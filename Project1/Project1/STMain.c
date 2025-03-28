#include <stdio.h>          // ����� ���
#include <string.h>         // ���ڿ� ���� �Լ� ����� ���� ���
#include <stdbool.h>        // bool, true, false ����� ���� ���
#include <stdlib.h>         // malloc �Ҵ��� ���� ���

#define SYM_TABLE_SIZE  100         // �ɺ� ���̺� ������ ����
#define STR_POOL_SIZE   500         // string pool ������ ����
#define HASH_TABLE_SIZE 23          // �ؽ� ���̺� ������ ����

typedef struct HTentry* HTpointer;  // �ؽ� ���̺� ��Ʈ�� ����ü�� ������
typedef struct HTentry {            // �ؽ� ���̺� ��Ʈ�� ����ü
    int index;
    HTpointer next;
} HTentry;

char separators[] = " ,;\t\n\r\n";  // ������
int sym_table[SYM_TABLE_SIZE][3];   // �ɺ� ���̺�
char str_pool[STR_POOL_SIZE];       // string pool
int sym_id;                         // �ɺ� ���̺� ID
HTpointer HT[HASH_TABLE_SIZE];      // �ؽ� ���̺�


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
    newEntry->index = index;    // �ش� ��Ʈ���� �ε����� ����
    newEntry->next = NULL;      // ���� ����Ʈ�� ������ ��Ÿ��

    if (HT[hscode] == NULL) {   // �ؽ� ���̺� �ش� �ؽ� �ڵ�� ��Ʈ���� �����ϴ��� Ȯ��
        HT[hscode] = newEntry;  // ������ �ٷ� �߰�
    }
    else {
        // ��ew[[�� ü�̴� ������� �� �׸��� ����Ʈ �� �տ� �߰�
        newEntry->next = HT[hscode];  // �� �׸��� next�� ���� ù ��° �׸�
        HT[hscode] = newEntry;        // �ؽ� ���̺��� �ش� ��ġ�� �� �׸����� ������Ʈ

        // �̹� �׸��� ��Ʈ����, ����Ʈ�� �� �տ� �߰�
        newEntry->next = HT[hscode];
        HT[hscode] = newEntry;
    }
}
// �ؽ� ���̺� ����
void add_hash_table(int index, int hscode) { // void�� � ���̵� ��ȯ�Ҽ��� �ִ�
    HTpointer newEntry = (HTpointer)malloc(sizeof(HTentry)); // ����ü��ŭ �Ҵ�ް� HTpointer���¸� ������
    if (newEntry == NULL) { // �� üũ �ʼ�
        printf("�޸� �Ҵ� ����");
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
        return -1; // -1�� ���ϵǴ� ��� string pool���� ����
    }
    //HTpointer node = HT[hash];

    //while (node != NULL) {
    //    int idx = sym_table[node->sym_id][1];
    //    int l = sym_table[node->sym_id][2];

    //    if (l == length && strncmp(str_pool + idx, str, length) == 0) {
    //        // �ߺ� �ĺ��� �� ���� ID ���
    //        printf("Already exists: ID=%d, Symbol=", node->sym_id);
    //        for (int i = 0; i < l; i++) putchar(str_pool[idx + i]);
    //        putchar('\n');
    //        return node->sym_id;
    //    }
    //    node = node->next;
    //}

    // �� �ĺ��� �߰�
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
        key += (int)*(str + i); // str+i �ּҿ� �ִ� ���� int�� ����
    }
    return key;
}

int divisionMethod(int key, int tableSize) {
    return key % tableSize;
}

// lookup_hash_table�� ��� �� �̰� ����
//int find_symbol(const char* str, int len) {
//    for (int i = 0; i < sym_id; i++) {
//        int idx = sym_table[i][1];
//        int l = sym_table[i][2];
//        if (l == len && strncmp(str_pool + idx, str, len) == 0) {
//            return i;  // �̹� �����ϴ� �ɺ��� ID ��ȯ
//        }
//    }
//    return -1;  // ����
//}

// string pool
//�ɺ����̺� �ε��������� ���ڿ� �� �о�� �ε��� ��Ʈ��Ǯ ���ڿ� ���Ѵٰų� �ؼ� �ض�??
HTpointer lookup_hash_table(int index, int hscode) {
    HTpointer entry = HT[hscode];

    while (entry != NULL) {
        if (strncmp(sym_table[entry->index], sym_table[index])) { // �� �̷��� (strncmp?? strcmp??)
            return entry;
        }
        entry = entry->next;
    }
    return NULL;
}


// �ɺ� ���̺� ��� (�����ؾ�!!!!!!!!1
void print_sym_table(void)
{
    printf("\nSymbol Table\nIndex\tLength\tSymbol\n"); // ID���ٸ� i+1
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

// �ؽ� ���̺� ���
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
    // �ؽ� ���̺� �޸� �Ҵ� ���� 
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
    int result; // ���� �Լ� ���� ����� ����
    int c; // ���� ���ڸ� ������ ����
    int index_start = 0;
    int index_next = 0;

    result = fopen_s(&fp, "example.txt", "r"); // "example.txt" ������ �б� ���� ����
    if (result != 0) {
        printf("���� ���� ����(%d)\n", result);
        return -1;
    }

    int err_flag = FALSE; // identifier�� ���ڷ� �����ϸ� �ȵ�. Ư�����ڰ����͵� ���� �ȵ�. ���̵� �Ѿ�� �ȵ�. �׷��� �߻��� �����÷��׸� TRUE��.
    do { // ���� ������ ���� �б�
        c = fgetc(fp);

        if (index_next >= STR_POOL_SIZE) { // ������� �Է��� �ĺ��ڶ�°�, ���� �Է����� �ĺ��ڴ�??
            fprintf(stderr, "Error - String Pool overflow\n");
            break;
        }

        if ((strchr(separators, c) != NULL) || c == EOF) { // separator�� ���԰ų� ��
            str_pool[index_next++] = '\0'; // �� �� ������ index_next�� ����

            if (index_next - index_start - 1 > 15) {
                err_flag = TRUE;
            }

            if (err_flag != TRUE) {
                int id = find_symbol(str_pool + index_start, index_next - index_start - 1);
                if (id != -1) {
                    // �̹� ���� �� ���� ���� ���
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
        else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_') // ������ ������ ����
        {
            str_pool[index_next++] = (char)c;
        }
        else if (c >= '0' && c <= '9') // ������ ������ ����
        {
            if (index_next == 0 || str_pool[index_next - 1] == '\0')
                err_flag = TRUE;
            str_pool[index_next++] = (char)c;
        }
        else
        {
            str_pool[index_next++] = (char)c; // ������ �������� �����÷��׸� true��->�������� ó��
            err_flag = TRUE;
        }
    } while (c != EOF);

    print_sym_table();
    print_hash_table();

    fclose(fp); // ���� �ݱ�
    free_memory_allocations();
    return 0;
}