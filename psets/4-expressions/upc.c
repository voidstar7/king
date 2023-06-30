#include <stdio.h>

// computes the check digit of a 12 digit UPC barcode
// example: 0 13800 15173 5
int main(void)
{
	int type, manufacturer, product, check, checksum; 
	int odd = 0; 
	int even = 0;
	printf("Enter the UPC: ");
	scanf("%1d %5d %5d %1d", &type, &manufacturer, &product, &check);
		odd += type;
		even += (manufacturer % 10); manufacturer /= 10;
		odd += (manufacturer % 10); manufacturer /= 10;
		even += (manufacturer % 10); manufacturer /= 10;
		odd += (manufacturer % 10); manufacturer /= 10;
		even += (manufacturer % 10); manufacturer /= 10;
		odd += (product % 10); product /= 10;
		even += (product % 10); product /= 10;
		odd += (product % 10); product /= 10;
		even += (product % 10); product /= 10;
		odd += (product % 10); product /= 10;

	checksum = 9 - ((((odd * 3) + even) - 1) % 10);
	if (check == checksum) {
		printf("VALID\n");
		return 0;
	}	
	printf("INVALID\n");
	return 1;
}
