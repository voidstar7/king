#include <stdio.h>

// prompts the user to enter two dates, then tells them which one comes earlier\n on the calendar
int main(void) {
	int monthOne, dayOne, yearOne, monthTwo, dayTwo, yearTwo;
	printf("Enter first date (mm/dd/yy): "); scanf("%d/%d/%d", &monthOne, &dayOne, &yearOne);
	printf("Enter second date (mm/dd/yy): "); scanf("%d/%d/%d", &monthTwo, &dayTwo, &yearTwo);

	if (yearOne < yearTwo) 
		printf("date one is earlier\n");
	else if (yearOne > yearTwo) 
		printf("date two is earlier\n");
	else 
		if (monthOne < monthTwo)
			printf("date one is earlier\n");
		else if (monthOne > monthTwo)
			printf("date two is earlier\n");
		else 
			if (dayOne < dayTwo)
				printf("date one is earlier\n");
			else if (dayOne > dayTwo)
				printf("date two is earlier\n");
			else 
				printf("The dates are the same\n");
}
