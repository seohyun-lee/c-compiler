// symtable.c: 해시 심볼 테이블이 구현된 c 파일
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define SYM_TABLE_SIZE	100
#define HASH_TABLE_SIZE 100
#define STR_POOL_SIZE   1000
char separators[] = " ,;\t\n\r\n";
char str_pool[STR_POOL_SIZE];
int sym_table[SYM_TABLE_SIZE][2];

#define isLetter(x) ( ((x) >= 'a' && (x) <='z') || ((x) >= 'A' && (x) <= 'Z') || ((x) == '_')) 
#define isDigit(x) ( (x) >= '0' && (x) <= '9' )

typedef struct HTentry* HTpointer;
typedef struct HTentry {
    int index;  
    HTpointer next;  
}HTentry;

HTpointer HT[HASH_TABLE_SIZE];

// 제산법 해시 함수
int divisionMethod(char* key, int tableSize) {
    unsigned int hash_key = 0;
    int c;

    while ((c = *key++)) {
        hash_key += c;
    }
    return hash_key % tableSize;
}

// 제곱값 중간법 해시 함수
int midsquareMethod(char* key, int tableSize) {
    int squared;
    int midPart;
    unsigned int hash_key = 0;
    int c;

    while ((c = *key++)) {
        hash_key += c;
    }

    squared = hash_key * hash_key;
    midPart = squared / 100 % 1000; // 제곱값의 중간 부분 추출
    return midPart % tableSize;
}

// 폴딩법 해시 함수
int foldingMethod(char* key, int tableSize) {
    int fold = 0;
    unsigned int hash_key = 0;
    int c;

    while ((c = *key++)) {
        hash_key += c;
    }

    while (hash_key > 0) {
        fold += hash_key % 10000; // 4자리씩 나누어 더함
        hash_key /= 10000;
    }
    return fold % tableSize;
}

// 심볼 테이블 초기화 함수
void init_sym_table() {
    int i;
    for (i = 0; i < SYM_TABLE_SIZE; i++) {
        sym_table[i][0] = -1;
        sym_table[i][1] = -1;
    }
}

// 심볼 테이블 출력 함수
void print_sym_table() {
    int i;
    printf("\nSymbol Table\n");
    printf("ID\tIndex\tLength\tSymbol\n");
    for (i = 0; i < SYM_TABLE_SIZE; i++) {
        if (sym_table[i][0] != -1) {
            printf("%d\t%d\t%d\t%s\n", i+1, sym_table[i][0], sym_table[i][1], str_pool+sym_table[i][0]);
        }
    }
}

// 해시 테이블 Look up 함수
HTpointer lookup_hash_table(int id_index, int hscode) {
    HTpointer entry = HT[hscode];

    // 체이닝된 리스트를 탐색
    while (entry != NULL) {
        if (strcmp(str_pool + sym_table[entry->index - 1][0], str_pool + id_index) == 0) {
            return entry; // 찾은 항목 반환
        }
        entry = entry->next;
    }
    return NULL; // 항목을 찾지 못한 경우
}

// 해시 테이블에 추가 함수
int add_hash_table(int id_index, int hscode) {
    // 새 항목 생성 및 초기화
    HTpointer newEntry = (HTpointer)malloc(sizeof(HTentry));
    if (newEntry == NULL) {
        // printf("메모리 할당 실패\n");
        return -1; // 메모리 할당에 실패한 경우 -1을 리턴한다.
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
    return 0;
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

int index_start = 0;
int sym_table_index = 0;

// 해시 심볼 테이블 처리 함수
int process_sym_table(char* identifier) {
    int hash_value = 0;
    strcpy(str_pool + index_start, identifier);

    hash_value = divisionMethod(str_pool + index_start, HASH_TABLE_SIZE);
    
    HTpointer htp = lookup_hash_table(index_start, hash_value);
    if (htp == NULL) {
        if (sym_table_index >= SYM_TABLE_SIZE) { // 심볼테이블 overflow 방지 처리
            return -1;
        }
        sym_table[sym_table_index][0] = index_start;
        sym_table[sym_table_index++][1] = (int)strlen(str_pool + index_start);

        if (add_hash_table(sym_table_index, hash_value) < 0) {
            return -1;
        }
        // printf("%d\t%s\n", hash_value, str_pool + index_start); // 버퍼의 내용을 화면에 출력
        index_start += strlen(identifier);
        if (index_start >= STR_POOL_SIZE) { // string pool overflow 방지 처리
            return -1;
        }
        str_pool[index_start++] = '\0';
        return 0;
    }
    else {
        printf("%d\t%s (already exists)\n", hash_value, str_pool + index_start); // 버퍼의 내용을 화면에 출력
        return 1;
    }
}
