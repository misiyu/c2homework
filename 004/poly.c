#include <stdio.h>
#include <string.h>
#define formularMAX 200
#define itemMAX 10
void arrayInit(int arr[],int len);
void tranferToInt(char str[],int arr[]);

void tranferToInt(char str[],int arr[])
{
	int readPoint=0;
	int len1 = strlen(str);
	int len2=0;
	int coeff=0;
	int power=0;
	char item[itemMAX];
	int i=0;
	arrayInit(arr,formularMAX);
	for (i = 0; i < len1; i++) {
		if(str[i]!=' ')
			str[len2++]=str[i];
	}
	for (i = 0; i < len2; i++) {
		if(str[i]=='+')
			str[i]=' ';
		else if(str[i]=='-' && str[i+1]=='-')
			str[i]=str[i+1]=' ';
		else if(str[i]=='-' && i!=0)
		{
			int j=0;
			for(j=len2;j>i;j--)
				str[j]=str[j-1];
			str[i]=' ';
			i++;
			len2++;
		}
	}
	while (1) {
		sscanf(str+readPoint,"%s",item);
		len1 = strlen(item);
		readPoint += len1;
		while(str[readPoint]!=' ' && readPoint<len2)
			readPoint++;
		for (i = 0; i <len1; i++) {
			if(item[i]=='x')
				break;
		}
		if(i==0 && len1!=1)
		{
			coeff=1;
			sscanf(item+1,"%d",&power);
		}
		else if (i==1 && item[0]=='-') {
			coeff=-1;
			if(len1!=2)
				sscanf(item+2,"%d",&power);
			else
				power=1;
		}
		else if(i==len1)
		{
			sscanf(item,"%d",&coeff);
			power=0;
		}
		else if(i==len1-1)
		{
			if(len1!=1)
				sscanf(item,"%d",&coeff);
			else
				coeff=1;
			power=1;
		}
		else
		{
			sscanf(item,"%dx%d",&coeff,&power);
		}
		arr[power] += coeff;
		if(readPoint >= len2)
			break;
	}
}
void arrayInit(int arr[],int len)
{
	int i=0;
	for (i = 0; i < len; i++) {
		arr[i] = 0;
	}
}
void formularAdd(int arr1[],int arr2[],int result[])
{
	int i=0;
	for (i = 0; i < formularMAX; i++) {
		result[i]=arr1[i] + arr2[i];
	}
}
void formularSub(int arr1[],int arr2[],int result[])
{
	int i=0;
	for (i = 0; i < formularMAX; i++) {
		result[i]= arr1[i] - arr2[i];
	}
}

void formularMul(int arr1[],int arr2[],int result[])
{
	arrayInit(result,formularMAX);
	int i=0;
	int j=0;
	for (i = 0; i < formularMAX; i++) {
		if(arr1[i]!=0)
		{
			for (j = 0; j < formularMAX; j++) {
				if(arr2[j]!=0)
				{
					int coeffTemp = arr1[i]*arr2[j];
					int powerTemp = i+j;
					result[powerTemp] += coeffTemp;
				}
			}
		}
	}
}
void output(int result[])
{
	int i=formularMAX;
	short int unsigned first=0;
	for (i = formularMAX-1; i >= 0; i--) {
		if(result[i]==0)
			continue;
		if(first==0)
			first=1;
		else
		{
			if(result[i] < 0)
			{
				printf("- ");
				result[i] = -result[i];
			}
			else
				printf("+ ");
		}
		if(result[i]!=1 && i!=0 && i!=1)
			printf("%dx%d ",result[i],i);
		else if (i==0) {
			printf("%d ",result[i]);
		}else if (result[i]==1 && i!=0 && i!=1) {
			printf("x%d ",i);
		}else if (i==1 && result[i]!=1) {
			printf("%dx ",result[i]);
		}else if (i==1 && result[i]==1) {
			printf("x ");
		}
	}
	printf("\n");
}
int main() {
	FILE *fp;
	char formular1[formularMAX];
	char formular2[formularMAX];
	int formular1Int[formularMAX];
	int formular2Int[formularMAX];
	char op;
	int result[formularMAX];
	fp=fopen("poly.in","r");
	fgets(formular1,formularMAX,fp);
	fgets(formular2,formularMAX,fp);
	op=fgetc(fp);
	fclose(fp);
	tranferToInt(formular1,formular1Int);
	tranferToInt(formular2,formular2Int);

	/*int i=0;*/
	/*for (i = 0; i < formularMAX; i++) {*/
		/*if(formular1Int[i]!=0)*/
			/*printf("%d:%d ",i,formular1Int[i]);*/
	/*}*/
	/*printf(" \n");*/
	/*for (i = 0; i < formularMAX; i++) {*/
		/*if(formular2Int[i]!=0)*/
			/*printf("%d:%d ",i,formular2Int[i]);*/
	/*}*/
	/*printf("\n");*/

	if(op=='+')
		formularAdd(formular1Int,formular2Int,result);
	else if (op=='-') {
		formularSub(formular1Int,formular2Int,result);
	}else if (op=='*') {
		formularMul(formular1Int,formular2Int,result);
	}
	output(result);
	return 0;
}

