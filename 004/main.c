#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void perm1(int k, char a[]);

void swap(char *a, char *b);
void output(char *list);

char res[100];
int n;
int main() {
	fgets(res,100,stdin);
	n = strlen(res)-1;
	res[n]=0;
	perm1(n, res);
	return 0;
}

void perm1(int k, char a[])
{
	int i;
	if (k==1) {
		output(res);
		return ;
	}
	for (i = 0; i < k; i++) {
		swap(&a[0],&a[i]);
		perm1(k-1 , &a[1]);
		swap(&a[i] , &a[0]);
	}
}

void swap(char *a, char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

void output(char *list)
{
	int i=0;
	for(i=0;i<n;i++,list++)
	{
		putchar(*list);
	}
	putchar('\n');
}

