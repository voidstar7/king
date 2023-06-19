#include <stdio.h>

// prompts for a two digit number, then prints the number reversed
int main(void)
{
	int number, first, second;

	printf("Enter a two digit number: ");
	scanf("%2d", &number);

	second = number % 10;
	first = (number - second) / 10;

	printf("The reversal is: %d%d\n", second, first);

	return 0;
}
