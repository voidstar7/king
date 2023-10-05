#include <stdio.h>
#include <stdlib.h>

void split_time (long total_sec, int *hr, int *min, int *sec);

int main(void)
{
	long total_sec;
	int hr, min, sec;
	printf("Enter the number of seconds since midnight: ");
	scanf("%ld", &total_sec);
	split_time(total_sec, &hr, &min, &sec);
	printf("It's been %d hours, %d minutes, %d seconds since midnight\n",hr, min, sec);
}

void split_time (long total_sec, int *hr, int *min, int *sec)
{
	int totalMinutes;
	if (total_sec > 86400)
	{
		printf("You entered more seconds than there are in a day\n");
		exit(1);
	}
	totalMinutes = total_sec / 60;
	*sec = total_sec % 60;
	*hr = totalMinutes / 60;
	*min = totalMinutes % 60;
}
