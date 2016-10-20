#include <stdio.h>
int getInput(int *m,int *k);
long double caculate(int m,int k);
int output(long double result);
int main() {

	long double result;
	int m=0;
	int k=0;
	int ret=0;
	ret=getInput(&m,&k);
	if (ret==1) {
		return ret;
	}
	result=caculate(m,k);
	output( result);
	return 0;
}
int getInput(int *m,int *k)
{
	FILE *fp = fopen("poisson.in","r");
	if(fp ==NULL)
	{
		return 1;
		printf("no file named poisson.in");

	}
	fscanf(fp,"%d%d",m,k);
	if(*m<=0 || *m>=2000 || *k<0 || *k>=2500)
		return 1;
	fclose(fp);
	return 0;
}

long double caculate(int m,int k)
{
	double  e = 2.718281828459;
	long double result=1;
	if (k==0) {
		int i=0;
		for (i = 0; i < m; i++) {
			result = result/e;
			if (result < 0.000001) {
				result = 0;
				break;
			}
		}
	}
	else 
	{
		int i=0;
		int j=1;
		while (i < m || j<=k) {
			if (i<m) {
				result = result/e;
				i++;
			}
			if(j<=k)
			{
				result = result*m/j;
				j++;
			}
		}
	}
	return result;
}

int output(long double result)
{
	double resultou = result;
	printf("%e\n",resultou);
	FILE *fp;
	fp = fopen("poisson.out","w");
	fprintf(fp, "%e\n",resultou);
	fclose(fp);
	return 0;
}
