#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_REMIND 50 
#define MSG_LEN 60
	
int read_line(char str[], int n);
int get_day_time(
		char day_str[], 
		char time_str[], 
		char msg_str[],
		int *hours,
		int *minutes
		);

int main(void)
{
	char 
		reminders[MAX_REMIND][MSG_LEN + 3], 
		day_str[3], 
		time_str[6],
		msg_str[MSG_LEN + 1];
	int day, hours, minutes, i, j, num_remind = 0,
			*ph = &hours,
			*pm = &minutes;

	for (;;) 
	{
		if (num_remind == MAX_REMIND) 
		{ 
			printf("-- No space left --\n"); 
			break;
		}
		 
		day = get_day_time(day_str, time_str, msg_str, ph, pm);
		if (day == 0)
			break;
		if ((day < 0 || day > 31) ||
				(hours >= 24 || hours < 0) ||
				(minutes >= 60 || minutes < 0))
		{
			printf("Invalid input\n");
			continue;
		}
		// debug statements
		printf("day = %d\n", day);
		printf("hours = %d\n", hours);
		printf("minutes = %d\n", minutes);
		// how to persist the 0s with time input like 05:03?why are only the last 2 digits being saved in time_str?
		printf("%s\n", time_str);
		return 1;

		for (i = 0; i < num_remind; i++)
			if (strcmp(day_str, reminders[i]) < 0)
				break;
		for (j = num_remind; j > i; j--)
			strcpy(reminders[j], reminders[j - 1]);

		strcpy(reminders[i], day_str);
		strcat(reminders[i], msg_str);

		num_remind++;
	}

	printf("\nDay Time Reminder\n");
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
		char time_str[], 
		char msg_str[],
		int *ph,
		int *pm
		)
{
	int dayInput;

	printf("Enter day, time (24hr format), and reminder: ");
	scanf("%d %02d:%02d", &dayInput, ph, pm);

	sprintf(day_str, "%2d", dayInput);

	if (*ph < 10)
		sprintf(time_str, "0%d:", *ph);
	else
		sprintf(time_str, "%2d:", *ph);

	if (*pm < 10)
		sprintf(time_str, "0%d", *pm);
	else
		sprintf(time_str, "%2d", *pm);

	read_line(msg_str, MSG_LEN);
	return dayInput;
}

