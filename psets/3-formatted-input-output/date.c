#include <stdio.h>

// prompts for a date in mm/dd/yyyy format and outputs yyyymmdd

int main (void)
{
	int month, day, year;
	printf("Enter a date (mm/dd/yyyy): ");
	scanf(" %d / %d / %d", &month, &day, &year);
	printf("%d%d%d\n", year, month, day);
	return 0;
}
