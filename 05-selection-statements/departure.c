#include <stdio.h>

#define NUM_FLIGHTS 8 
#define DEPART_HOUR departure[i] / 60 % 12 
#define DEPART_MINUTES departure[i] % 60
#define ARRIVE_HOUR arrival[i] / 60 % 12 
#define ARRIVE_MINUTES arrival[i] % 60

// prompts for a time in 24 hour format, then displays (in standard format) the departure and arrival times of the flight whose departure time is closest to the user input

int main(void) 
{
	int inputHour, inputMinutes, time, i;
	char departureMeridiem, arrivalMeridiem;
	printf("Enter a time (24 hour format xx:xx): ");
	scanf("%d:%d", &inputHour, &inputMinutes);
	time = inputHour * 60 + inputMinutes;
	int departure[NUM_FLIGHTS] = 
	{
		8 * 60 + 0,
		9 * 60 + 43,
		11 * 60 + 19,
		12 * 60 + 47,
		14 * 60 + 0,
		15 * 60 + 45,
		19 * 60 + 0,
		21 * 60 + 45
	};
	int arrival[NUM_FLIGHTS] =
	{
		10 * 60 + 16,
		11 * 60 + 52,
		13 * 60 + 31,
		15 * 60 + 0,
		16 * 60 + 8,
		17 * 60 + 55,
		21 * 60 + 20,
		23 * 60 + 58
	};
	for (i = 0; i < NUM_FLIGHTS; i++)
	{
		if (time < departure[0])
		{
			i = 0;
			departureMeridiem = 'a';
			arrivalMeridiem = 'a';
			goto print;
		}
		else if (time > departure[NUM_FLIGHTS - 1])
		{
			printf("There are no more departures scheduled for today\n");
			return 0;
		}
		else if (time >= departure[i] && time <= departure[i + 1])
		{
			departureMeridiem = (departure[i] < 720) ? 'a' : 'p';
			arrivalMeridiem = (arrival[i] < 720) ? 'a' : 'p';
			if (time - departure[i] < departure[i + 1] - time)
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
