#include <stdio.h>

// prompts for a two digit number, then prints the number reversed
int main(void)
{
	int first, second;
	printf("Enter a two digit number ");
	scanf("%1d%1d", &first, &second);
	printf("The reversal is: %d%d\n", second, first);
	return 0;
}
