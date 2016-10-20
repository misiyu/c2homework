#include<stdio.h>

#define N 1000000

int main()
{
	int age[N] = {0}, num[N] = {0};
	int m, n, p, k, i, year, count, cow = 0, cow_birth;
	scanf("%d%d%d%d", &m, &n, &p, &k);

	age[0] = 0, num[0] = 1, count = 0;

	for(year = 1; year <= k; year++){
		cow_birth = 0;
		for(i = 0; i <= count; i++){
			if(age[i] != -1){
				age[i]++;
				if(age[i] >= m && age[i] <= n){
					cow_birth += num[i];

				}
				else if(age[i] >= p){
					age[i] = -1;

				}

			}

		}
		if(cow_birth > 0){
			count++;
			num[count] = cow_birth;

		}

	}

	for(i = 0; i <= count; i++){
		if(age[i] != -1){
			cow += num[i];

		}

	}
	printf("%d\n", cow);
	return 0;

}
