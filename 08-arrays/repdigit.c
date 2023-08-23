#include <stdio.h>

int main(void)
{
	int digit_seen[10] = { 0 };
	int digit;
	long n;

prompt:
	printf("Enter a number (0 to terminate): ");
	scanf("%ld", &n);
	if (n > 0)
	{
		while (n > 0)
		{
			digit = n % 10;
			digit_seen[digit]++;
			n /= 10;
		}
		printf("Digit:      ");
		for (int i = 0; i < 10; i++)
			printf("%2d ", i);
		printf("\n");
		printf("Occurences: ");
		for (int j = 0; j < 10; j++)
			printf("%2d ", digit_seen[j]);
		printf("\n");
		for (int k = 0; k < 10; k++)
			digit_seen[k] = 0;
		goto prompt;
	}
	return 0;
}
