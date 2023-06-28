#include <stdio.h>

// prompts for wind speed in knots and estimates the wind force according to the Beaufort scale
int main(void) {
	int speed;
	printf("Enter the wind speed in knots: "); scanf("%d", &speed);
	if (speed < 1)
		printf("Calm\n");
	else if (speed >= 1 && speed <= 3)
		printf("Light air\n");
	else if (speed >= 4 && speed <= 27)
		printf("Breeze\n");
	else if (speed >= 28 && speed <= 47)
		printf("Gale\n");
	else if (speed >= 48 && speed <= 63)
		printf("Storm\n");
	else 
		printf("Hurricane\n");
	return 0;
}
