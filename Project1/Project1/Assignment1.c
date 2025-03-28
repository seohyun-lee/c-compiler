#include <stdio.h>                  // 입출력 함수 헤더
#include <string.h>                 // 문자열 처리 함수 사용을 위한 헤더
#include <stdlib.h>                 // 동적 메모리 할당 함수 헤더

#define SYM_TABLE_SIZE  100         // 심볼 테이블의 크기
#define STR_POOL_SIZE   500         // string pool의 크기
#define HASH_TABLE_SIZE 11          // 해시 테이블의 크기

typedef struct HTentry* HTpointer;  // 해시 테이블 엔트리 구조체의 포인터
typedef struct HTentry {            // 해시 테이블 엔트리 구조체
    int index;                      // 심볼 테이블의 ID를 저장
    HTpointer next;                 // 체이닝을 위한 포인터
} HTentry;

char separators[] = " ,;\t\n\r\n";      // 구분자
int sym_table[SYM_TABLE_SIZE][3];       // 심볼 테이블: [ID, str_pool 인덱스, 길이]
char str_pool[STR_POOL_SIZE];           // string pool
int sym_index;                          // 심볼 테이블 현재 인덱스
HTpointer HT[HASH_TABLE_SIZE];          // 해시 테이블

// 문자열의 아스키 합을 기반으로 해시 키를 계산하는 함수
int calc_key(char* str) {
    int key = 0;
    for (int i = 0; i < strlen(str); i++) {
        key += (int)*(str + i); // str+i 주소에 있는 값을 int로 변경 후 key에 더함
    }
    return key;
}

// 제산법 해시 함수
int division_method(int key) {
    return key % HASH_TABLE_SIZE;
}

// 해시 테이블을 통해 심볼테이블에 식별자가 존재하는지 검사하는 함수
HTpointer lookup_hash_table(int index_start, int length, int hscode) {
    HTpointer entry = HT[hscode];

    while (entry != NULL) {
        // 해시테이블 엔트리의 index는 sym_table의 ID로, ID는 실제 배열 인덱스 +1한 값
        // sym_table에서 ID-1를 인덱스로 str_pool 시작 인덱스를 찾고 문자열을 읽어, 현재 str_pool이 읽은 식별자 문자열과 비교
        if (strncmp(str_pool + sym_table[entry->index - 1][1], str_pool + index_start, length) == 0
            && sym_table[entry->index - 1][2] == length) {
            return entry;
        }
        entry = entry->next;
    }
    return NULL;
}

// 해시 테이블에 삽입하는 함수
void add_hash_table(int index, int hscode) {
    HTpointer newEntry = (HTpointer)malloc(sizeof(HTentry)); // 새 엔트리 할당    
    if (newEntry == NULL) {         // 널 가드
        printf("메모리 할당 실패\n");
        exit(1);
    }
    newEntry->index = index;
    newEntry->next = NULL;          // 연결 리스트의 끝임을 나타냄

    if (HT[hscode] == NULL) {       // 해시 테이블에 해당 해시 코드로 엔트리가 존재하는지 확인
        HT[hscode] = newEntry;      // 없으면 바로 추가
    }
    else {                            // 이미 있다면 체이닝으로 새 항목을 리스트 맨 앞에 추가
        newEntry->next = HT[hscode];  // 새 엔트리의 next는 기존 첫 번째 엔트리
        HT[hscode] = newEntry;        // 해시 테이블 hscode번째 원소가 가리키는 위치를 새 엔트리로 업데이트
    }
}

// 식별자에 대해 해시 테이블을 확인하고, 이미 존재하던 식별자가 아니라면 해시테이블 및 심볼 테이블에 삽입하는 함수
int insert_symbol(const char* str, int index_start, int length) {
    int hash_value = division_method(calc_key(str));

    HTpointer htp = lookup_hash_table(index_start, length, hash_value);
    if (htp == NULL) { // 해시 테이블에 없는 경우
        // 오버플로우 시 에러 처리
        if (sym_index >= SYM_TABLE_SIZE) {
            printf("Error - Symbol table overflow\n");
            return -1;
        }
        printf("%d\t%s\n", hash_value, str);

        // 해시 테이블에 추가
        add_hash_table(sym_index + 1, hash_value);

        // 심볼 테이블에 추가
        sym_table[sym_index][0] = sym_index + 1;    // ID
        sym_table[sym_index][1] = index_start;      // string_pool 시작인덱스
        sym_table[sym_index++][2] = length;         // 길이
        return 0;
    }
    else { // 해시 테이블에 이미 있는 경우 정보 출력 후 저장하지 않음
        printf("%d\t%s (already exists)\n", hash_value, str);
        return -1;
    }
}

// 심볼 테이블 출력 함수
void print_sym_table() {
    printf("\nSymbol Table\nID\tIndex\tLength\tSymbol\n");
    for (int i = 0; i < sym_index; i++) {
        printf("%d\t%d\t%d\t%s\n", sym_table[i][0], sym_table[i][1], sym_table[i][2], str_pool + sym_table[i][1]);
    }
    return;
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

// 동적 할당된 해시 테이블 메모리 해제
void free_memory_allocations() {
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        HTpointer entry = HT[i];
        while (entry != NULL) {
            HTpointer tmp = entry;
            entry = entry->next;
            free(tmp);
        }
    }
}


int main() {
    FILE* fp;
    int result;
    int c;                  // 읽은 문자를 저장할 변수
    int index_start = 0;    // 시작 인덱스
    int index_next = 0;     // 다음 인덱스
    int err_flag = 0; // 0: 정상, -1: 불법 문자 포함, -2: 숫자로 시작, -3: 15자 초과

    result = fopen_s(&fp, "example.txt", "r"); // "example.txt" 파일을 읽기 모드로 열기
    if (result != 0) {
        printf("파일 열기 실패(%d)\n", result);
        return -1;
    }

    do {                    // 파일 끝까지 읽음
        c = fgetc(fp);      // fp에서 한 문자를 읽어옴

        // string pool 오버플로우 방지
        if (index_next >= STR_POOL_SIZE) {
            fprintf(stderr, "Error - String Pool overflow\n");
            break;
        }

        if (c == EOF || (strchr(separators, c) != NULL)) { // separator가 나왔거나 끝
            if (index_next == index_start) { // 식별자 길이가 없다면 무시 (연속으로 구분자가 두 번 나온 경우)
                continue;
            }

            str_pool[index_next++] = '\0'; // str_pool에 널 문자를 넣고 index_next를 증가

            // 식별자 길이가 15를 초과하는 경우 에러
            int length = index_next - index_start - 1;
            if (length > 15) {
                err_flag = -3;
            }

            // err_flag에 따라서 심볼테이블에 삽입하거나, string pool을 처리함 (err_flag가 0인 경우가 정상)
            if (err_flag == 0) {
                int res = insert_symbol(str_pool + index_start, index_start, length); // 삽입 및 출력 처리
                if (res == -1) {
                    index_next = index_start; // string pool 삭제 롤백
                }
                else {
                    index_start = index_next; // index_start를 index_next자리로 옮김
                }
            }
            else { // 에러
                switch (err_flag) {
                    case -1:
                        printf("Error - Illegal identifier ");
                        break;
                    case -2:
                        printf("Error - Start with digit ");
                        break;
                    case -3:
                        printf("Error - Too long identifier ");
                        break;
                    default:
                        printf("Error - Unknown issue ");
                        break;
                }
                printf("(%s)\n", str_pool + index_start);

                index_next = index_start; // string pool 상태 롤백
                err_flag = 0;             // 정상 상태로 복구
            }
        }
        else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_') { // 알파벳이나 언더바 문자인 경우 정상
            str_pool[index_next++] = (char)c;
        }
        else if (c >= '0' && c <= '9') { // 숫자 문자인 경우: 첫 자리에 숫자가 오는 경우 에러, err_flag를 -2로 설정. 그외 정상
            if (index_next == 0 || str_pool[index_next - 1] == '\0') {
                err_flag = -2;
            }
            str_pool[index_next++] = (char)c;
        }
        else { // 식별자로 유효하지 않은 문자인 경우 에러, err_flag를 -1로 설정
            err_flag = -1;
            str_pool[index_next++] = (char)c;
        }
    } while (c != EOF);

    print_sym_table();          // 심볼 테이블 출력
    print_hash_table();         // 해시 테이블 출력
    free_memory_allocations();  // 메모리 할당 해제

    fclose(fp);                 // 파일 닫기
    return 0;
}