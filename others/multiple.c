#include<stdio.h>
enum {LEN = 10000, MAX = 10};
int digit_num;
typedef struct node{
	int num, mod;
	int parent;
}NODE;
void output(FILE* out, NODE queue[], int n);
void insertSort(int array[], int n);
int main()
{	
	FILE *in, *out;
	NODE queue[LEN];
	int i = 0, j, k, p, n, rear = 0, digit[MAX];
	in = fopen("multiple.in", "r");
	out = fopen("multiple.out", "w");
	//in = stdin;
	//out = stdout;
	fscanf(in, "%d", &n);
	while(fscanf(in, "%d", &digit[i]) > 0){
		i++;
	}
	digit_num = i;
	insertSort(digit, digit_num);
	
	queue[0].num = 0;
	queue[0].mod = 0;
	queue[0].parent = 0;
	for(k = 1;k <= digit_num;k++){
		queue[k].num = digit[k - 1];
		queue[k].mod = digit[k - 1] % n;
		queue[k].parent = 0;
		rear++;
	}
	for(i = 1;i <= rear;i++){
		if(i == 1 && queue[i].num == 0)
			continue;
		j = 0;
		while(j < digit_num){
			if((queue[i].mod * 10 + digit[j]) % n == 0){
				queue[k].num = digit[j];
				queue[k].parent = i;
				output(out, queue, k);
				fprintf(out, "\n");
				return 0;
			}
			else{
				for(p = 0;p <= rear && (queue[i].mod * 10 + digit[j]) % n != queue[p].mod;p++)
					;
				if(p == rear + 1){
					queue[k].num = digit[j];
					queue[k].parent = i;
					queue[k].mod = (queue[i].mod * 10 + digit[j]) % n;
					k++;
					rear++;
				}
				j++;
			}
		}
	}
	fprintf(out, "0\n");
	fclose(in);
	fclose(out);
	return 0;
}

void output(FILE* out, NODE queue[], int n){
	if(n <= digit_num && n > 0){
		fprintf(out, "%d", queue[n].num);
	}
	else{
		output(out, queue, queue[n].parent);
		fprintf(out, "%d", queue[n].num);
	}
}

void insertSort(int array[], int n){
	int i, j;
	int temp;

	for(i = 0;i < n - 1;i++){
		temp = array[i + 1];
		for(j = i + 1;j > 0 && temp < array[j - 1];j--)
			array[j] = array[j - 1];
		array[j] = temp;
	}
}
