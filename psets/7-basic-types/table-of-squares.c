#include <stdio.h>

int main(void)
{
	int n, i = 1;
	printf("Enter the number of entries of the table: ");
	scanf("%d", &n);
	while (i <= n) {
		printf("%10d%10d\n", i, i * i);
		i++;
	}
}
