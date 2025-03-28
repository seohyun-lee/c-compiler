#include <stdio.h>                  // ����� �Լ� ���
#include <string.h>                 // ���ڿ� ó�� �Լ� ����� ���� ���
#include <stdlib.h>                 // ���� �޸� �Ҵ� �Լ� ���

#define SYM_TABLE_SIZE  100         // �ɺ� ���̺��� ũ��
#define STR_POOL_SIZE   500         // string pool�� ũ��
#define HASH_TABLE_SIZE 11          // �ؽ� ���̺��� ũ��

typedef struct HTentry* HTpointer;  // �ؽ� ���̺� ��Ʈ�� ����ü�� ������
typedef struct HTentry {            // �ؽ� ���̺� ��Ʈ�� ����ü
    int index;                      // �ɺ� ���̺��� ID�� ����
    HTpointer next;                 // ü�̴��� ���� ������
} HTentry;

char separators[] = " ,;\t\n\r\n";      // ������
int sym_table[SYM_TABLE_SIZE][3];       // �ɺ� ���̺�: [ID, str_pool �ε���, ����]
char str_pool[STR_POOL_SIZE];           // string pool
int sym_index;                          // �ɺ� ���̺� ���� �ε���
HTpointer HT[HASH_TABLE_SIZE];          // �ؽ� ���̺�

// ���ڿ��� �ƽ�Ű ���� ������� �ؽ� Ű�� ����ϴ� �Լ�
int calc_key(char* str) {
    int key = 0;
    for (int i = 0; i < strlen(str); i++) {
        key += (int)*(str + i); // str+i �ּҿ� �ִ� ���� int�� ���� �� key�� ����
    }
    return key;
}

// ����� �ؽ� �Լ�
int division_method(int key) {
    return key % HASH_TABLE_SIZE;
}

// �ؽ� ���̺��� ���� �ɺ����̺� �ĺ��ڰ� �����ϴ��� �˻��ϴ� �Լ�
HTpointer lookup_hash_table(int index_start, int length, int hscode) {
    HTpointer entry = HT[hscode];

    while (entry != NULL) {
        // �ؽ����̺� ��Ʈ���� index�� sym_table�� ID��, ID�� ���� �迭 �ε��� +1�� ��
        // sym_table���� ID-1�� �ε����� str_pool ���� �ε����� ã�� ���ڿ��� �о�, ���� str_pool�� ���� �ĺ��� ���ڿ��� ��
        if (strncmp(str_pool + sym_table[entry->index - 1][1], str_pool + index_start, length) == 0
            && sym_table[entry->index - 1][2] == length) {
            return entry;
        }
        entry = entry->next;
    }
    return NULL;
}

// �ؽ� ���̺� �����ϴ� �Լ�
void add_hash_table(int index, int hscode) {
    HTpointer newEntry = (HTpointer)malloc(sizeof(HTentry)); // �� ��Ʈ�� �Ҵ�    
    if (newEntry == NULL) {         // �� ����
        printf("�޸� �Ҵ� ����\n");
        exit(1);
    }
    newEntry->index = index;
    newEntry->next = NULL;          // ���� ����Ʈ�� ������ ��Ÿ��

    if (HT[hscode] == NULL) {       // �ؽ� ���̺� �ش� �ؽ� �ڵ�� ��Ʈ���� �����ϴ��� Ȯ��
        HT[hscode] = newEntry;      // ������ �ٷ� �߰�
    }
    else {                            // �̹� �ִٸ� ü�̴����� �� �׸��� ����Ʈ �� �տ� �߰�
        newEntry->next = HT[hscode];  // �� ��Ʈ���� next�� ���� ù ��° ��Ʈ��
        HT[hscode] = newEntry;        // �ؽ� ���̺� hscode��° ���Ұ� ����Ű�� ��ġ�� �� ��Ʈ���� ������Ʈ
    }
}

// �ĺ��ڿ� ���� �ؽ� ���̺��� Ȯ���ϰ�, �̹� �����ϴ� �ĺ��ڰ� �ƴ϶�� �ؽ����̺� �� �ɺ� ���̺� �����ϴ� �Լ�
int insert_symbol(const char* str, int index_start, int length) {
    int hash_value = division_method(calc_key(str));

    HTpointer htp = lookup_hash_table(index_start, length, hash_value);
    if (htp == NULL) { // �ؽ� ���̺� ���� ���
        // �����÷ο� �� ���� ó��
        if (sym_index >= SYM_TABLE_SIZE) {
            printf("Error - Symbol table overflow\n");
            return -1;
        }
        printf("%d\t%s\n", hash_value, str);

        // �ؽ� ���̺� �߰�
        add_hash_table(sym_index + 1, hash_value);

        // �ɺ� ���̺� �߰�
        sym_table[sym_index][0] = sym_index + 1;    // ID
        sym_table[sym_index][1] = index_start;      // string_pool �����ε���
        sym_table[sym_index++][2] = length;         // ����
        return 0;
    }
    else { // �ؽ� ���̺� �̹� �ִ� ��� ���� ��� �� �������� ����
        printf("%d\t%s (already exists)\n", hash_value, str);
        return -1;
    }
}

// �ɺ� ���̺� ��� �Լ�
void print_sym_table() {
    printf("\nSymbol Table\nID\tIndex\tLength\tSymbol\n");
    for (int i = 0; i < sym_index; i++) {
        printf("%d\t%d\t%d\t%s\n", sym_table[i][0], sym_table[i][1], sym_table[i][2], str_pool + sym_table[i][1]);
    }
    return;
}

// �ؽ� ���̺� ��� �Լ�
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

// ���� �Ҵ�� �ؽ� ���̺� �޸� ����
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
    int c;                  // ���� ���ڸ� ������ ����
    int index_start = 0;    // ���� �ε���
    int index_next = 0;     // ���� �ε���
    int err_flag = 0; // 0: ����, -1: �ҹ� ���� ����, -2: ���ڷ� ����, -3: 15�� �ʰ�

    result = fopen_s(&fp, "example.txt", "r"); // "example.txt" ������ �б� ���� ����
    if (result != 0) {
        printf("���� ���� ����(%d)\n", result);
        return -1;
    }

    do {                    // ���� ������ ����
        c = fgetc(fp);      // fp���� �� ���ڸ� �о��

        // string pool �����÷ο� ����
        if (index_next >= STR_POOL_SIZE) {
            fprintf(stderr, "Error - String Pool overflow\n");
            break;
        }

        if (c == EOF || (strchr(separators, c) != NULL)) { // separator�� ���԰ų� ��
            if (index_next == index_start) { // �ĺ��� ���̰� ���ٸ� ���� (�������� �����ڰ� �� �� ���� ���)
                continue;
            }

            str_pool[index_next++] = '\0'; // str_pool�� �� ���ڸ� �ְ� index_next�� ����

            // �ĺ��� ���̰� 15�� �ʰ��ϴ� ��� ����
            int length = index_next - index_start - 1;
            if (length > 15) {
                err_flag = -3;
            }

            // err_flag�� ���� �ɺ����̺� �����ϰų�, string pool�� ó���� (err_flag�� 0�� ��찡 ����)
            if (err_flag == 0) {
                int res = insert_symbol(str_pool + index_start, index_start, length); // ���� �� ��� ó��
                if (res == -1) {
                    index_next = index_start; // string pool ���� �ѹ�
                }
                else {
                    index_start = index_next; // index_start�� index_next�ڸ��� �ű�
                }
            }
            else { // ����
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

                index_next = index_start; // string pool ���� �ѹ�
                err_flag = 0;             // ���� ���·� ����
            }
        }
        else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_') { // ���ĺ��̳� ����� ������ ��� ����
            str_pool[index_next++] = (char)c;
        }
        else if (c >= '0' && c <= '9') { // ���� ������ ���: ù �ڸ��� ���ڰ� ���� ��� ����, err_flag�� -2�� ����. �׿� ����
            if (index_next == 0 || str_pool[index_next - 1] == '\0') {
                err_flag = -2;
            }
            str_pool[index_next++] = (char)c;
        }
        else { // �ĺ��ڷ� ��ȿ���� ���� ������ ��� ����, err_flag�� -1�� ����
            err_flag = -1;
            str_pool[index_next++] = (char)c;
        }
    } while (c != EOF);

    print_sym_table();          // �ɺ� ���̺� ���
    print_hash_table();         // �ؽ� ���̺� ���
    free_memory_allocations();  // �޸� �Ҵ� ����

    fclose(fp);                 // ���� �ݱ�
    return 0;
}