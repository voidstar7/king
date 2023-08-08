#include <stdio.h>

// prompts for the number days in the month and the day of the week that the month begins on, then prints a calendar
 
int main(void) {
	int days, startDay;
	printf("Enter number of days in month: "); 
	scanf("%d", &days);
	printf("Enter starting day of the week (1=Sun, 7=Sat): ");
	scanf("%d", &startDay);

	for (int i = 0; i < startDay - 1; i++) {
		printf("   ");
	}
	int wrap = 7 - (startDay - 1);
	for (int j = 1; j <= days; j++) {
		if (j == wrap) {
			printf("%3d\n", j);
			wrap += 7;
		}
		else
			printf("%3d", j);
	} 
	printf("\n");
	return 0;
}
