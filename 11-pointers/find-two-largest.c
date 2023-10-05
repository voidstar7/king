#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void find_two_largest(int a[], int n, int *largest, int *second_largest);

int main(void)
{
	int i, largest, second_largest, n = 10, a[n];
	srand(time(NULL));
	for (i = 0; i < n; i++)
		a[i] = rand() % 100;
	for (i = 0; i < n; i++)
		printf("%d, ", a[i]);
	printf("\n");
	find_two_largest(a, n, &largest, &second_largest);
	printf("Largest: %d, Second largest: %d\n", largest, second_largest);
	return 0;
}

void find_two_largest(int a[], int n, int *largest, int *second_largest)
{
	int i, j, temp;
	for (i = 0; i < n; i++)
		for (j = i + 1; j < n; j++)
			if (a[j] < a[i])
			{
				temp = a[j];
				a[j] = a[i];
				a[i] = temp;
			}
	for (i = 0; i < n; i++)
		printf("%d, ", a[i]);
	printf("\n");
	*largest = a[n - 1];
	*second_largest = a[n - 2];
}
