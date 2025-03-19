#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define SYM_TABLE_SIZE 100

int main() {
	FILE* fp;
	int err;
	char str_pool[100];
	char separators[] = ".\r\n"; // ���
	int sym_table[SYM_TABLE_SIZE][2];

	err = fopen_s(&fp, "file.txt", "r");
	if (err != 0) {
		printf("���� �б⿡ �����߽��ϴ�.");
		return -1;
	}

	int c, index_start=0, index_next=0;
	char* s;
	while ((c = fgetc(fp)) != EOF) {
		if (strchr(separators, c) != NULL) { // ��������
			if (index_start < index_next) {
				str_pool[index_next++] = '\0'; // ���ڿ� ���� (�� ����)

				if (str_pool[index_start] >= '0' && str_pool[index_start] <= '9') {
					printf("Error - start with digit (%d)\n", str_pool + index_start);
				}
				else {
					// ����
					printf("%d (%d)\n", str_pool + index_start, index_start);
				}
				index_start = index_next; // ���� �ε��� �ʱ�ȭ
			}
		}
		str_pool[index_next++] = (char)c;
	}
	// ���������ڿ� ���
	if (index_start < index_next) {
		str_pool[index_next++] = '\0';
		printf("%s (%d)\n", str_pool + index_start, index_start);
	}
	fclose(fp); // ���� �ݱ�
	return 0;
}