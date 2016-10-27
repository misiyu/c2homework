#include <stdio.h>
#define MAX 5000

short int validNum[10];
short int validLen=0;
struct Node{
	short int num;
	short int remaindValue;
	short int path;
}Arr[MAX];
short int arrUsed=0;
char remaindMark[MAX];
short int n;


void init()
{
	FILE *fp = fopen("multiple.in","r");
	int temp[10];
	int i=0;
	for (i = 0; i < 10; i++)
		temp[i] = 0;
	for (i = 0; i < MAX; i++)
		remaindMark[i] = '0';
	fscanf(fp,"%hd",&n);
	int validTemp=0;
	while(fscanf(fp,"%d",&validTemp)!=EOF)
		temp[validTemp]=1;
	fclose(fp);
	for (i = 0; i < 10; i++)
		if(temp[i]!=0)
			validNum[validLen++]=i;
	Arr[0].num = 0;
	Arr[0].remaindValue = 0;
	Arr[0].path = 0;
	arrUsed++;
	for (i = 0; i < validLen; i++) {
		Arr[i+1].num = validNum[i];
		Arr[i+1].remaindValue = validNum[i]%n;
		Arr[i+1].path= 0 ;
		arrUsed++;
		if(validNum[i]!=0)
			remaindMark[validNum[i]] = '1';
	}
}

int findMul()
{
	int i=0;
	for (i = 1; i < arrUsed; i++) {
		if(Arr[i].num == 0 && i==1) // ==================little different
			continue;
		int j=0;
		while(j < validLen)
		{
			int newRemainder = (Arr[i].remaindValue*10+ validNum[j])%n;
			if(newRemainder == 0)
			{
				Arr[arrUsed].num = validNum[j];
				Arr[arrUsed].path = i;
				return 1;
			}
			else
			{
				if(remaindMark[newRemainder] == '0')
				{
					Arr[arrUsed].num = validNum[j];
					Arr[arrUsed].path = i;
					Arr[arrUsed].remaindValue = newRemainder;
					remaindMark[newRemainder]='1';
					arrUsed++;
				}
				j++;
			}
		}
	}
	return 0;
}

void output(int option)
{
	FILE *fp=fopen("multiple.out","w");
	if(option == 0)
		fprintf(fp, "0\n");
	else
	{
		int i= Arr[arrUsed].path;
		Arr[arrUsed].remaindValue = -1;
		while(i!=0)
        {
			Arr[i].remaindValue = -1;
            i= Arr[i].path;
        }
		for (i = 0; i <= arrUsed; i++) {
			if(Arr[i].remaindValue == -1)
				fprintf(fp, "%hd",Arr[i].num);
		}
		fprintf(fp,"\n");
	}
	fclose(fp);
}
int main() {

	init();
	int ret=0;
	ret = findMul();
	output(ret);
	return 0;
}
