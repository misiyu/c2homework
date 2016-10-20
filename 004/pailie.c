#include <stdio.h>
int n=0;
int m=0;
int choose[10]; 
int getchoose()
{
	/*if(choose[m-1] < n)*/
	/*{*/
		/*choose[m-1]++;*/
		/*return 1;*/
	/*}*/
	/*else*/
	int i=0;
	for (i = m-1; i >=0 ; i--) {
		if(choose[i]+1 <= n -(m-1-i))
		{
			choose[i]++;
			break;
		}
	}
	if(i < 0)
	{
		return 0;
	}
	else
	{
		for (i++; i < m; i++) 
			choose[i] = choose[i-1]+1;
		return 1;
	}
}
void init()
{
	scanf("%d%d",&n,&m);
	int i=0;
	for(i = 0;i< m;i++)
		choose[i] = i+1;
}
int main() {
	init();
	while(1)
	{
		int i=0;
		for (i = 0; i < m; i++) {
			printf("%d ",choose[i]);
		}
		printf( "\n");
		if(getchoose()==0)
			break;
	}
	return 0;
}
