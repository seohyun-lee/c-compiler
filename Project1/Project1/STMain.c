#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define SYM_TABLE_SIZE  100
#define STR_POOL_SIZE 500
#define HASH_SIZE 23
#define TRUE    1
#define FALSE   0

char separators[] = " ,;\t\n\r\n"; //������ ���� (�� \n�� �ΰ�?)
int sym_table[SYM_TABLE_SIZE][3];
char str_pool[STR_POOL_SIZE];
//char hash_bucket[HASH_SIZE];
int sym_id; // 0���� �⺻ �ʱ�ȭ

typedef struct SymbolNode {
    int sym_id;
    struct SymbolNode* next;
} SymbolNode;

SymbolNode* hash_bucket[HASH_SIZE];  // �� ��Ŷ�� ���� ����Ʈ ���

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

void print_hash_bucket(void) {
    printf("\nHash Buckets (Chaining)\n");
    for (int i = 0; i < HASH_SIZE; i++) {
        printf("[%d] -> ", i);
        SymbolNode* node = hash_bucket[i];
        while (node != NULL) {
            int idx = sym_table[node->sym_id][1];
            int len = sym_table[node->sym_id][2];
            for (int j = 0; j < len; j++) {
                putchar(str_pool[idx + j]);
            }
            printf(" -> ");
            node = node->next;
        }
        printf("NULL\n");
    }
    // free
    for (int i = 0; i < HASH_SIZE; i++) {
        SymbolNode* node = hash_bucket[i];
        while (node != NULL) {
            SymbolNode* tmp = node;
            node = node->next;
            free(tmp);
        }
    }
}

int insert_symbol(const char* str, int index_start, int length) {
    // ���� �߰�
    int key = calc_key(str_pool + index_start);
    int hash = hash_division_method(key);

    SymbolNode* node = hash_bucket[hash];
    while (node != NULL) {
        int idx = sym_table[node->sym_id][1];
        int l = sym_table[node->sym_id][2];

        if (l == length && strncmp(str_pool + idx, str, length) == 0) {
            // �ߺ� �ĺ��� �� ���� ID ���
            printf("Already exists: ID=%d, Symbol=", node->sym_id);
            for (int i = 0; i < l; i++) putchar(str_pool[idx + i]);
            putchar('\n');
            return node->sym_id;
        }
        node = node->next;
    }

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

unsigned int hash_division_method(int key) {
    return key % HASH_SIZE;
}

unsigned int hash_midsquare_method(int base) {
    unsigned long long square = (unsigned long long)base * base;

    // �߰� ��Ʈ�� ���� (��: 32��Ʈ �� ��� 8��Ʈ ���)
    unsigned int mid = (square >> 8) & 0xFFFF;

    return mid % HASH_SIZE;
}

int find_symbol(const char* str, int len) {
    for (int i = 0; i < sym_id; i++) {
        int idx = sym_table[i][1];
        int l = sym_table[i][2];
        if (l == len && strncmp(str_pool + idx, str, len) == 0) {
            return i;  // �̹� �����ϴ� �ɺ��� ID ��ȯ
        }
    }
    return -1;  // ����
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
    print_hash_bucket();

    fclose(fp); // ���� �ݱ�
    return 0;
}

/*

int midsquareMethod()
{

}

int foldingMethod()
{

}
*/