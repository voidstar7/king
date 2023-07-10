#include <stdio.h>

// prompts the user for a fraction then reduces it to its lowest terms
int main(void) {
	int num, den, n, d, r;
	printf("Enter a fraction: ");
	scanf(" %d / %d", &n, &d);
	num = n; den = d;
	// compute gcd of num and den
	for (; n > 0; n = r) {
		r = d % n;
		d = n;
	}
	// divide both num and den by gcd
	printf("Lowest terms: %d/%d\n", num / d, den / d);
}
