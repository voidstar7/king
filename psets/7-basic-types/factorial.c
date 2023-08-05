#include <stdio.h>

int main(void)
{
	long n, fact;
	printf("Enter a positive integer: ");
	scanf("%ld", &n);
	fact = n;
	for (int i = 1; i < n; i++)
	{
		fact *= (n - i);
	}
	printf("Factorial of %ld: %ld\n", n, fact);
}
// !6 = 6 * 5 * 4 * 3 * 2 * 1
// 		= 30 * 4 * 3 * 2 * 1
// 		= 120 * 3 * 2 * 1
// 		= 360 * 2 * 1
// 		=	720 * 1 
// 		= 720
