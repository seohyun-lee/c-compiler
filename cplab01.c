#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define SYM_TABLE_SIZE 100

int main() {
	FILE* fp;
	int err;
	char str_pool[100];
	char separators[] = ".\r\n"; // 등등
	int sym_table[SYM_TABLE_SIZE][2];

	err = fopen_s(&fp, "file.txt", "r");
	if (err != 0) {
		printf("파일 읽기에 실패했습니다.");
		return -1;
	}

	int c, index_start=0, index_next=0;
	char* s;
	while ((c = fgetc(fp)) != EOF) {
		if (strchr(separators, c) != NULL) { // 구분자임
			if (index_start < index_next) {
				str_pool[index_next++] = '\0'; // 문자열 종료 (빈 문자)

				if (str_pool[index_start] >= '0' && str_pool[index_start] <= '9') {
					printf("Error - start with digit (%d)\n", str_pool + index_start);
				}
				else {
					// 정상
					printf("%d (%d)\n", str_pool + index_start, index_start);
				}
				index_start = index_next; // 버퍼 인덱스 초기화
			}
		}
		str_pool[index_next++] = (char)c;
	}
	// 마지막문자열 출력
	if (index_start < index_next) {
		str_pool[index_next++] = '\0';
		printf("%s (%d)\n", str_pool + index_start, index_start);
	}
	fclose(fp); // 파일 닫기
	return 0;
}