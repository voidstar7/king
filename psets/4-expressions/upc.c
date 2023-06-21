#include <stdio.h>

// computes the check digit of a 12 digit UPC barcode

int main(void)
{
	int type, manufacturer, product; 
	printf("Enter the first 11 digits of the UPC: ");
	scanf("%1d%5d%5d", &type, &manufacturer, &product);

	int odd = 0; odd += type;
	int even = 0;

	even += (manufacturer % 10); manufacturer /= 10;
	odd += (manufacturer % 10); manufacturer /= 10;
	even += (manufacturer % 10); manufacturer /= 10;
	odd += (manufacturer % 10); manufacturer /= 10;
	even += (manufacturer % 10); manufacturer /= 10;
	even += (product % 10); product /= 10;
	odd += (product % 10); product /= 10;
	even += (product % 10); product /= 10;
	odd += (product % 10); product /= 10;
	even += (product % 10); product /= 10;
	
	printf("The check digit is %d\n", 9 - ((((odd * 3) + even) - 1) % 10));
	return 0;
}
