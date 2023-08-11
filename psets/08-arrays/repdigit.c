#include <stdio.h>

int main(void)
{
	int digit_seen[10] = { 0 };
	int digit;
	long n;

	printf("Enter a number: ");
	scanf("%ld", &n);
	while (n > 0)
	{
		digit = n % 10;
		digit_seen[digit]++;
		n /= 10;
	}
	for (int i = 0; i < 10; i++)
	{
		if (digit_seen[i] > 1)
		{
			printf("Repeated digit(s): ");
			for (int j = 0; j < 10; j++)
			{
				if (digit_seen[j] > 1)
					printf("%d ", j);
			}
			printf("\n");
			return 0;
		}
	}
	printf("No repeated digits\n");
	return 0;
}
