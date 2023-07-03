#include <stdio.h>

// prompts for a time in 24 hour format, then displays (in standard format) the departure and arrival times of the flight whose departure time is closest to the user input

int main(void) {
	int hour, minutes, conversion, 
			da, db, dc, dd, de, df, dg, dh,
			ca, cb, cc, cd, ce, cf, cg, ch,
			hda, hdb, hdc, hdd, hde, hdf, hdg, hdh,
			mda, mdb, mdc, mdd, mde, mdf, mdg, mdh,
			haa, hab, hac, had, hae, haf, hag, hah,
			maa, mab, mac, mad, mae, maf, mag, mah,
	departHour, departMinutes,
	arriveHour, arriveMinutes;

	printf("Enter a time (24 hour format xx:xx): ");
	scanf("%d:%d", &hour, &minutes);
	conversion = hour * 60 + minutes;

	// depart = 8:00am; arrive = 10:16am
		 da = 8 * 60 + 0; 
		 ca = conversion - da;
		 hda = 8; mda = 0;
		 haa = 10; maa = 16; 

	// depart = 9:43am; arrive = 11:52am
		 db = 9 * 60 + 43;
		 cb = conversion - db;
		 hdb = 9; mdb = 43;
		 hab = 11; mab = 52;
		 
	// depart = 11:19a; arrive = 1:31pm
		 dc = 11 * 60 + 19;
		 cc = conversion - dc;
		 hdc = 11; mdc = 19;
		 hac = 1; mac = 31;

	// depart = 12:47pm; arrive = 3:00pm
		 dd = 12 * 60 + 47;
		 cd = conversion - dd;
		 hdd = 12; mdd = 47;
		 had = 3; mad = 0;

	// depart = 2:00pm; arrive = 4:08pm
		 de = 14 * 60 + 0;
		 ce = conversion - de;
		 hde = 2; mde = 0;
		 hae = 4; mae = 8;

	// depart = 3:45pm; arrive = 5:55pm
		 df = 15 * 60 + 45;
		 cf = conversion - df;
		 hdf = 3; mdf = 45;
		 haf = 5; maf = 55;

	// depart = 7:00pm; arrive = 9:20pm
		 dg = 19 * 60 + 0;
		 cg = conversion - dg;
		 hdg = 7; mdg = 0;
		 hag = 9; mag = 20;
		 
	// depart = 9:45pm; arrive = 11:58pm
		 dh = 21 * 60 + 45;
		 ch = conversion - dh;
		 hdh = 9; mdh = 45;
		 hah = 11; mah = 58;

	if (ca < cb && ca < cc && ca < cd && ca < ce && ca < cf && ca < cg && ca < ch) {
		departHour = hda; departMinutes = mda;
		arriveHour = haa; arriveMinutes = maa;
	}
	else if (cb < ca && cb < cc && cb < cd && cb < ce && cb < cf && cb < cg && cb < ch) {
		departHour = hdb; departMinutes = mdb;
		arriveHour = hab; arriveMinutes = mab;
	}
	else if (cc < cb && cc < ca && cc < cd && cc < ce && cc < cf && cc < cg && cc < ch) {
		departHour = hdc; departMinutes = mdc;
		arriveHour = hac; arriveMinutes = mac;
	}
	else if (cd < cb && cd < cc && cd < ca && cd < ce && cd < cf && cd < cg && cd < ch) {
		departHour = hdd; departMinutes = mdd;
		arriveHour = had; arriveMinutes = mad;
	}
	else if (ce < cb && ce < cc && ce < cd && ce < ca && ce < cf && ce < cg && ce < ch) {
		departHour = hde; departMinutes = mde;
		arriveHour = hae; arriveMinutes = mae;
	}
	else if (cf < cb && cf < cc && cf < cd && cf < ce && cf < ca && cf < cg && cf < ch) {
		departHour = hdf; departMinutes = mdf;
		arriveHour = haf; arriveMinutes = maf;
	}
	else if (cg < cb && cg < cc && cg < cd && cg < ce && cg < cf && cg < ca && cg < ch) {
		departHour = hdg; departMinutes = mdg;
		arriveHour = hag; arriveMinutes = mag;
	}
	else if (ch	< cb && ch < cc && ch < cd && ch < ce && ch < cf && ch < cg && ch < ca) {
		departHour = hdh; departMinutes = mdh;
		arriveHour = hah; arriveMinutes = mah;
	}
	else {
		printf("Error\n");
		return 1;
	} 

	if (departHour < (12 * 60) && arriveHour < (12 * 60)) {
		printf("Closest departure time is %d:%.2dam, arriving at %d:%2dam\n", 
				departHour, departMinutes, arriveHour, arriveMinutes);
	}
	else if (departHour > (12 * 60) && arriveHour > (12 * 60)) {
		printf("Closest departure time is %d:%.2dpm, arriving at %d:%2dpm\n", 
				departHour, departMinutes, arriveHour, arriveMinutes);
	}
	else {
		printf("Closest departure time is %d:%.2dam, arriving at %d:%2dpm\n", 
				departHour, departMinutes, arriveHour, arriveMinutes);
	}
	return 0;
}
