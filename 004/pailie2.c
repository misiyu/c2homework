#include <stdio.h>
#include <stdlib.h>
void perm2(int k, int a[]);

void swap(int *a, int *b);
void output(int *list);
void circle_right(int a[],int start,int end);
void circle_left(int a[],int start,int end);
int getrepeatTimes();

int res[9];
int n=0;
int m=0;
int repeatTimes=0;
int count = 0;
int main() {

	scanf("%d%d",&n,&m);
	int i=0;
	for (i = 0; i < n; i++) {
		res[i] = i+1;
	}
	res[i] = 0;
	repeatTimes = getrepeatTimes();
	perm2(n, res);
	return 0;
}

int getrepeatTimes()
{
	int temp =1;
	int i=1;
	for (i = 1; i <= n-m; i++) {
		temp *= i;
	}
	return temp;
}
void perm2(int k, int a[])
{
	/*升序输出函数perm的编码*/
	int i;
	if (k==1) {
		count = ( count+1 ) %repeatTimes;
		if(count == 0)
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

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void output(int *list)
{
	int i=0;
	for(i=0;i<m && *list !=0 ;list++,i++)
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
