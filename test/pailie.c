#include <stdio.h>
#include <stdlib.h>
void perm1(int k, int a[]);
void perm2(int k, int a[]);
void perm3(int k, int a[]);

void swap(int *a, int *b);
void output(int *list);
void circle_right(int a[],int start,int end);
void circle_left(int a[],int start,int end);

int res[9];

int main(int c,char** v) {

	int i=0;
	int n=4;
	if(c==2)
		n = atoi(v[1]);
	for (i = 0; i < n; i++) {
		res[i] = i+1;
	}
	res[i] = 0;
	perm2(n, res);
	return 0;
}

void perm1(int k, int a[])
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

void perm2(int k, int a[])
{
	/*升序输出函数perm的编码*/
	int i;
	if (k==1) {
		output(res);
		return ;
	}
	for (i = 0; i < k; i++) {
		swap(&a[0],&a[i]);
		circle_right(a,1,i);
		perm2(k-1 , &a[1]);
		circle_left(a,1,i);
		swap(&a[i] , &a[0]);
	}
}

void perm3(int k, int a[])
{
	int i;
	if (k==1) {
		output(res);
		return ;
	}
	for (i = 0; i < k; i++) {
		swap(&a[0],&a[i]);
		perm3(k-1 , &a[1]);
		swap(&a[i] , &a[0]);
	}
}
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void output(int *list)
{

	for(;*list !=0 ;list++)
	{
		putchar(*list+'0');
		putchar(' ');
	}
	putchar('\n');
}

void circle_right(int a[],int start,int end)
{
	if(end<=start)
		return ;
	int temp = a[end];
	int i=end;
	for (i = end; i > start; i--) {
		a[i] = a[i-1];
	}
	a[start] = temp;
}

void circle_left(int a[],int start,int end)
{
	if(end<=start)
		return ;
	int temp = a[start];
	int i=0;
	for (i = start; i < end; i++) {
		a[i] = a[i+1];
	}
	a[end] = temp;
}
