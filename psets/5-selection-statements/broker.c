#include <stdio.h>

// calculates the commission paid to a broker according to transaction size. The minimum commission amount is $39

int main(void) {
	float v, c;
	printf("Enter value of trade: ");
	scanf("%f", &v);

	if (v < 2500.00f) {
		c = 30.00f + (v * 0.017f);
	} else if (v > 2500.00f && v < 6250.00f) {
		c = 56.00f + (v * 0.066f);
	} else if (v > 6250.00f && v < 20000.00f) {
		c = 76.00f + (v * 0.034f);
	} else if (v > 20000.00f && v < 50000.00f) {
		c = 100.00f + (v * 0.022f);
	} else if (v > 50000 && v < 500000) {
		c = 155.00f + (v * 0.011f);
	} else {
		c = 255.00f + (v * 0.009f);
	} 
	if (c < 39.00f) {
		c = 39.00f;
	}
	printf("Commission: $%.2f\n", c);
	return 0;
}
