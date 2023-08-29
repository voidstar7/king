#include <stdio.h>

int main(void)
{
	int n;
	printf("Enter size of magic square (odd number between 1 and 99): ");
	scanf("%d", &n);
	if (n % 2 == 0 || n < 0 || n > 99)
	{
		printf("Invalid input\n");
		return 1;
	}
		printf("valid input\n");
}
