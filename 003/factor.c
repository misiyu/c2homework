#include <stdio.h>
#define MAXARR 1000
void addTimes(int result[],int times);
void output(int result[]);
int main()
{
    int result[MAXARR];
    int n=0;
    FILE *fp=fopen("factor.in","r");
    fscanf(fp,"%d",&n);
    fclose(fp);
    int i=0;
    result[0]=result[1]=1;
    for (i = 2; i <= n; i++)
    {
        addTimes(result,i);
    }
    output(result);
    return 0;
}

void output(int result[])
{
    int i=0;
    int j=0;
    FILE *fp=fopen("factor.out","w");
    for (i = result[0]; i > 0; i--)
    {
        printf("%d",result[i]);
        fprintf(fp,"%d",result[i]);
        j++;
        if(j%50==0)
            fprintf(fp,"\n");
    }
    fclose(fp);
}
void addTimes(int result[],int times)
{
    int i=0;
    int temp[MAXARR];
    int carry=0;
    int len=result[0];
    for(i=0; i<=result[0]; i++)
        temp[i]=result[i];
    for (i = 0; i < times-1; i++)
    {
        int j=0;
        carry=0;
        for (j = 1; j <=len; j++)
        {
            int temp1=0;
            if(j<=result[0])
                temp1=result[j]+temp[j]+carry;
            else
                temp1=result[j]+carry;
            result[j]=temp1%10;
            carry=temp1/10;
        }
        if(carry>0)
            result[++len]=carry;
    }
    result[0]=len;
}
