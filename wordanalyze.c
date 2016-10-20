/*方法：
<Z>::=<B>e
<B>::=<A>f
<A>::=e|<A>e
*/

#include <stdio.h>
#include <stdlib.h>
void error()
{
	printf("error\n");
	exit(0);
}
int main() {
	char ch='0';
	scanf("%c",&ch);
	if(ch!='e')
		error();
	else
	{
		while(1)
		{
			scanf("%c",&ch);
			if (ch=='e') 
				continue;
			else
				break;
		}
		if(ch!='f')
			error();
		scanf("%c",&ch);	
		if(ch!='e')
			error();
		printf("matching successful\n");
	}
	return 0;
}
