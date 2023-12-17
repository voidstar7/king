#include <stdio.h>
#include <math.h>

// returns 1 if both x and y fall between 0 and n - 1 inclusive
#define CHECK(x, y, n) \
	((x) > 0 && (y) > 0) && \
	((x) <= ((n) - 1)) && ((y) <= ((n) - 1)) \
	? 1 : 0

// returns the median of three numbers
#define MEDIAN(x, y, z) \
	(((y) > (x)) && ((y) < (z))) \
	? y : \
	(((x) > (y)) && ((x) < (z))) \
	? x : \
	(((z) > (x)) && ((z) < (y))) \
	? z : 0

// computes 3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6
#define POLYNOMIAL(x) \
	3 * (pow((x), 5)) + \
	2 * (pow((x), 4)) - \
	5 * (pow((x), 3)) - \
	pow((x), 2) + \
	((x) * 7) \
	- 6

int main(void)
{
	printf("%d\n", CHECK(51, 49, 100));
	printf("%d\n", MEDIAN(123, 81, 970));
	printf("%lf\n", POLYNOMIAL(4));
}
