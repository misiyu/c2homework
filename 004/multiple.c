#include <stdio.h>
#include <string.h>
#define LISTSIZE 505
short int unsigned validNUM[10];
short int unsigned N[LISTSIZE];
int Nlen;
int check(short int unsigned multiple[],int multipleLen)
{
	int i=0;
	for (i = 0; i < multipleLen; i++) {
		if(validNUM[multiple[i]]!=1)
			return 0;
	}
	return 1;
}
void init(short int unsigned multiple[], int *multipleLen)
{
	FILE *fp=fopen("multiple.in","r");
	int n=0;
	int validTemp=0;
	int i=0;
	int len=0;
	for (i = 0; i < 10; i++) {
		validNUM[i]=0;
	}
	fscanf(fp,"%d",&n);
	printf("%d\n",n);
	while(fscanf(fp,"%d",&validTemp)!=EOF)
	{
		while(1)
		{
			int temp = validTemp%10;
			validNUM[temp]=1;
			validTemp /= 10;
			if(validTemp==0)
				break;
		}
	}
	while(n!=0)
	{
		multiple[len]=N[len]=n%10;
		len++;
		n /= 10;
	}
	fclose(fp);
	*multipleLen = len;
	Nlen = len;
	for (i = 0; i < Nlen; i++) {
		printf("%d ",N[i]);
	}
	printf("\n");
}
void add(short int unsigned multiple[],int *multipleLen)
{
	int len=*multipleLen;
	int i=0;
	int carry=0;
	for (i = 0; i < Nlen; i++) {
		int temp = (multiple[i]+N[i] + carry);
		multiple[i] =temp%10; 
		carry = temp/10;
	}
	if(carry>0)
	{
		if(len == Nlen)
		{
			multiple[len++] = carry;
		}
		else {
			for(;i<len;i++)
			{
				int temp = multiple[i]+carry;
				multiple[i] = temp %10;
				carry = temp /10;
			}
			if(carry>0)
			{
				multiple[len++]=carry;
			}
		}
	}
	*multipleLen = len;
}
int main() {
	short int unsigned multiple[LISTSIZE];
	int multipleLen=0;
	init(multiple,&multipleLen);
	while(check(multiple,multipleLen)==0)
	{
		int i=0;
		for (i = multipleLen-1; i >= 0; i--) {
			printf("%d",multiple[i]);
		}
		printf("\n");
		add(multiple,&multipleLen);
		if(multipleLen>500)
			break;
	}
	FILE *fp;
	fp=fopen("multiple.out","w");
	if(multipleLen > 500)
	{
		fprintf(fp,"0");
	}
	else
	{
		int i=0;
		for (i = multipleLen-1; i >= 0; i--) 
		{
			printf("%d",multiple[i]);
			fprintf(fp,"%d",multiple[i]);
		}
	}
	fprintf(fp,"\n");
	printf("\n");
	fclose(fp);
	return 0;
}
