#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 50
void transBtoG(short unsigned int arr1[],short unsigned int arr2[],int len);
void transGtoB(short unsigned int arr1[],short unsigned int arr2[],int len);
void transChtoInt(char *str,short unsigned int arr[],int *lenPara, char *optionPara);
void output(short int unsigned arr[],int len);

int main() {
	char str[MAX];
	char *strP[1000];
	int strNum = 0;
	while(scanf("%s",str)!=EOF)
	{
		strP[strNum] = (char*)malloc(sizeof(char)*strlen(str));
		strcpy(strP[strNum],str);
		strNum ++;
	}
	int i=0;
	for (i = 0; i < strNum; i++) {
		short unsigned int arr1[MAX];
		int len = 0;
		short unsigned int arr2[MAX];
		char option = 'b';
		transChtoInt(strP[i],arr1,&len,&option);
		free(strP[i]);
		if(option == 'g')
			transBtoG(arr1,arr2,len);
		else 
			transGtoB(arr1,arr2,len);
		output(arr2,len);
	}
	return 0;
}

void output(short int unsigned arr[],int len)
{
	int i=0;
	for (i = 0; i < len; i++) {
		printf("%d",arr[i]);
	}
	printf("\n");
}
void transChtoInt(char *str,short unsigned int arr[],int *lenPara, char *optionPara)
{
	int len = strlen(str);
	int i=0;
	if(str[0] == '-')
	{
		*optionPara = str[1];
		*lenPara = len-2;
		for (i = 2; i < len; i++) {
			arr[i-2] = str[i]-'0';
		}
	}
	else
	{
		*optionPara = 'b';
		*lenPara = len;
		for (i = 0; i < len; i++) {
			arr[i] = str[i]-'0';
		}
	}
}
void transBtoG(short unsigned int arr1[],short unsigned int arr2[],int len)
{
	int i = 0;
	arr2[0] = 0^arr1[0];
	for (i = 1; i < len-1; i++) {
		arr2[i] = arr1[i] ^ arr1[i-1];
	}
}

void transGtoB(short unsigned int arr1[],short unsigned int arr2[],int len)
{
	arr2[0] = arr1[0];
	int i=0;
	for (i = 1; i < len; i++) {
		arr2[i] = arr2[i-1] ^ arr1[i];
	}
}
