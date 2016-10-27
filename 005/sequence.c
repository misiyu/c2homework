#include <stdio.h>
#define MAX 20

void changeArrToInt(int arr[],int len , long int *anum)
{
	int temp =1;
	int i=0;
	long result=0;
	for (i = 0; i < len; i++) {
		result += temp*arr[i];
		temp *= 10;
	}
	*anum = result ;
}

void changeIntToArr(long anum, int arr[], int *len)
{
	int i=0;
	for (i = 0; anum !=0; i++) {
		arr[i] = anum % 10;
		anum /= 10;
	}
	*len = i;
}

int getNumberSum(long num)
{
	int result =0;
	while(num != 0)
	{
		result += num %10;
		num /= 10;
	}
	return result;
}

void serveConst(int temp, int arr2[],int *lenP,int i)
{
	int len = *lenP;
	for (; ; i++) {
		if(i >= len)
			arr2[i] =0;
		if(temp + arr2[i] > 9)
		{
			temp = temp - (9-arr2[i]);
			arr2[i] = 9;
		}
		else
		{
			arr2[i] += temp;
			break;
		}
	}
	if(i >= len)
		*lenP = i+1;
}
void serveConst2(int temp , int arr2[],int *lenP,int i)
{
	int marki = i;
	int len = *lenP;
	for(;i>=0;i--)
		arr2[i] = 0;
	for (i = marki;; i++) {
		if(i>=len)
			arr2[i] = 0;
		if(arr2[i]+temp-1>9)
		{
			temp = temp - (9 - arr2[i]);
			arr2[i] = 9;
		}
		else
		{
			arr2[i]+= temp-1;
			arr2[i+1]++;
			break;
		}
		if(i>len)
			*lenP = i;
	}
}
void constructAnext(int arr1[],int arr2[],int *lenP,int sum2)
{
	int len = *lenP;
	int i=0;
	int temp = sum2;
	for (i = len-1; i >=0 ; i--) {
		if(temp > arr1[i])
		{
			arr2[i] = arr1[i];
			temp -= arr1[i];
		}
		else
			break;
	}
	if( i < 0 )
	{
		serveConst(temp,arr2,&len,0);
	}
	else if(i == len - 1)
	{
		arr2[len++] = 1;
		for (i = 0; i < len; i++) {
			if(temp>9)
			{
				arr2[i] = '9';
				temp -= 9;
			}
			else
			{
				arr2[i] = temp-1;
				for (i++; i < len-1; i++) {
					arr2[i] = 0;
				}
				break;
			}
		}
	}
	else
	{
		serveConst2(temp,arr2,&len,i);
	}
	*lenP = len;
}

void copyArr(int arr1[], int arr2[],int len)
{
	int i=0;
	for (i = 0; i < len; i++) {
		arr1[i] = arr2[i];
	}
}
int main() {

	int a[MAX];
	int aTemp[MAX];
	int aLen=0;
	long int aValue=0;
	int k=0;
	int n=0;
	FILE *fp = fopen("sequence.in","r");
	fscanf(fp,"%d%d%d",&a[0],&k,&n);
	fclose(fp);
	aValue = a[0];
	long aValueTwice ;
	int i=0;
	changeIntToArr(aValue,a,&aLen);
	for (i = 0; i < n-1; i++) {
		aValueTwice = aValue*2 ;
		int numSum2 = getNumberSum(aValueTwice);
		constructAnext(a,aTemp,&aLen,numSum2);
		copyArr(a,aTemp,aLen);
		changeArrToInt(a,aLen,&aValue );
	}
	printf("%ld\n",aValue);
	fp = fopen("sequence.out","w");
	fprintf(fp,"%ld\n",aValue);
	return 0;
}
