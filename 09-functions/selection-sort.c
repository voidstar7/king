#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int selection_sort(int a[], int n);

int main(void)
{
  srand(time(NULL));
  int i, j, n = 20;
  int a[n];

	// initialize array
	for (i = 0; i < n; i++)
	{
		a[i] = rand() % 100;
		// a[i] = n - i;
		printf("%d ", a[i]);
	}
	printf("\n");

	selection_sort(a, n);

	// print sorted
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}

int selection_sort(int a[], int n)
{
	if (n == 1)
		return 1;
	int temp = 0;
	for (int i = 2; i <= n; i++)
	{
		if (a[n - i] < a[n - 1])
			continue;
		temp = a[n - 1];
		a[n - 1] = a[n - i];
		a[n - i] = temp;
	}
	return selection_sort(a, n - 1);
}

