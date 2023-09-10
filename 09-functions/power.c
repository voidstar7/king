#include <stdio.h>

int power_even(int x, int n);
int power_odd(int x, int n);

int main(void)
{
	int x, n;
	printf("Enter a value for x: "); scanf("%d", &x);
	printf("Enter a value for n: "); scanf("%d", &n);
	if (n % 2 == 1)
	{
		printf("%d^%d = %d\n", x, n, power_odd(x, n));
		return 0;
	}
	printf("%d^%d = %d\n", x, n, power_even(x, n));
	return 0;
}

// if n is odd: x^n = x * x^n-1
int power_odd(int x, int n)
{
	if (n == 0)
		return 1;
	else 
		return x * power_odd(x, n - 1);
}

// if n is even: x^n = (x^n/2)^2
int power_even(int x, int n)
{
	if (n == 0)
		return 1;
	else
	{
		int y = power_odd(x, n / 2);
		return y * y;
	}
}
