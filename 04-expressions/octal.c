#include <stdio.h>

// prompts for an integer between 0 and 32767 and returns a 5 digit octal equivalent
int main(void)
{
	int number;
	printf("Enter a number between 0 and 32767: ");
	scanf("%d", &number);
	printf(
			"The octal equivalent of %d is %d%d%d%d%d\n", 
			number,
			(((((number / 8) / 8) / 8) / 8) % 8),
			((((number / 8 ) / 8) / 8) % 8), 
			(((number / 8) / 8) % 8), 
			((number / 8) % 8), 
			(number % 8) 
			);
	return 0;
}
