#include <stdio.h>
#define MAX 200
typedef struct
{
    int data;
    int rank;
} Data;
int main()
{
    Data datas[MAX];
    int numIndex[MAX];
    int distinctNum=0;
    int i=0;
    char ch;
    while(1)
    {
        scanf("%d%c",&datas[i].data,&ch);
        datas[i].rank=1;
        int j=0;
		for(j=0;j<i;j++)
			if(datas[i].data==datas[j].data)
			{
				datas[j]=datas[i];
				numIndex[distinctNum++]=j;
				continue;
			}
        for(j=0; j<i; j++)
        {
            if(datas[i].data < datas[j].data)
                datas[j].rank++;
            else if (datas[i].data > datas[j].data)
            {
                datas[i].rank++;
            }
        }
		numIndex[distinctNum++]=i;
		i++;

        if(ch=='\n')
            break;
    }
    for (i = 0; i < distinctNum; i++)
    {
        printf("%d ",datas[numIndex[i]].rank);
    }
    printf("\n");
    return 0;
}
