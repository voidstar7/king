#include <stdio.h>
/* 
 * prompts for two integers and prints the greatest common divisor (GCD)
 *
 * Let m and n be variables containing the two numbers. 
 * If n is 0, then stop: m contains the GCD. 
 * Otherwise, compute the remainder when m is divided by n. 
 * Copy n into m and copy the remainder into n. 
 * Then repeat the process, starting with testing whether n is 0.
*/
int main(void) {
	int n, m, r;
	printf("Enter two integers: ");
	scanf("%d %d", &n, &m);
	for (; n > 0; n = r) {
		r = m % n;
		m = n;
	}
	printf("Greatest common divisor: %d\n", m);
}
