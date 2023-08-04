#include <stdio.h>

int main(void)
{
	double x, z = 0.0;
	printf("Enter a positive number: ");
	scanf("%lf", &x);
	for (
			double y = 1.0; 
			x / y - y < 0.000001; 
			y = (x + (x / y)) / 2
			)
	{
		z = x / y;
	}
	printf("Square root: %lf\n", z);
	return 0;
}
