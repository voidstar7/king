#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_REMIND 50 
#define MSG_LEN 60
	
int read_line(char str[], int n);
int get_year_day_time(
		char msg_str[],
		int *year,
		int *day,
		int *hours,
		int *minutes
		);

int main(void)
{
	char 
		input,
		reminders[MAX_REMIND][MSG_LEN + 3], 
		msg_str[MSG_LEN + 1],
		year_str[5],
		day_str[4], 
		hours_str[4],
		minutes_str[3],
		year_day_hours_minutes_str[16];
		// 2023 15 23:30 msg goes here 

	int year, day, hours, minutes, i, j, 
			num_remind = 0,
			*py = &year,
			*pd = &day,
			*ph = &hours,
			*pm = &minutes;

	for (;;) 
	{
		if (num_remind == MAX_REMIND) 
		{ 
			printf("-- No space left --\n"); 
			break;
		}

		if (get_year_day_time(msg_str, py, pd, ph, pm) == 1)
			break;

		//printf("year: %d\nday: %d\nhours: %d\nminutes: %d\n", year, day, hours, minutes);
		if ((year < 0) ||
				(day < 0 || day > 31) ||
				(hours >= 24 || hours < 0) ||
				(minutes >= 60 || minutes < 0))
		{
			printf("Invalid input\n");
			continue;
		}
		sprintf(year_str, "%4d", year);
		//printf("%d\n", year);
		//return 1;

		sprintf(day_str, " %02d", day);
		sprintf(hours_str, " %02d", hours);
		sprintf(minutes_str, "%02d", minutes);
		strcpy(year_day_hours_minutes_str, year_str);
		strcat(year_day_hours_minutes_str, day_str);
		strcat(year_day_hours_minutes_str, hours_str);
		strcat(year_day_hours_minutes_str, ":");
		strcat(year_day_hours_minutes_str, minutes_str);

		//printf("%s\n", year_day_hours_minutes_str);
		//return 1;

		for (i = 0; i < num_remind; i++)
			if (strcmp(year_day_hours_minutes_str, reminders[i]) < 0)
				break;
		for (j = num_remind; j > i; j--)
			strcpy(reminders[j], reminders[j - 1]);

		strcpy(reminders[i], year_day_hours_minutes_str);
		strcat(reminders[i], msg_str);
		
		//printf("%s\n", reminders[i]);
		//return 1;

		num_remind++;
	}

	printf("\nYear Day  Time Reminder\n");
	for (i = 0; i < num_remind; i++) 
		printf(" %s\n", reminders[i]);

	/*
		Enter year, day, time (24hr format), and reminder: 2023 15 12:50 test
Enter year, day, time (24hr format), and reminder: 2023 15 12:49 test2
Enter year, day, time (24hr format), and reminder: 2023 15 12:48 test3
Enter year, day, time (24hr format), and reminder: 2023 15 11:51 test4
Enter year, day, time (24hr format), and reminder: 2020 4 10:30 test5
Enter year, day, time (24hr format), and reminder: 0

Year Day  Time Reminder
 2020 04 10:30 test5
 2023 15 11:51 test4
 2023 15 12:48 test3
 2023 15 12:49 test2
 2023 15 12:50 test
*/

	return 0;
}

int read_line(char str[], int n) 
{
	int ch, i = 0;
	
	while ((ch = getchar()) != '\n')
		if (i < n)
			str[i++] = ch;
	str[i] = '\0';
	return i;
}	

int get_year_day_time(
		char msg_str[],
		int *py,
		int *pd,
		int *ph,
		int *pm
		)
{
		printf("Enter year, day, time (24hr format), and reminder: ");
	scanf("%d", py);
	if (*py == 0)
		return 1;
	scanf("%2d %02d:%02d", pd, ph, pm);
	read_line(msg_str, MSG_LEN);
	return 0;
}

