#include <stdio.h>

int calculate(int base, int coefficient, int exponent);

int main(void)
{
	int x;
	printf("Enter a value for x: ");
	scanf("%d", &x);
	printf(
				"%d", 
				calculate(x, 3, 5) +
				calculate(x, 2, 4) -
				calculate(x, 5, 3) -
				calculate(x, 1, 2) +
				(x * 7) - 
				6
				);
	return 0;
}

// 3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6
int calculate(int base, int coefficient, int exponent)
{
	int i, result = base;
	for (i = 0; i < exponent - 1; i++)
	{
		result *= base;
		//printf("%d\n", result);
	}
	return result * coefficient;
	//printf("%d\n", result * coefficient);
}
