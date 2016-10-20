#include <stdio.h>
#define MAX 200001
int main()
{
	int unsigned mark[MAX];
	int num[MAX];
	int i=0;
	int n=0;
	char ch;
	int len=0;
	for (i = 0; i < MAX; i++) {
		mark[i]=0;
	}
	while (1) {
		scanf("%d%c",&n,&ch);
		num[len++]=n;
		if(len>=MAX)
			break;
		mark[n]=1;
		if(ch=='\n')
			break;
	}
	int rank=1;
	for (i = 0; i < MAX; i++) {
		if(mark[i]!=0)
			mark[i]=rank++;
	}
	for (i = 0; i < len; i++) {
		printf("%d ",mark[num[i]]);
	}
	printf("\n");
	return 0;
}
