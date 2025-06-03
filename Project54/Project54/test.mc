/* This is
sample input */

const int max=100;

int main(int a, char c)
{ //
	int result = 8;
	int hexa1 = +0x12;
	int octa2 = -07;
	int b, d;
	char str[10] = "hello";
	int aaaaabbbbbccccc = 0;
	float fnum1 = -0.24;
	float fnum2 = +0.24;
	if (result >= 0) {
		result *= -3;
	} else {
		result %= 2;
	}
	while (result < 0) result++;
	return result;
}