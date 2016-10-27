#include<stdio.h>
enum {MAX = 500};
char res[MAX];
int count[MAX];
void arrange(int k, char array[]);
void swap(char *a, char *b);
void insertSort(char array[]);
void record(char array[], int num[]);
int main()
{
	int i, n;
	char c;
	i = 0;
	while((c = getchar()) != '\n'){
		res[i] = c;
		i++;
	}
	res[i] = '\0';
	n = i;
	insertSort(res);
	arrange(n, res);
}

void arrange(int k, char array[]){
	int i = 0;
	int num = 0;
	if(k == 1){
		printf("%s", res);
		printf("\n");
		return;
	}
	
	
	while(i < k){
		record(&array[0], count);
		if(num >= 1 && count[num] == 0){
			return;
		}
		i = count[num];
		
		swap(&array[0], &array[i]);
		arrange(k - 1, &array[1]);
		swap(&array[i], &array[0]);
		num++;
	}
}

void record(char array[], int num[]){
	int i, k = 0;
	insertSort(array);
	num[k] = 0;
	for(i = 1;array[i] != '\0';i++){
		if(array[i] != array[0] && array[i] != array[i - 1])
			num[++k] = i;
	}
	num[++k] = 0;
}
void swap(char *a, char *b){
	char temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void insertSort(char array[]){
	int i, j;
	char temp;
	for (i = 0;array[i]!='\0' ; i++) {
		for(j = i+1; array[j]!='\0';j++)
		{
			if(array[j] < array[i])
			{
				temp = array[i];
				array[i] = array[j];
				array[j]= temp ; 
			}
		}
	}
}

