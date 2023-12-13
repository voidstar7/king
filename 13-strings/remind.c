#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_REMIND 50 
#define MSG_LEN 60
	
int read_line(char str[], int n);
int get_day_time(
		char day_str[], 
		char msg_str[],
		int *hours,
		int *minutes
		);

int main(void)
{
	char 
		reminders[MAX_REMIND][MSG_LEN + 3], 
		day_str[3], 
		hours_str[4],
		minutes_str[3],
		day_hours_minutes_str[9],
		//15 23:30 msg goes here 
		msg_str[MSG_LEN + 1];
	int day, hours, minutes, i, j, 
			num_remind = 0,
			*ph = &hours,
			*pm = &minutes;

	for (;;) 
	{
		if (num_remind == MAX_REMIND) 
		{ 
			printf("-- No space left --\n"); 
			break;
		}
		day = get_day_time(day_str, msg_str, ph, pm);
		if (day == 0)
			break;
		if ((day < 0 || day > 31) ||
				(hours >= 24 || hours < 0) ||
				(minutes >= 60 || minutes < 0))
		{
			printf("Invalid input\n");
			continue;
		}
		sprintf(hours_str, " %02d", hours);
		sprintf(minutes_str, "%02d", minutes);
		strcpy(day_hours_minutes_str, day_str);
		strcat(day_hours_minutes_str, hours_str);
		strcat(day_hours_minutes_str, ":");
		strcat(day_hours_minutes_str, minutes_str);

		/*
		printf("%s\n", day_hours_minutes_str);
		printf("day_str: %s\n", day_str);
		printf("hours: %d\n", hours);
		printf("minutes: %d\n", minutes);
		printf("hours_str: %s\n", hours_str);
		printf("minutes_str: %s\n", minutes_str);
		*/

		for (i = 0; i < num_remind; i++)
			if (strcmp(day_hours_minutes_str, reminders[i]) < 0)
				break;
		for (j = num_remind; j > i; j--)
			strcpy(reminders[j], reminders[j - 1]);

		strcpy(reminders[i], day_hours_minutes_str);
		strcat(reminders[i], msg_str);
		
		//printf("%s\n", reminders[i]);
		//return 1;

		num_remind++;
	}

	printf("\nDay  Time Reminder\n");
	for (i = 0; i < num_remind; i++) 
		printf(" %s\n", reminders[i]);

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

int get_day_time(
		char day_str[],
		char msg_str[],
		int *ph,
		int *pm
		)
{
	int dayInput;

	printf("Enter day, time (24hr format), and reminder: ");
	scanf("%d", &dayInput);
	for (;;)
	{
		if (dayInput == 0)
			return dayInput;
		{
			scanf("%02d:%02d", ph, pm);
			sprintf(day_str, "%2d", dayInput);
			read_line(msg_str, MSG_LEN);
			break;
		}
	}
	return dayInput;
}

