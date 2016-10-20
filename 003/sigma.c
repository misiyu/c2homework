#include <stdio.h>
long long getIntPart(int k, int x, int n);
double getDemPart(int k,int x,int m);
int main() {
	int k,x,m,n;
	FILE *fp=fopen("sigma.in","r");
	fscanf(fp,"%d%d%d%d",&k,&x,&m,&n);
	fclose(fp);
	if(x==1)
	{
		printf("1.00000000000000\n");
		return 0;
	}
	long long intpart = getIntPart(k,x,n);
	double demPart= getDemPart(k,x,m);
	while(demPart>1)
	{
		demPart = demPart-1;
		intpart = intpart+1;
	}
	printf("%lld",intpart);
	char str[20];
	sprintf(str,"%.14f",demPart);
	puts(str+1);
	return 0;
}

long long getIntPart(int k, int x, int n)
{
	long long result=1;
	int i=0;
	long long temp=x;
	for (i = 0; i < n; i++)
	{
		result+=temp;
		temp *= x;
	}
	return result*k;
}

double getDemPart(int k,int x,int m)
{
	double result=1;
	long double temp =getIntPart(k,x,m-1);
	long double temp1 =1;
	int i=0;
	for (i = 0; i < m; i++)
	{
		temp1 *= x;
	}
	result=temp/temp1;
	return result;
}
