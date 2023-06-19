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

	/* can be simplified to only use one variable and three lines of code
	 
  printf("Enter a three-digit number: ");
  scanf("%d", &n);
  printf("The reversal is: %d%d%d\n", n % 10, (n / 10) % 10, n / 100);

	*/
}
