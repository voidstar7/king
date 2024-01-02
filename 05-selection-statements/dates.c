#include <stdio.h>

typedef struct { int day, month, year; } Date;

int total_days(Date d);

// prompts for calendar dates then returns the earliest one
int main(void)
{
	int count = 0;
	Date earliest = { 0, 0, 0 }, input;

	for (;;count++)
	{
		printf("Enter a date (mm/dd/yy) - 0/0/0 to stop: "); 
		scanf("%d/%d/%d", &input.month, &input.day, &input.year);

		if (total_days(input) == 0)
			break;

		if (count == 0 || total_days(input) < total_days(earliest))
			earliest = input;
	}
	printf("The earliest date is %d/%d/%d\n", earliest.month, earliest.day, earliest.year);
	return 0;
}

int total_days(Date d)
{
  int i, daysInYear = 0, daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (d.day == 0 && d.month == 0 && d.year == 0)
		return 0;

	for (i = 0; i < d.month; i++)
		daysInYear += daysInMonth[i];

	if (d.day != daysInMonth[d.month])
		daysInYear -= daysInMonth[d.month] - d.day;

	return daysInYear += (d.year * 365);
}
