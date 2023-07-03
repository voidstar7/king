#include <stdio.h>

// prompts for a time in 24 hour format, then displays (in standard format) the departure and arrival times of the flight whose departure time is closest to the user input

int main(void) {
	int a, b, c, d, e, f, g, h, 
			hour, minutes, time;
	printf("Enter a time (24 hour format xx:xx): ");
	scanf("%d:%d", &hour, &minutes);
	time = hour * 60 + minutes;

	// a | depart = 8:00am; arrive = 10:16am
	a = (8 * 60 + 0);
	// b | depart = 9:43am; arrive = 11:52am
	b = (9 * 60 + 43);
	// c | depart = 11:19a; arrive = 1:31pm
	c = (11 * 60 + 19);
	// d | depart = 12:47pm; arrive = 3:00pm
	d = (12 * 60 + 47);
	// e | depart = 2:00pm; arrive = 4:08pm
	e = (14 * 60 + 0);
	// f | depart = 3:45pm; arrive = 5:55pm
	f = (15 * 60 + 45);
	// g | depart = 7:00pm; arrive = 9:20pm
	g = (19 * 60 + 0);
	// h | depart = 9:45pm; arrive = 11:58pm
	h = (21 * 60 + 45);

	if (time < a) {
		printf("Closest departure time is 8:00am, arriving at 10:16am\n");
	}
	else if (time >= a && time < b) {
		if ((time - a) < (b - time)) 
			printf("Closest departure time is 8:00am, arriving at 10:16am\n");
		else
			printf("Closest departure time is 9:43am, arriving at 11:52am\n");
	}
	else if (time >= b && time < c) {
		if ((time - b) < (c - time)) 
			printf("Closest departure time is 9:43am, arriving at 11:52am\n");
		else
			printf("Closest departure time is 11:19am, arriving at 1:31pm\n");
	}
	else if (time >= c && time < d) {
		if ((time - c) < (d - time)) 
			printf("Closest departure time is 11:19am, arriving at 1:31pm\n");
		else
			printf("Closest departure time is 12:47pm, arriving at 3:00pm\n");
	}
	else if (time >= d && time < e) {
		if ((time - d) < (e - time)) 
			printf("Closest departure time is 12:47pm, arriving at 3:00pm\n");
		else
			printf("Closest departure time is 2:00pm, arriving at 4:08pm\n");
	}
	else if (time >= e && time < f) {
		if ((time - e) < (f - time)) 
			printf("Closest departure time is 2:00pm, arriving at 4:08pm\n");
		else
			printf("Closest departure time is 3:45pm, arriving at 5:55pm\n");
	}
	else if (time >= f && time < g) {
		if ((time - f) < (g - time)) 
			printf("Closest departure time is 3:45pm, arriving at 5:55pm\n");
		else
			printf("Closest departure time is 7:00pm, arriving at 9:20pm\n");
	}
	else if (time >= g && time <= h) {
		if ((time - g) < (h - time)) 
			printf("Closest departure time is 7:00pm, arriving at 9:20pm\n");
		else
			printf("Closest departure time is 9:45pm, arriving at 11:58pm\n");
	}
	else {
		printf("There are no more departures scheduled for today\n");
	}
}
