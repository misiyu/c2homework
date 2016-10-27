#include <stdio.h>
#include <string.h>
#define wordLen 1005
#define dotNum 26
int main() {

	int dotDegree[dotNum];
	char word[wordLen];
	int i=0;
	for (i = 0; i < dotNum; i++) {
		dotDegree[i]=0;
	}
	while(scanf("%s",word)!=EOF)
	{
		int len = strlen(word);
		dotDegree[word[0]-'a'] ++;
		dotDegree[word[len-1]-'a'] ++;
	}
	int oddAmount =0;
	for (i = 0; i < dotNum; i++) {
		if(dotDegree[i] % 2 != 0)
		{
			oddAmount ++;
			if(oddAmount > 2)
				break;
		}
		
	}
	if(oddAmount == 0|| oddAmount == 2)
		printf("yes\n");
	else
		printf("no\n");

	return 0;
}
