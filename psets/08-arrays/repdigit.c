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
	printf("Digit:      ");
	for (int i = 0; i < 10; i++)
		printf("%2d ", i);
	printf("\n");
	printf("Occurences: ");
	for (int j = 0; j < 10; j++)
		printf("%2d ", digit_seen[j]);
	printf("\n");
	return 0;
}
