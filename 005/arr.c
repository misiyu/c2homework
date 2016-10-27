#include <stdio.h>
#define MATRIXSIZE 200

void getNum(char str[],int arr[],int* arrLen);

int a[MATRIXSIZE][MATRIXSIZE];
int b[MATRIXSIZE][MATRIXSIZE];
int result[MATRIXSIZE][MATRIXSIZE];

int m=0;
int k=0;
int n=0;
void init()
{
	FILE *fp=fopen("arr.in","r");	
	char str[MATRIXSIZE*5];
	fgets(str,MATRIXSIZE*5,fp);
		getNum(str,a[m],&k);
	int line =1 ;
	while(fgets(str,MATRIXSIZE*5,fp)!=NULL)
		line++;
	fseek(fp, 0, SEEK_SET);
	int i=0;
	int line1 = line - k;
	int line2 = k;
	for (i = 0; i < line1; i++) {
		fgets(str,MATRIXSIZE*5,fp);
		getNum(str,a[m],&k);
		m++;
	}
	for (i = 0; i < line2; i++) {
		fgets(str,MATRIXSIZE*5,fp);
		getNum(str,b[i],&n);
	}
}

void getNum(char str[],int arr[],int* arrLen)
{
	char *p=str;
	int sscret=0;
	int bias=0;
	int len=0;
	int temp=0;
	while(1)
	{
		sscret=sscanf(p,"%d%n",&temp,&bias);
		if(sscret == 1)
		{
			arr[len++] = temp;
			p += bias;
		}else if (sscret == 0) {
			p ++;
		}else{
			*arrLen = len;
			return ;
		}
	}
}
int getresultIJ(int a[],int col)
{
	int ret=0;
	int i=0;
	for(i = 0;i< k;i++)
	{
		ret += a[i]*b[i][col];
	}
	return ret;
}
void getresult()
{
	int i=0;
	for(i = 0;i<m;i++)
	{
		int j=0;
		for(j = 0; j<n;j++)
		{
			result[i][j] = getresultIJ(a[i],j);
		}
	}
}
void output()
{
	int i=0;
	for (i = 0; i < m; i++) {
		int j=0;
		for(j = 0; j< n;j++)
		{
			printf("%-12d ",result[i][j]);
		}
		printf("\n");
	}
}
int main() {
	init();
	getresult();
	output();
	return 0;
}
