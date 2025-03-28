#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define HASH_TABLE_SIZE 20

typedef struct HTentry* HTpointer;
typedef struct HTentry {
    int index;
    HTpointer next;
}HTentry;

HTpointer HT[HASH_TABLE_SIZE];

/* lookup_hash_table()
*
* 입력:
* index - 현재 string pool 위치
* hscode - 현재 입력된 symbol의 hash code
*
* 출력:
* HTpointer - 찾고자 하는 symbol이 이미 존재할 경우 해당 symbol이 저장된 HTpointer 반환
*             없을 경우는 NULL 반환
*/
HTpointer lookup_hash_table(int index, int hscode) {
    HTpointer entry = HT[hscode];

    // 체이닝된 리스트를 탐색
    while (entry != NULL) {
        /* 과제를 위해서는 탐색하고자 하는 값과 비교하는 코드로 변경되어야 함
        * 예: 심볼테이블에 저장된 ID/index/length를 이용하여 현재 string pool의 symbol과 같은지 비교
        */
        if (entry->index == index) {
            return entry; // 찾은 항목 반환
        }
        entry = entry->next;
    }
    return NULL; // 항목을 찾지 못한 경우
}

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
    newEntry->index = index;
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

/* print_hash_table()
*
* 입력: 없음
* 출력: 없음
*/
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

int divisionMethod(int key, int tableSize) {
    return key % tableSize;
}

int main() {
    int inputs[] = { 17, 18, 23, 25, 18, 38, 39, 22 };
    int size = sizeof(inputs) / sizeof(int);

    for (int i = 0; i < size; i++) {
        int hash_value = divisionMethod(inputs[i], HASH_TABLE_SIZE);
        HTpointer htp = lookup_hash_table(inputs[i], hash_value);
        if (htp == NULL) {
            add_hash_table(inputs[i], hash_value);
            printf("%d\t%d\n", hash_value, inputs[i]); // 버퍼의 내용을 화면에 출력
        }
        else {
            printf("%d\t%d (already exists)\n", hash_value, inputs[i]); // 버퍼의 내용을 화면에 출력
        }

    }

    print_hash_table();

    return 0;
}