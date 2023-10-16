#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 2 

int sum_two_dimensional_array(const int a[][LEN], int n);

int main(void)
{
	//srand(time(NULL));
	int i, j, n = 5;
	int a[n][LEN];
	for (i = 0; i < n; i++)
		for (j = 0; j < LEN; j++)
			a[i][j] = rand() % 10 + 1;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < LEN; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
	printf("Sum is %d\n", sum_two_dimensional_array(a, n));
}

int sum_two_dimensional_array(const int a[][LEN], int n)
{
	const int *p; 
	int sum = 0;
	for (p = &a[0][0]; p < &a[0][0] + (n * LEN); p++)
		sum += *p;
	return sum;
}
