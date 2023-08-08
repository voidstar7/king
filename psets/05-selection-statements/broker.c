#include <stdio.h>

// calculates the commission paid to a broker according to the number and price of shares purchased. The minimum commission amount is $39. Displays the commission amount in comparison to the commission charged by a rival broker.

int main(void) {
	float v, c, p, tv; 
	int s;
	/*
	printf("Enter the number of shares: "); scanf("%d", &s);
	printf("Enter the price per share: "); scanf("%f", &p);
	v = s * p;
	*/

	do {
		printf("Enter a trade value (0 to stop): $"); 
		scanf("%f", &v);
		if (v == 0) {
			break;
		}
		else if (v < 2500.00f) {
			c = 39.00f;
			printf("Commission: $%.2f\n", c);
				continue;
		} else if (v >= 2500.00f) {
			c = 30.00f + (v * 0.017f);
			printf("Commission: $%.2f\n", c);
				continue;
		} else if (v >= 2500.00f && v < 6250.00f) {
			c = 56.00f + (v * 0.0066f);
			printf("Commission: $%.2f\n", c);
				continue;
		} else if (v >= 6250.00f && v < 20000.00f) {
			c = 76.00f + (v * 0.0034f);
			printf("Commission: $%.2f\n", c);
				continue;
		} else if (v >= 20000.00f && v < 50000.00f) {
			c = 100.00f + (v * 0.0022f);
			printf("Commission: $%.2f\n", c);
				continue;
		} else if (v >= 50000.00f && v < 500000.00f) {
			c = 155.00f + (v * 0.0011f);
			printf("Commission: $%.2f\n", c);
				continue;
		} else if (v > 500000.00f){
			c = 255.00f + (v * 0.0009f);
			printf("Commission: $%.2f\n", c);
		} 
	}
	while (v != 0);	

	/*
	if (v < 2500.00f) {
		c = 30.00f + (v * 0.017f);
	} else if (v >= 2500.00f && v < 6250.00f) {
		c = 56.00f + (v * 0.0066f);
	} else if (v >= 6250.00f && v < 20000.00f) {
		c = 76.00f + (v * 0.0034f);
	} else if (v >= 20000.00f && v < 50000.00f) {
		c = 100.00f + (v * 0.0022f);
	} else if (v >= 50000 && v < 500000) {
		c = 155.00f + (v * 0.0011f);
	} else {
		c = 255.00f + (v * 0.0009f);
	} 
	if (c < 39.00f) {
		c = 39.00f;
	}
	printf("Commission on $%.2f: $%.2f\n", v, c);
	*/

	/* competitor comparison
	float r;
	// $33.00 + $0.03 per share for fewer than 2000 shares
	// $33.00 + $0.02 per share for 2000 shares or more
	if (s < 2000) {
		r = 33.00f + (v * 0.03f);
	} else {
		r = 33.00f + (v * 0.02f);
	}
	printf("Commission on $%.2f (competitor): $%.2f\n", v, r);
	*/

	return 0;
}
