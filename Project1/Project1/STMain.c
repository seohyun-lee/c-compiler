#include <stdio.h>          // 입출력 헤더
#include <string.h>         // 문자열 관련 함수 사용을 위한 헤더
#include <stdbool.h>        // bool, true, false 사용을 위한 헤더
#include <stdlib.h>         // malloc 할당을 위한 헤더

#define SYM_TABLE_SIZE  100         // 심볼 테이블 사이즈 정의
#define STR_POOL_SIZE   500         // string pool 사이즈 정의
#define HASH_TABLE_SIZE 23          // 해시 테이블 사이즈 정의

typedef struct HTentry* HTpointer;  // 해시 테이블 엔트리 구조체의 포인터
typedef struct HTentry {            // 해시 테이블 엔트리 구조체
    int index;
    HTpointer next;
} HTentry;

char separators[] = " ,;\t\n\r\n";  // 구분자
int sym_table[SYM_TABLE_SIZE][3];   // 심볼 테이블
char str_pool[STR_POOL_SIZE];       // string pool
int sym_id;                         // 심볼 테이블 ID
HTpointer HT[HASH_TABLE_SIZE];      // 해시 테이블


/* add_hash_table()
*
* 입력:
* index - 현재 string pool 위치
* hscode - 현재 입력된 symbol의 hash code
*
* 출력: 없음
*/
void add_hash_table(int index, int hscode) {
    // 새 항목 생성 및 초기화
    HTpointer newEntry = (HTpointer)malloc(sizeof(HTentry));
    if (newEntry == NULL) {
        printf("메모리 할당 실패\n");
        exit(1);
    }
    newEntry->index = index;    // 해당 엔트리의 인덱스를 설정
    newEntry->next = NULL;      // 연결 리스트의 끝임을 나타냄

    if (HT[hscode] == NULL) {   // 해시 테이블에 해당 해시 코드로 엔트리가 존재하는지 확인
        HT[hscode] = newEntry;  // 없으면 바로 추가
    }
    else {
        // 있ew[[면 체이닝 방식으로 새 항목을 리스트 맨 앞에 추가
        newEntry->next = HT[hscode];  // 새 항목의 next는 기존 첫 번째 항목
        HT[hscode] = newEntry;        // 해시 테이블의 해당 위치를 새 항목으로 업데이트

        // 이미 항목이 엔트리가, 리스트의 맨 앞에 추가
        newEntry->next = HT[hscode];
        HT[hscode] = newEntry;
    }
}
// 해시 테이블에 삽입
void add_hash_table(int index, int hscode) { // void는 어떤 값이든 반환할수가 있다
    HTpointer newEntry = (HTpointer)malloc(sizeof(HTentry)); // 구조체만큼 할당받고 HTpointer형태를 가진다
    if (newEntry == NULL) { // 널 체크 필수
        printf("메모리 할당 실패");
        exit(1);
    }
    newEntry->index = index;
    newEntry->next = NULL;

    if (HT[hscode] == NULL) {
        HT[hscode] = newEntry;
    }
    else {
        newEntry->next = HT[hscode];
        HT[hscode] = newEntry;
    }
}

int insert_symbol(const char* str, int index_start, int length) {
    int key = calc_key(str_pool + index_start);
    int hash_value = divisionMethod(key, HASH_TABLE_SIZE);

    HTpointer htp = lookup_hash_table(key, hash_value);
    if (htp == NULL) {
        add_hash_table(key, hash_value);
        printf("%d\t%d)\n", hash_value, key);
        return 0;
    }
    else {
        printf("%d\t%d (already exists)\n", hash_value, key);
        return -1; // -1이 리턴되는 경우 string pool에서 빼야
    }
    //HTpointer node = HT[hash];

    //while (node != NULL) {
    //    int idx = sym_table[node->sym_id][1];
    //    int l = sym_table[node->sym_id][2];

    //    if (l == length && strncmp(str_pool + idx, str, length) == 0) {
    //        // 중복 식별자 → 기존 ID 출력
    //        printf("Already exists: ID=%d, Symbol=", node->sym_id);
    //        for (int i = 0; i < l; i++) putchar(str_pool[idx + i]);
    //        putchar('\n');
    //        return node->sym_id;
    //    }
    //    node = node->next;
    //}

    // 새 식별자 추가
    if (sym_id >= SYM_TABLE_SIZE) {
        fprintf(stderr, "Error: Symbol table overflow\n");
        return -1;
    }

    printf("%d\t%.*s\n", hash, length, str);

    sym_table[sym_id][0] = sym_id;
    sym_table[sym_id][1] = index_start;
    sym_table[sym_id][2] = length;

    SymbolNode* new_node = (SymbolNode*)malloc(sizeof(SymbolNode));
    new_node->sym_id = sym_id;
    new_node->next = hash_bucket[hash];
    hash_bucket[hash] = new_node;

    return 0;
}


int calc_key(char* str)
{
    int len = strlen(str);
    int key = 0;
    for (int i = 0; i < len; i++) {
        key += (int)*(str + i); // str+i 주소에 있는 값을 int로 변경
    }
    return key;
}

int divisionMethod(int key, int tableSize) {
    return key % tableSize;
}

// lookup_hash_table을 대신 봄 이거 삭제
//int find_symbol(const char* str, int len) {
//    for (int i = 0; i < sym_id; i++) {
//        int idx = sym_table[i][1];
//        int l = sym_table[i][2];
//        if (l == len && strncmp(str_pool + idx, str, len) == 0) {
//            return i;  // 이미 존재하는 심볼의 ID 반환
//        }
//    }
//    return -1;  // 없음
//}

// string pool
//심볼테이블 인덱스값으로 문자열 값 읽어와 인덱스 스트링풀 문자열 비교한다거나 해서 해라??
HTpointer lookup_hash_table(int index, int hscode) {
    HTpointer entry = HT[hscode];

    while (entry != NULL) {
        if (strncmp(sym_table[entry->index], sym_table[index])) { // 뭐 이런식 (strncmp?? strcmp??)
            return entry;
        }
        entry = entry->next;
    }
    return NULL;
}


// 심볼 테이블 출력 (수정해야!!!!!!!!1
void print_sym_table(void)
{
    printf("\nSymbol Table\nIndex\tLength\tSymbol\n"); // ID였다면 i+1
    for (int i = 0; i < sym_id; i++) {
        int index = sym_table[i][1];
        int length = sym_table[i][2];

        printf("%d\t%d\t", i, length);
        for (int j = 0; j < length; j++) {
            putchar(str_pool[index + j]);
        }
        putchar('\n');
    }
    return;
}

// 해시 테이블 출력
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

void free_memory_allocations()
{
    // 해시 테이블 메모리 할당 해제 
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        HTpointer node = HT[i];
        while (node != NULL) {
            HTpointer tmp = node;
            node = node->next;
            free(tmp);
        }
    }

}

int main() {
    FILE* fp;
    int result; // 각종 함수 실행 결과를 저장
    int c; // 읽은 문자를 저장할 변수
    int index_start = 0;
    int index_next = 0;

    result = fopen_s(&fp, "example.txt", "r"); // "example.txt" 파일을 읽기 모드로 열기
    if (result != 0) {
        printf("파일 열기 실패(%d)\n", result);
        return -1;
    }

    int err_flag = FALSE; // identifier가 숫자로 시작하면 안됨. 특수문자같은것도 들어가면 안됨. 길이도 넘어가면 안됨. 그런것 발생시 에러플래그를 TRUE로.
    do { // 파일 끝까지 문자 읽기
        c = fgetc(fp);

        if (index_next >= STR_POOL_SIZE) { // 현재까지 입력한 식별자라는게, 지금 입력중인 식별자는??
            fprintf(stderr, "Error - String Pool overflow\n");
            break;
        }

        if ((strchr(separators, c) != NULL) || c == EOF) { // separator가 나왔거나 끝
            str_pool[index_next++] = '\0'; // 이 줄 다음에 index_next가 증가

            if (index_next - index_start - 1 > 15) {
                err_flag = TRUE;
            }

            if (err_flag != TRUE) {
                int id = find_symbol(str_pool + index_start, index_next - index_start - 1);
                if (id != -1) {
                    // 이미 존재 → 기존 정보 출력
                    printf("Already exists: ID=%d, Symbol=", id);
                    for (int i = 0; i < sym_table[id][2]; i++) {
                        putchar(str_pool[sym_table[id][1] + i]);
                    }
                    putchar('\n');
                }
                else {
                    int length = index_next - index_start - 1;
                    if (insert_symbol(str_pool + index_start, index_start, length) != -1)
                        sym_id++;
                }
                index_start = index_next;
            }
            else {
                printf("Error - Invalid identifier (%s)\n", str_pool + index_start);
                index_next = index_start;
                err_flag = FALSE;
            }
        }
        else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_') // 사전에 정의한 문자
        {
            str_pool[index_next++] = (char)c;
        }
        else if (c >= '0' && c <= '9') // 사전에 정의한 문자
        {
            if (index_next == 0 || str_pool[index_next - 1] == '\0')
                err_flag = TRUE;
            str_pool[index_next++] = (char)c;
        }
        else
        {
            str_pool[index_next++] = (char)c; // 저장은 해주지만 에러플래그를 true로->마지막에 처리
            err_flag = TRUE;
        }
    } while (c != EOF);

    print_sym_table();
    print_hash_table();

    fclose(fp); // 파일 닫기
    free_memory_allocations();
    return 0;
}