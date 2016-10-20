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
int changeSscaP(int p,char str[])
{
	while(1)
	{
		p++;
		if(str[p]=='+'||str[p]=='-'||str[p]=='/'||str[p]=='*')
			break;
	}
	return p;
}
int main() {

	char formulor[MAX];
	fgets(formulor,MAX,stdin);
	removeBlank(formulor);
	/*puts(formulor);*/
	long double num1=0;
	long double num2=0;
	char op='-';
	sscanf(formulor,"%Lf",&num1);
	int ssaP=0;
	ssaP=changeSscaP(ssaP,formulor);
	/*printf("%Lf\n",num1);*/
	int len= strlen(formulor);
	int opNum=0;
	int i=0;
	for (i = 0; i < len; i++) {
		if(formulor[i]=='+'||formulor[i]=='-'||formulor[i]=='/'||formulor[i]=='*')
			opNum++;
	}
	for (i = 0; i < opNum; i++) {
		sscanf(formulor+ssaP,"%c%Lf",&op,&num2);
		ssaP=changeSscaP(ssaP+1,formulor);
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
	sprintf(result,"%.9LF",num1);
	len = strlen(result);
	for (i = len-1; i > 0; i--) {
		if (result[i]>'0'&&result[i]<='9') {
			break;
		}
		result[i]='\0';
	}
	puts(result);
	return 0;
}
