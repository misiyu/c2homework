#include <stdio.h>
#include <string.h>
#define MAX 200
void removeBlank(char str[])
{
	int i =0;
	int j=0;
	int len = strlen(str);
	for (i = 0; i < len; i++) {
		if(str[i]!=' ')
			str[j++]=str[i];
	}
	while(j<len)
		str[j++]='\0';
}
int main() {

	char formulor[MAX];
	fgets(formulor,MAX,stdin);
	removeBlank(formulor);
	puts(formulor);
	long double num1=0;
	long double num2=0;
	char op='-';
	sscanf(formulor,"%Lf",&num1);
	printf("%Lf\n",num1);
	int len= strlen(formulor);
	int opNum=0;
	int i=0;
	for (i = 0; i < len; i++) {
		if(formulor[i]=='+'||formulor[i]=='-'||formulor[i]=='/'||formulor[i]=='*')
			opNum++;
	}
	for (i = 0; i < opNum; i++) {
		sscanf(formulor,"%c%Lf",&op,&num2);
		if(op=='+')
			num1 += num2;
		else if (op=='-') {
			num1-=num2;
		}
		else if (op=='*') {
			num1*=num2;
		}
		else if (op=='/') {
			num1/=num2;
		}
	}
	char result[MAX];
	sprintf(result,"%LF",num1);
	puts(result);
	return 0;
}
