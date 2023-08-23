#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DAYS 30
#define HOURS 24

int main(void)
{
	// generates random temperatures for each hour for the day over the course of a month
	srand(time(NULL));
	int temperature_readings[DAYS][HOURS];
	for (int i = 0; i < DAYS; i++)
	{
		for (int j = 0; j < HOURS; j++)
		{
			temperature_readings[i][j] = (rand() % 32) - 3;
		}
	}

	// prints the data and average temperature
	int day = 1;
	int sum = 0;
	for (int i = 0; i < DAYS; i++)
	{
		printf("Day %d:  ", day);
		for (int j = 0; j < HOURS; j++)
		{
			sum += temperature_readings[i][j];
			printf("%2d ", temperature_readings[i][j]);
		}
		printf("\n");
		day++;
	}
	printf("Average temperature: %d\n", sum / (DAYS * HOURS));
	return 0;
}
