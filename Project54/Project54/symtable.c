#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define SYM_TABLE_SIZE	100
#define HASH_TABLE_SIZE 100
#define STR_POOL_SIZE   1000
#define ATTR_POOL_SIZE  5000

char separators[] = " ,;\t\n\r\n";
char str_pool[STR_POOL_SIZE];
int index_start = 0;

int sym_table[SYM_TABLE_SIZE][4];
/* sym_table[i][0] = pool 시작 인덱스
   sym_table[i][1] = identifier의 length
   sym_table[i][2] = 엔티티 종류 (1=function, 2=variable, 3=param)
   sym_table[i][3] = line number
*/
int sym_table_index = 0;

// 각 ID별로 최대 256자까지 속성 문자열 저장 (최대 256자로 설정하였음)
char attr_pool[SYM_TABLE_SIZE][256];

#define isLetter(x) ( ((x) >= 'a' && (x) <='z') || ((x) >= 'A' && (x) <= 'Z') || ((x) == '_')) 
#define isDigit(x) ( (x) >= '0' && (x) <= '9' )

typedef struct HTentry* HTpointer;
typedef struct HTentry {
    int index;  
    HTpointer next;  
}HTentry;

HTpointer HT[HASH_TABLE_SIZE];

// 제산법 해시 함수
int division_method(char* key, int tableSize) {
    unsigned int hash_key = 0;
    int c;

    while (c = *key++) {
        hash_key += c;
    }
    return hash_key % tableSize;
}

// 제곱값 중간법 해시 함수
int midsquare_method(char* key, int tableSize) {
    int squared;
    int midPart;
    unsigned int hash_key = 0;
    int c;

    while (c = *key++) {
        hash_key += c;
    }

    squared = hash_key * hash_key;
    midPart = squared / 100 % 1000; // 제곱값의 중간 부분 추출
    return midPart % tableSize;
}

// 폴딩법 해시 함수
int folding_method(char* key, int tableSize) {
    int fold = 0;
    unsigned int hash_key = 0;
    int c;

    while (c = *key++) {
        hash_key += c;
    }

    while (hash_key > 0) {
        fold += hash_key % 10000; // 4자리씩 나누어 더함
        hash_key /= 10000;
    }
    return fold % tableSize;
}

// 심볼 테이블 초기화
void init_sym_table() {
    int i;
    for (i = 0; i < SYM_TABLE_SIZE; i++) {
        sym_table[i][0] = -1;
        sym_table[i][1] = -1;
        sym_table[i][2] = 0;   // 엔티티 종류 미정
        sym_table[i][3] = -1;
    }
}

// 심볼 테이블 업데이트 함수
/* update_sym_table:
   - id_index: 1-based 심볼 인덱스
   - attr_num: 속성 종류
       0 = 기본 타입           (0=int,1=void,2=float,3=char)
       1 = const 여부          (0=non-const,1=const)
       2 = 변수의 배열 여부    (0=scalar,1=array)
       3 = 함수의 파라미터 개수
       4 = 엔티티 종류         (1=function, 2=variable, 3=param)
       5 이상 = 함수 파라미터 타입 순서대로 (0=int,1=void,2=float,3=char 등)
   - attr_value: 해당 속성의 정수 코드
*/
void update_sym_table(int id_index, int attr_num, int attr_value) {
    int i0 = id_index - 1;
    char buf[64];

    switch (attr_num) {
    case 0:
        /* 기본 타입을 attr_pool[i0]에 덮어쓰기 */
        if (attr_value == 0) strcpy(buf, "int");
        else if (attr_value == 1) strcpy(buf, "void");
        else if (attr_value == 2) strcpy(buf, "float");
        else if (attr_value == 3) strcpy(buf, "char");
        snprintf(attr_pool[i0], 256, "%s", buf);
        break;

    case 1:
        /* const 여부를 attr_pool[i0] 앞에 삽입 (const int) */
        if (attr_value != 1) break;  /* non-const이면 아무것도 안함 */

        if (attr_pool[i0][0] == '\0') {
            /* 타입이 아직 안 저장된 경우, 빈 상태이므로 "const "만 저장 */
            strcpy(attr_pool[i0], "const ");
        }
        else {
            /* 기존 "<type>" 앞에 "const " 삽입 */
            char temp[256];
            strcpy(temp, attr_pool[i0]);
            snprintf(attr_pool[i0], 256, "const %s", temp);
        }
        break;

    case 2:
        /* 배열 여부: attr_pool[i0] 뒤에 " scalar" 또는 " array" 덧붙임 */
        if (attr_pool[i0][0] == '\0') break;
        if (attr_value == 0)       sprintf(buf, " scalar");
        else                       sprintf(buf, " array");
        strncat(attr_pool[i0], buf, 255 - strlen(attr_pool[i0]));
        break;

    case 3:
        /* 함수 파라미터 개수: attr_pool[i0] 뒤에 숫자만 붙임 */
        if (attr_pool[i0][0] == '\0') break;
        sprintf(buf, "%d", attr_value);
        strncat(attr_pool[i0], buf, 255 - strlen(attr_pool[i0]));
        break;

    case 4:
        /* 엔티티 종류 지정 */
        if (attr_value != 0)
           sym_table[i0][2] = attr_value;
        break;
    }
}


/*
  id_index    : 1-based 함수 엔트리 번호 (sym_table 인덱스로 들어갈 때 -1)
  param_count : 파라미터 개수
  param_type[]: 각 파라미터 타입 코드(0=int, 1=void, 2=float, 3=char)
  param_ids[] : 각 파라미터의 “심볼 테이블 엔트리 번호”(1-based)
*/
void update_sym_table_param(int id_index, int param_count,
    int param_type[], int param_ids[])
{
    int i0 = id_index - 1;
    char buf[256];
    const char* type_str;

    /* 1) 이 엔티티가 함수(kind=1)가 아니면 무시 */
    if (sym_table[i0][2] != 1) {
        return;
    }

    /* 2) param_count 만큼 반복하면서, attr_pool[i0] 뒤에 ", <type> <sym_index>" 붙이기 */
    for (int i = 0; i < param_count; i++) {
        /* 2-1) param_type[i] → 문자열로 */
        switch (param_type[i]) {
        case 0: type_str = "int";   break;
        case 1: type_str = "void";  break;
        case 2: type_str = "float"; break;
        case 3: type_str = "char";  break;
        default: type_str = "unknown"; break;
        }

        /* 2-2) param_ids[i] 자체가 “심볼 테이블의 엔트리 번호(1-based)”이므로,
                 여기서는 그냥 숫자로 처리한다. */
        int sym_index = param_ids[i];  /* 1-based */

        /* 2-3) ", <type> <sym_index>" 형식으로 buf에 포맷 */
        snprintf(buf, sizeof(buf), ", %s %d", type_str, sym_index);

        /* 2-4) attr_pool[i0] 뒤에 덧붙이기 (버퍼 오버플로우 방지) */
        strncat(attr_pool[i0], buf, 255 - strlen(attr_pool[i0]));
    }
}


void print_sym_table(void) {
    printf("\nSymbol Table\n");
    printf("ID\tIndex\tLength\tLineNumber\tSymbol\t\tAttributes\n");

    for (int i = 0; i < sym_table_index; i++) {
        int   i0 = i;
        char* name = str_pool + sym_table[i0][0];
        int   kind = sym_table[i0][2];
        char* attrs = attr_pool[i0];

        if (kind == 1) {
            /* === 함수 처리 ===
               attrs 예시: "int3, int 2, char 4"
               → 리턴타입=int, 파라미터 개수=3, param_idxs=" int 2, char 4"
            */
            if (attrs[0] == '\0') {
                // attrs가 비어 있으면, Unknown 상태로 기본 문자열 출력
                printf(
                    "%d\t%d\t%d\t%d\t%s\tFunction (return type: Unknown, # of param: -1, params:)\n",
                    i + 1,
                    sym_table[i0][0],
                    sym_table[i0][1],
                    sym_table[i0][3],
                    name
                );
                continue;
            }
            char buffer[256];
            strcpy(buffer, attrs);

            // 1) buffer에서 숫자(파라미터 개수)가 처음 나오는 위치 찾기
            char* p = buffer;
            while (*p && !isdigit((unsigned char)*p)) {
                p++;
            }

            // 리턴 타입만 담을 곳
            char return_str[256];
            // 파라미터 개수
            int param_cnt = 0;
            // 파라미터 “타입+인덱스” 부분: 예) " int 2, char 4"
            char param_idxs[256] = "";

            if (*p) {
                // 숫자가 있으면, “파라미터 개수” 추출
                int prefix_len = p - buffer;
                strncpy(return_str, buffer, prefix_len);
                return_str[prefix_len] = '\0';

                param_cnt = atoi(p);

                // 숫자 구간 지나기
                while (*p && isdigit((unsigned char)*p)) {
                    p++;
                }
                // p는 숫자 끝난 다음(콤마 또는 공백)
                if (*p == ',') {
                    p++;
                    // param_idxs에 “ int 2, char 4” 복사
                    strcpy(param_idxs, p);
                }
            }
            else {
                // 숫자가 전혀 없는 경우 (파라미터 없음)
                strcpy(return_str, buffer);
                param_cnt = 0;
            }

            if (param_cnt == 0) {
                printf("%d\t%d\t%d\t%d\t\t%s\t\tFunction (return type: %s, # of param: 0, params:)\n",
                    i + 1,
                    sym_table[i0][0],
                    sym_table[i0][1],
                    sym_table[i0][3],
                    name,
                    return_str);
            }
            else {
                // param_idxs = " int 2, char 4" 같은 형태
                // ╌ 각 파라미터마다: "<space><type><space><index>"
                char* q = param_idxs;
                // 출력할 파라미터 리스트를 저장할 버퍼
                char param_list_out[256] = "";
                int first = 1;

                while (*q) {
                    // 1) 콤마나 공백 건너뛰기
                    while (*q && (isspace((unsigned char)*q) || *q == ',')) {
                        q++;
                    }
                    if (!*q) break;

                    // 2) type 문자열 추출 (알파벳 연속 부분)
                    char type_buf[64];
                    int tlen = 0;
                    while (*q && isalpha((unsigned char)*q)) {
                        if (tlen < (int)sizeof(type_buf) - 1) {
                            type_buf[tlen++] = *q;
                        }
                        q++;
                    }
                    type_buf[tlen] = '\0';

                    // 3) 공백 건너뛰기
                    while (*q && isspace((unsigned char)*q)) {
                        q++;
                    }
                    if (!*q) break;

                    // 4) 인덱스(숫자) 추출
                    int sym_index = atoi(q);
                    // 숫자 끝까지 이동
                    while (*q && isdigit((unsigned char)*q)) {
                        q++;
                    }

                    // 5) 인덱스를 1-based → 0-based 로 변경해서 이름 찾기
                    char* pname = "";
                    if (sym_index >= 1 && sym_index <= sym_table_index) {
                        pname = str_pool + sym_table[sym_index - 1][0];
                    }

                    // 6) “"<type> <name>"” 형태로 붙이기
                    if (!first) {
                        strcat(param_list_out, ", ");
                    }
                    first = 0;
                    strcat(param_list_out, type_buf);
                    strcat(param_list_out, " ");
                    strcat(param_list_out, pname);
                }

                // 최종 출력 (리턴타입, 파라미터 개수, params: <type name, ...>)
                printf("%d\t%d\t%d\t%d\t\t%s\t\tFunction (return type: %s, # of param: %d, params: %s)\n",
                    i + 1,
                    sym_table[i0][0],
                    sym_table[i0][1],
                    sym_table[i0][3],
                    name,
                    return_str,
                    param_cnt,
                    param_list_out);
            }
        }
        else if (kind == 2) {
            /* 변수 처리 */
            printf("%d\t%d\t%d\t%d\t\t%s\t\t%s variable\n",
                i + 1,
                sym_table[i0][0],
                sym_table[i0][1],
                sym_table[i0][3],
                name,
                attrs);
        }
        else if (kind == 3) {
            /* 파라미터 처리 */
            printf("%d\t%d\t%d\t%d\t\t%s\t\tFunction Parameter(%s variable)\n",
                i + 1,
                sym_table[i0][0],
                sym_table[i0][1],
                sym_table[i0][3],
                name,
                attrs);
        }
        else {
            /* 기타 Unknown */
            printf("%d\t%d\t%d\t%d\t\t%s\t\tUnknown\n",
                i + 1,
                sym_table[i0][0],
                sym_table[i0][1],
                sym_table[i0][3],
                name);
        }
    }
}



HTpointer lookup_hash_table(int id_index, int hscode) {
    HTpointer entry = HT[hscode];

    // 체이닝된 리스트를 탐색
    while (entry != NULL) {
        if (strcmp(str_pool + sym_table[entry->index-1][0], str_pool + id_index) == 0) {
            return entry; // 찾은 항목 반환
        }
        entry = entry->next;
    }
    return NULL; // 항목을 찾지 못한 경우
}

void add_hash_table(int id_index, int hscode) {
    // 새 항목 생성 및 초기화
    HTpointer newEntry = (HTpointer)malloc(sizeof(HTentry));
    if (newEntry == NULL) {
        printf("메모리 할당 실패\n");
        exit(1);
    }
    newEntry->index = id_index;
    newEntry->next = NULL;

    if (HT[hscode] == NULL) {
        // 첫 번째 항목으로 추가
        HT[hscode] = newEntry;
    }
    else {
        // 이미 항목이 있으면, 리스트의 맨 앞에 추가
        newEntry->next = HT[hscode];
        HT[hscode] = newEntry;
    }
}

void print_hash_table() {
    printf("\nHash Table:\n");
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        HTpointer entry = HT[i];
        if (entry != NULL) {
            printf("[%d]: ", i);
            while (entry != NULL) {
                printf("%d -> ", entry->index);
                entry = entry->next;
            }
            printf("NULL\n");
        }
    }
}

int process_sym_table(char* identifier, int line_num) {
    int hash_value = 0;
    bool flag_undefined = false;
    int result;
 
    strcpy(str_pool + index_start, identifier);

    hash_value = division_method(str_pool + index_start, HASH_TABLE_SIZE);
    
    HTpointer htp = lookup_hash_table(index_start, hash_value);
    if (htp == NULL) {
        sym_table[sym_table_index][0] = index_start;
        sym_table[sym_table_index][1] = (int)strlen(str_pool + index_start);
        sym_table[sym_table_index][2] = 0;      // 엔티티 종류 초기값
        sym_table[sym_table_index][3] = line_num;
        attr_pool[sym_table_index][0] = '\0';   // 속성 문자열 초기화
        sym_table_index++;

        add_hash_table(sym_table_index, hash_value);
        //printf("%d\t%s\n", hash_value, str_pool + index_start); // 버퍼의 내용을 화면에 출력
        result = sym_table_index;
    }
    else {
        result = htp->index;
        //printf("%d\t%s (already exists)\n", hash_value, str_pool + index_start); // 버퍼의 내용을 화면에 출력
        return result;
    }

    index_start += strlen(identifier);
    str_pool[index_start++] = '\0';
 
    return result;
}
