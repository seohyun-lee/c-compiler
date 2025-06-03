// symtable.c: 해시 심볼 테이블이 구현된 c 파일
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define SYM_TABLE_SIZE	100
#define HASH_TABLE_SIZE 100
#define STR_POOL_SIZE   1000
#define ATTR_POOL_SIZE  256

char separators[] = " ,;\t\n\r\n";
char str_pool[STR_POOL_SIZE];
int index_start = 0;

int sym_table[SYM_TABLE_SIZE][6];
/* sym_table[i][0] = pool 시작 인덱스
   sym_table[i][1] = identifier의 length
   sym_table[i][2] = 엔티티 종류 (1=function, 2=variable, 3=param)
   sym_table[i][3] = 엔티티 타입 (0=int,1=void,2=float,3=char)
   sym_table[i][4] = 변수인 경우 엔티티 scalar(0)/array(1) 또는 함수인 경우 파라미터 개수
   sym_table[i][5] = line number
*/
int sym_table_index = 0;

// 각 ID별로 최대 ATTR_POOL_SIZE자까지 속성 관련 문자열 저장 (최대 256자로 설정하였음)
char attr_pool[SYM_TABLE_SIZE][ATTR_POOL_SIZE];

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
        for (int j = 0; j < 6; j++)
            sym_table[i][j] = -1;
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
       5 이상 = 함수 파라미터 타입 순서대로 (0=int,1=void,2=float,3=char)
   - attr_value: attr_num 관련 값
*/
void update_sym_table(int id_index, int attr_num, int attr_value) {
    int i0 = id_index - 1;
    char buf[ATTR_POOL_SIZE];

    switch (attr_num) {
        case 0: sym_table[i0][3] = attr_value; break;   // 엔티티 타입
        case 1: break; // const를 출력하도록 확장할 수 있는 부분 (현재는 출력 x)
        case 2: sym_table[i0][4] = attr_value; break;   // scalar(0)/array(1)
        case 3: sym_table[i0][4] = attr_value; break;   // 함수인 경우 파라미터 개수로 활용
        case 4: sym_table[i0][2] = attr_value; break;   // 엔티티 종류
    }
}

// 함수가 파라미터 정보를 얻기 위한 심볼 테이블 업데이트 함수
void update_sym_table_param(int id_index, int param_count, int param_types[], int param_indexes[]) {
    int i0 = id_index - 1;
    char buf[ATTR_POOL_SIZE] = "";

    for (int i = 0; i < param_count; i++) {
        char* type_str[] = { "int", "void", "float", "char" };
        int sym_index = param_indexes[i];
        int is_array = sym_table[sym_index - 1][4];
        char* param_name = str_pool + sym_table[sym_index - 1][0];

        char param_buf[ATTR_POOL_SIZE];
        sprintf(param_buf, "%s%s %s", (i ? "," : ""), type_str[param_types[i]], param_name);
        if (is_array) strcat(param_buf, "[]");
        strcat(buf, param_buf);
    }
    strcpy(attr_pool[i0], buf);
}

// 심볼 테이블 출력 함수
void print_sym_table(void) {
    printf("\nSymbol Table\n");
    printf("ID\tIndex\tLength\tLine\tSymbol\tAttributes\n");

    for (int i = 0; i < sym_table_index; i++) {
        char* name = str_pool + sym_table[i][0];
        int kind = sym_table[i][2];
        int type = sym_table[i][3];
        int line = sym_table[i][5];

        char* type_str[] = { "int", "void", "float", "char" };
        char attr_buf[ATTR_POOL_SIZE];

        if (kind == 1) { // 함수
            char param_info[ATTR_POOL_SIZE];
            strcpy(param_info, attr_pool[i]);
            int param_cnt = sym_table[i][4];
            printf("%d\t%d\t%d\t%d\t%s\tFunction (return type: %s, # of param: %d, params:%s)\n",
                i + 1, sym_table[i][0], sym_table[i][1], line, name, type_str[type], param_cnt, param_info);
        }
        else if (kind == 2) { // 일반 변수
            int is_array = sym_table[i][4];
            sprintf(attr_buf, "%s %s variable", type_str[type], is_array ? "array" : "scalar");
            printf("%d\t%d\t%d\t%d\t%s\t%s\n",
                i + 1, sym_table[i][0], sym_table[i][1], line, name, attr_buf);
        }
        else if (kind == 3) { // 함수 파라미터
            int is_array = sym_table[i][4];
            sprintf(attr_buf, "%s %s variable", type_str[type], is_array ? "array" : "scalar");
            printf("%d\t%d\t%d\t%d\t%s\tFunction Parameter(%s)\n",
                i + 1, sym_table[i][0], sym_table[i][1], line, name, attr_buf);
        }
        else { // unknown
            printf("%d\t%d\t%d\t%d\t%s\tUnknown\n", i + 1, sym_table[i][0], sym_table[i][1], line, name);
        }
    }
}

// 해시 테이블 Look up 함수
HTpointer lookup_hash_table(int id_index, int hscode) {
    HTpointer entry = HT[hscode];

    // 체이닝된 리스트를 탐색
    while (entry != NULL) {
        if (strcmp(str_pool + sym_table[entry->index-1][0], str_pool + id_index) == 0) {
            return entry; // 찾은 항목 반환
        }
        entry = entry->next;
    }
    return NULL; // 항목을 찾지 못한 경우 NULL 반환
}

// 해시 테이블 추가 함수
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

// 해시 테이블 출력 함수
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

// 해시 심볼 테이블 처리 함수
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
        sym_table[sym_table_index][5] = line_num; // 줄 번호
        attr_pool[sym_table_index][0] = '\0';   // 속성 문자열 초기화
        sym_table_index++;

        add_hash_table(sym_table_index, hash_value);
        result = sym_table_index;
    }
    else {
        result = htp->index;
        return result;
    }

    index_start += strlen(identifier);
    str_pool[index_start++] = '\0';
 
    return result;
}
