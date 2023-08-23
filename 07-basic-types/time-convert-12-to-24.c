#include <stdio.h>
#include <ctype.h>

// prompts for the time in 12 hour format then prints the military time equivalent

int main(void)
{
	int hour, minute;
	char ap;
	printf("Enter the time (12 hour format <xx:xx>am/pm): ");
	scanf(" %d:%d %c", &hour, &minute, &ap);
	if (tolower(ap) == 97)
	{
		printf("Equivalent 24-hour time: 0%d:%d\n", hour, minute);
		return 0;
	}
	if (hour == 12)
	{
		printf("Equivalent 24-hour time: 12:%d\n", minute);
		return 0;
	}
	printf("Equivalent 24-hour time: %d:%d\n", hour + 12, minute);
	return 0;
}
