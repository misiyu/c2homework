#include<stdio.h>

#define Listsize 1000000
int init();
int bornDead();

int m,n,p,k;
int cowNum[Listsize]={0};
int cowAge[Listsize]={0};

int main()
{
    init();
    bornDead();
}
int init()
{
    scanf("%d%d%d%d",&m,&n,&p,&k);
    /*if(!(1<m && m<n))*/
        /*return 1;*/
    /*if(!(n<p && p<60))*/
        /*return 1;*/
    /*int i=0;*/
    /*for (i = 0; i < Listsize; i++)*/
    /*{*/
        /*cowNum[i]=0;*/
        /*cowAge[i]=-1;*/
    /*}*/
    cowNum[0]=1;
    cowAge[0]=0;
    return 0;
}
int bornDead()
{
    int ListUsed=0;
    int i=0;
    int newBirth=0;
    for(i=1; i<=k; i++)
    {
        newBirth=0;
        int j=0;
        for(j=0; j<=ListUsed; j++)
        {
			if(cowAge[j]!=-1)
			{
				cowAge[j]++;
				if(cowAge[j]>=m&&cowAge[j]<=n)
					newBirth+=cowNum[j];
				else if(cowAge[j]>=p)
					cowAge[j]=-1;
			}
		}
		if(newBirth>0)
		{
			ListUsed++;
			cowNum[ListUsed] = newBirth;
			cowAge[ListUsed] = 0;
		}
	}
	int result=0;
	for(i=0; i<=ListUsed; i++)
		if(cowAge[i]!=-1)
			result+=cowNum[i];
	printf("%d\n",result);
	return 0;
}
