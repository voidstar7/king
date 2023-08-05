#include <stdio.h>

int main(void)
{
	int n, fact;
	printf("Enter a positive integer: ");
	scanf("%d", &n);
	fact = n;
	for (int i = 1; i < n; i++)
	{
		fact *= (n - i);
	}
	printf("Factorial of %d: %d\n", n, fact);
}
// !6 = 6 * 5 * 4 * 3 * 2 * 1
// 		= 30 * 4 * 3 * 2 * 1
// 		= 120 * 3 * 2 * 1
// 		= 360 * 2 * 1
// 		=	720 * 1 
// 		= 720
