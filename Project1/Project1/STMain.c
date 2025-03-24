#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define SYM_TABLE_SIZE  100
#define STR_POOL_SIZE 8
#define HASH_SIZE 23
#define TRUE    1
#define FALSE   0

char separators[] = " ,;\t\n\r\n"; //구분자 (윈도우 캐리지리턴은 \r\n)
char str_pool[STR_POOL_SIZE];
char hash_bucket[HASH_SIZE];
int sym_id; // 0으로 기본 초기화

typedef struct {
    int index;
    int length;
    char* symbol;
} Symbol;

Symbol sym_table[SYM_TABLE_SIZE];


void print_sym_table(void)
{
    printf("\nSymbol Table\nIndex\tLength\tSymbol\n"); // ID였다면 i+1
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
        key += (int)*(str + i); // str+i 주소에 있는 값을 int로 변경
    }
    return key;
}

unsigned int hash_division_method(int key) {
    return key % HASH_SIZE;
}

unsigned int hash_midsquare_method(int base) {
    unsigned long long square = (unsigned long long)base * base;

    // 중간 비트를 추출 (예: 32비트 중 가운데 8비트 사용)
    unsigned int mid = (square >> 8) & 0xFFFF;

    return mid % HASH_SIZE;
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

        if (index_next >= STR_POOL_SIZE) { // 현재까지 입력한 식별자라는게, 지금 입력중인 식별자는?? \0은??
            fprintf(stderr, "Error - String Pool overflow\n");
            break;
        }

        if ((strchr(separators, c) != NULL) || c == EOF) { // separator가 나왔거나 끝
            str_pool[index_next++] = '\0'; // 이 줄 다음에 index_next가 증가

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

    fclose(fp); // 파일 닫기
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