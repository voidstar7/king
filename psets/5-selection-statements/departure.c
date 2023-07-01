#include <stdio.h>

// prompts for a time in 24 hour format, then displays (in standard format) the departure and arrival times of the flight whose departure time is closest to the user input

int main(void) {
	int hour, minutes, conversion, 
			da, db, dc, dd, de, df, dg, dh,
			aa, ab, ac, ad, ae, af, ag, ah;
	printf("Enter a time (24 hour format xx:xx): ");
	scanf("%d:%d", &hour, &minutes);

		// da = 8:00am; aa = 10:16am
		// da = 8 * 60 + 0; aa = 10 * 60 + 16; 
		//
		// db = 9:43am; ab = 11:52am
		// db = 9 * 60 + 43; ab = 11 * 60 + 52;
		//
		// dc = 11:19a; ac = 1:31pm
		// dc = 11 * 60 + 19; ac = 1 * 60 + 31;
		//
		// dd = 12:47am; ad = 3:00pm
		// dd = 12 * 60 + 47; ad = 3 * 60 + 0;
		//
		// de = 2:00pm; ae = 4:08pm
		// de = 2 * 60 + 0; ae = 4 * 60 + 8;
		//
		// df = 3:45p; af = 5:55pm
		// df = 3 * 60 + 45; af = 5 * 60 + 55;
		//
		// dg = 7:00p; ag = 9:20pm
		// dg = 7 * 60 + 0; ag = 9 * 60 + 20;
		//
		// dh = 9:45p; ah = 11:58pm
		// dh = 9 * 60 + 45; ah = 11 * 60 + 58;

	printf("Closest departure time is %d, arriving at %d\n");
}
