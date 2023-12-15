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
		year_day_hours_minutes_str[17];

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

		if ((year < 0) ||
				(day < 0 || day > 31) ||
				(hours >= 24 || hours < 0) ||
				(minutes >= 60 || minutes < 0))
		{
			printf("Invalid input\n");
			continue;
		}

		sprintf(year_day_hours_minutes_str, "%4d   %2d %02d:%02d ",
				year,
				day,
				hours,
				minutes);

		for (i = 0; i < num_remind; i++)
			if (strcmp(year_day_hours_minutes_str, reminders[i]) < 0)
				break;
		for (j = num_remind; j > i; j--)
			strcpy(reminders[j], reminders[j - 1]);

		strcpy(reminders[i], year_day_hours_minutes_str);
		strcat(reminders[i], msg_str);
		
		num_remind++;
	}

	printf("\nYear  Day  Time  Reminder\n");
	for (i = 0; i < num_remind; i++) 
		printf("%s\n", reminders[i]);
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

