#include <stdio.h>

#define NUM_FLIGHTS 8 
#define DEPART_HOUR schedule[i].departure / 60 % 12 
#define DEPART_MINUTES schedule[i].departure % 60
#define ARRIVE_HOUR schedule[i].arrival / 60 % 12 
#define ARRIVE_MINUTES schedule[i].arrival % 60

typedef struct
{
	int departure;
	int arrival;
} Flights;

// prompts for a time in 24 hour format, then displays (in standard format) the departure and arrival times of the flight whose departure time is closest to the user input

int main(void) 
{
	int inputHour, inputMinutes, time, i;
	char departureMeridiem, arrivalMeridiem;

	printf("Enter a time (24 hour format xx:xx): ");
	scanf("%d:%d", &inputHour, &inputMinutes);
	time = inputHour * 60 + inputMinutes;

	Flights schedule[NUM_FLIGHTS] =
	{
			{8 * 60 + 0, 10 * 60 + 16},
			{9 * 60 + 43, 11 * 60 + 52},
			{11 * 60 + 19, 13 * 60 + 31},
			{12 * 60 + 47, 15 * 60 + 0},
			{14 * 60 + 0, 16 * 60 + 8},
			{15 * 60 + 45, 17 * 60 + 55},
			{19 * 60 + 0, 21 * 60 + 20},
			{21 * 60 + 45, 23 * 60 + 58}
	};

	for (i = 0; i < NUM_FLIGHTS; i++)
	{
		if (time < schedule[0].departure)
		{
			i = 0;
			departureMeridiem = 'a';
			arrivalMeridiem = 'a';
			goto print;
		}
		else if (time > schedule[NUM_FLIGHTS - 1].departure)
		{
			printf("There are no more departures scheduled for today\n");
			return 0;
		}
		else if (time >= schedule[i].departure && time <= schedule[i + 1].departure)
		{
			departureMeridiem = (schedule[i].departure < 720) ? 'a' : 'p';
			arrivalMeridiem = (schedule[i].arrival < 720) ? 'a' : 'p';
			if (time - schedule[i].departure < schedule[i + 1].departure - time)
			{
			print:
				if (DEPART_HOUR == 0)
				{
					printf("Closest departure time is 12:%.2d%cm, arriving at %d:%.2d%cm\n", 
							DEPART_MINUTES,
							departureMeridiem,
							ARRIVE_HOUR, 
							ARRIVE_MINUTES,
							arrivalMeridiem);
							return 0;
				}
				printf("Closest departure time is %d:%.2d%cm, arriving at %d:%.2d%cm\n", 
						DEPART_HOUR, 
						DEPART_MINUTES,
						departureMeridiem,
						ARRIVE_HOUR, 
						ARRIVE_MINUTES,
						arrivalMeridiem);
						return 0;
			}
			i++; 
			goto print;
		}
		continue;
	}
}
