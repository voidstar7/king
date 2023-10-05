#include <stdio.h>

void swap(int *p, int *q);

int main(void)
{
	int i = 2, j = 3;
	printf("i is %d, j is %d\n", i, j);
	swap(&i, &j);
	printf("i is %d, j is %d\n", i, j);
}

void swap(int *p, int *q)
{
	int temp;
	temp = *p;
	*p = *q;
	*q = temp;
}
