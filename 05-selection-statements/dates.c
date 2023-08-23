#include <stdio.h>

// prompts for calendar dates then returns the earliest one

int main(void) {
	int month, day, year, earlyMonth, earlyDay, earlyYear;
	printf("Enter a date (mm/dd/yy) - 0/0/0 to stop: "); scanf("%d/%d/%d", &month, &day, &year);
	if (month > 12 || day > 31 || year < 0) { 
			printf("Invalid entry\n");
			return 1;
	}
	else if (month == 0 && day == 0 && year == 0) { 
		goto zeroInit;
	}	
	else { 
		earlyMonth = month;
		earlyDay = day;
		earlyYear = year;
		while (1) {
			printf("Enter a date (mm/dd/yy) - 0/0/0 to stop: "); scanf("%d/%d/%d", &month, &day, &year);
			if (month > 12 || day > 31 || year < 0) { 
				printf("Invalid entry\n");
				return 1;
			}
			else if (month == 0 && day == 0 && year == 0) 
				break;
			else { 
				if (year < earlyYear) {
					earlyYear = year;
					earlyMonth = month;
					earlyDay = day;
					continue;
				}
				else if (year == earlyYear) { 
					if (month < earlyMonth) {
						earlyYear = year;
						earlyMonth = month;
						earlyDay = day;
						continue;
					}
					else if (month == earlyMonth) { 
						if (day < earlyDay) { 
							earlyYear = year;
							earlyMonth = month;
							earlyDay = day;
							continue;
						}
					}
				}
			}
		}	
	}	
	printf("Earliest date: %d/%d/%d\n", earlyMonth, earlyDay, earlyYear);
	return 0;

zeroInit:
	printf("Earliest date 0/0/0\n");
	return 2;
}
