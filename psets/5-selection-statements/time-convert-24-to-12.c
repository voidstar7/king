#include <stdio.h>

// prompts user for military time and converts to 12 hour form with am/pm
int main(void)
{
	int inHour, outHour, minutes;
	printf("Enter the time (24 hour format <xx:xx>): ");
	scanf("%2d:%2d", &inHour, &minutes);

	if (inHour < 12)
	{
		printf("The time is %d:%.2d am\n", inHour, minutes);
		return 0;
	}
	else if (inHour == 12)
	{
		printf("The time is %d:%.2d pm\n", inHour, minutes);
		return 0;
	}
	else if (inHour > 12 && inHour < 24)
	{
		outHour = inHour % 12;
		printf("The time is %d:%.2d pm\n", outHour, minutes);
		return 0;
	}
	else 
	{
		printf("Invalid input\n");
		return 1;
	}
}
