#include <stdio.h>
int main() {
	int a = 0x12345678;
	char b = a;
	printf("%x\n",b);
	printf("===================\n");
	b='a';
	printf("%x\n", b);
	return 0;
}
