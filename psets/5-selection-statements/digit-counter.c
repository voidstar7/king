#include <stdio.h>

// calculates the number of digits in a number of up to 4 digits
int main(void)
{
	int i;
	printf("Enter a number (max 4 digits): "); scanf("%d", &i);
	if (i >= 0 && i < 10)
	{
		printf("%d is 1 digit long\n", i);
	}
	else if (i >= 10 && i < 100)
	{
		printf("%d is 2 digits long\n", i);
	}
	else if (i >= 100 && i < 1000)
	{
		printf("%d is 3 digits long\n", i);
	}
	else if (i >= 1000 && i < 10000)
	{
		printf("%d is 4 digits long\n", i);
	}
	return 0;
}
