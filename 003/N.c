#include <stdio.h>
#include <malloc.h>
#define MAXN 1000

//已知a中的(k-1)!,求k!
void PreNext(int a[],int k) 
{
	int *b,m = a[0],i,j,r,carry;
	b = (int*)malloc(sizeof(int)*(m+1));
	for(i = 1; i <= m; i++)  
		b[i] = a[i];
	for(j = 1; j < k; j++)   //控制累加k-1次
	{
		for(carry=0,i = 1;i <= m;i++)
		{
			r = (i <= a[0]?a[i]+b[i]:a[i])+carry; //计算加的结果
			a[i] = r % 10; //计算本位结果
			carry = r / 10; //计算进位数字
		}
		if(carry)  //向最高为进位
			a[++m] = carry;
	}
	free(b);
	a[0] = m;
}
void Print(int *a)
{
	int i;
	int m = 0;
	/*for(i = a[0]; i >0; i--){*/
	for(i = a[0]; i >0; i--){
		printf("%d",a[i]);
		m++;
		if(m % 5 == 0)             //每5个数字空一格   
			printf(" ");  
		if(40 == m)                //每行输出40个数字   
		{  
			printf("\n");  
			m = 0;          
		}
	}
	printf("\n");
}
int main()
{
	int a[MAXN],n,k;
	n = 1;
	printf("本程序计算任意位数的阶乘！\n");

	while(n){
		printf("请输入一个数：");
		scanf("%d",&n);
		a[0] = a[1] = 1;
		for(k = 2; k <= n; k++)
		{
			PreNext(a,k);		
			if(k == n)
				Print(a);
		}
	}
	return 0;
}
