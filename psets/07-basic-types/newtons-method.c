#include <stdio.h>
#include <math.h>

int main(void)
{
	double x, y = 1.0;
	printf("Enter a positive number: ");
	scanf("%lf", &x);
	while (fabs((((x / y) + y)) / 2 - y) > .00001)
	{
		y = ((x / y) + y) / 2;
	}
	printf("Square root: %.5lf\n", y);
	return 0;
}
