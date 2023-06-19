#include <stdio.h>

// prompts for a three digit number, then prints the number reversed
int main(void)
{
	int number, first, second, third;

	printf("Enter a three digit number: ");
	scanf("%3d", &number);

	third = number % 10;
	number = (number - third) / 10;
	second = number % 10;
	first = (number - second) / 10;

	printf("The reversal is: %d%d%d\n", third, second, first);

	return 0;
}
