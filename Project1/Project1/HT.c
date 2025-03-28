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
* �Է�:
* index - ���� string pool ��ġ
* hscode - ���� �Էµ� symbol�� hash code
*
* ���:
* HTpointer - ã���� �ϴ� symbol�� �̹� ������ ��� �ش� symbol�� ����� HTpointer ��ȯ
*             ���� ���� NULL ��ȯ
*/
HTpointer lookup_hash_table(int index, int hscode) {
    HTpointer entry = HT[hscode];

    // ü�̴׵� ����Ʈ�� Ž��
    while (entry != NULL) {
        /* ������ ���ؼ��� Ž���ϰ��� �ϴ� ���� ���ϴ� �ڵ�� ����Ǿ�� ��
        * ��: �ɺ����̺� ����� ID/index/length�� �̿��Ͽ� ���� string pool�� symbol�� ������ ��
        */
        if (entry->index == index) {
            return entry; // ã�� �׸� ��ȯ
        }
        entry = entry->next;
    }
    return NULL; // �׸��� ã�� ���� ���
}

/* add_hash_table()
*
* �Է�:
* index - ���� string pool ��ġ
* hscode - ���� �Էµ� symbol�� hash code
*
* ���: ����
*/
void add_hash_table(int index, int hscode) {
    // �� �׸� ���� �� �ʱ�ȭ
    HTpointer newEntry = (HTpointer)malloc(sizeof(HTentry));
    if (newEntry == NULL) {
        printf("�޸� �Ҵ� ����\n");
        exit(1);
    }
    newEntry->index = index;
    newEntry->next = NULL;

    if (HT[hscode] == NULL) {
        // ù ��° �׸����� �߰�
        HT[hscode] = newEntry;
    }
    else {
        // �̹� �׸��� ������, ����Ʈ�� �� �տ� �߰�
        newEntry->next = HT[hscode];
        HT[hscode] = newEntry;
    }
}

/* print_hash_table()
*
* �Է�: ����
* ���: ����
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
            printf("%d\t%d\n", hash_value, inputs[i]); // ������ ������ ȭ�鿡 ���
        }
        else {
            printf("%d\t%d (already exists)\n", hash_value, inputs[i]); // ������ ������ ȭ�鿡 ���
        }

    }

    print_hash_table();

    return 0;
}