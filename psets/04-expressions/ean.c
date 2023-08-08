#include <stdio.h>

// computes the check digit of a 13 digit EAN barcode

int main(void)
{
	long n; 
	int even, odd, check; 
	printf("Enter the first 12 digits of the EAN: ");
	scanf("%12lu", &n);

	odd = 0; even = 0;
	even += (n % 10); n /= 10;
	odd += (n % 10); n /= 10;
	even += (n % 10); n /= 10;
	odd += (n % 10); n /= 10;
	even += (n % 10); n /= 10;
	odd += (n % 10); n /= 10;
	even += (n % 10); n /= 10;
	odd += (n % 10); n /= 10;
	even += (n % 10); n /= 10;
	odd += (n % 10); n /= 10;
	even += (n % 10); n /= 10;
	odd += n;
	
	printf("The check digit is %d\n", 9 - ((((even * 3) + odd) - 1) % 10));
	return 0;
}
