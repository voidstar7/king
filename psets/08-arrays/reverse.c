#include <stdio.h>
#define N 10

// reverses a series of numbers
int main(void)
{
	int a[N];
	int i; 
	printf("Enter %d numbers: ", N);
	for (i = 0; i < (int)(sizeof(a) / sizeof(a[0])); i++)
		scanf("%d", &a[i]);
	printf("In reverse order:");
	for (i = ((int)(sizeof(a) / sizeof(a[0]))) - 1; i >= 0; i--)
		printf(" %d", a[i]);
	printf("\n");
	return 0;
}
