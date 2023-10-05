#include <stdio.h>
#include <stdbool.h>

void split_date(int day_of_year, int year, int *month, int *day);

int main(void)
{
	int day_of_year, year, month, day;
	printf("Enter the year: ");
		scanf("%d", &year);
	printf("Enter the day of the year: "); 
		scanf("%d", &day_of_year);
	if (day_of_year > 366)
	{
		printf("Invalid day of year\n");
		return 1;
	}
	split_date(day_of_year, year, &month, &day);
	printf("Month: %d\nDay: %d\n", month, day);
	return 0;
}

void split_date(int day_of_year, int year, int *month, int *day)
{
	int i, tempDays, monthCount = 0, daysInMonth[12];
	bool leap = false;

	// check if leap year
	if (year % 4)
	{
		if (year % 100 != 0)
			leap = true;
		else if (year % 400 != 0)
			leap = false;
	}

	// populate array with number of days per month 
	for (i = 0; i < 12; i++)
	{
		// Apr, Jun, Sep, Nov have 30 days
		if (i == 3 || i == 5 || i == 8 || i == 10)
			daysInMonth[i] = 30;
		else
			daysInMonth[i] = 31;
		// Feb has 28 or 29 days
		if (leap)
			daysInMonth[1] = 28;
		else
			daysInMonth[1] = 29;
	}

	// calculate day and month
	tempDays = day_of_year;
	for (i = 0; i < 12; i++)
	{
		if (tempDays > daysInMonth[i])
		{
			tempDays -= daysInMonth[i];
			monthCount++;
			continue;
		}
	}
	*day = tempDays;
	*month = monthCount + 1;
}
