#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define SYM_TABLE_SIZE  100
#define STR_POOL_SIZE 8
#define HASH_SIZE 23
#define TRUE    1
#define FALSE   0

char separators[] = " ,;\t\n\r\n"; //������ (������ ĳ���������� \r\n)
char str_pool[STR_POOL_SIZE];
char hash_bucket[HASH_SIZE];
int sym_id; // 0���� �⺻ �ʱ�ȭ

typedef struct {
    int index;
    int length;
    char* symbol;
} Symbol;

Symbol sym_table[SYM_TABLE_SIZE];


void print_sym_table(void)
{
    printf("\nSymbol Table\nIndex\tLength\tSymbol\n"); // ID���ٸ� i+1
    for (int i = 0; i < sym_id; i++) {
        printf("%d\t%d\t%s\n", sym_table[i].index, sym_table[i].length, sym_table[i].symbol);
    }
    return;
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

        if (index_next >= STR_POOL_SIZE) { // ������� �Է��� �ĺ��ڶ�°�, ���� �Է����� �ĺ��ڴ�?? \0��??
            fprintf(stderr, "Error - String Pool overflow\n");
            break;
        }

        if ((strchr(separators, c) != NULL) || c == EOF) { // separator�� ���԰ų� ��
            str_pool[index_next++] = '\0'; // �� �� ������ index_next�� ����

            if (index_next - index_start - 1 > 15) {
                err_flag = TRUE;
            }

            if (err_flag != TRUE) {
                int key = calc_key(str_pool + index_start);
                int hash = hash_division_method(key);
                printf("%d\t%s\n", hash, str_pool + index_start);
                sym_table[sym_id].index = index_start;
                sym_table[sym_id].length = index_next - index_start - 1;
                sym_table[sym_id].symbol = str_pool + index_start;
                sym_id++;
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