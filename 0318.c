#include <stdio.h>

int main() {
    FILE* fp;
    int result;
    char str_pool[100];

    result = fopen_s(&fp, "example.txt", "r");
    if (result != 0) {
        printf("파일 열기 실패(%d)\n", result);
        return -1;
    }

    while (fgets(str_pool, sizeof(str_pool), fp) != NULL) {
        printf("%s", str_pool); // 버퍼의 내용을 화면에 출력
    }

    fclose(fp);
    return 0;
}