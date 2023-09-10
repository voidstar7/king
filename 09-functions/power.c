#include <stdio.h>

int power(int x, int n);

int main(void)
{
	int x, n;
	printf("Enter a value for x: "); scanf("%d", &x);
	printf("Enter a value for n: "); scanf("%d", &n);
	printf("%d^%d = %d\n", x, n, power(x, n));
	return 0;
}

// x^n = x * x^n - 1
int power(int x, int n)
{
	if (n == 0)
		return 1;
	else
		return x * power(x, n - 1);
}
