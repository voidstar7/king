#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *find_largest(int a[], int n);

int main(void)
{
	const int len = 10;
	int i, *largest, nums[len];
	srand(time(NULL));
	for (i = 0; i < len; i++)
		nums[i] = rand() % 50 + 1;
	for (i = 0; i < len; i++)
		printf("%d ", nums[i]);
	printf("\n");
	largest = find_largest(nums, len);
	printf("largest: %d\n", *largest);
	return 0;
}

int *find_largest(int a[], int n)
{
	int i, j, temp;
	for (i = 0; i < n; i++)
		for (j = i + 1; j < n; j++)
			if (a[j] < a[i])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
	return &a[n - 1];
}
