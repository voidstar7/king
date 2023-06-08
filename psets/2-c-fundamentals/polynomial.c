#include <stdio.h>

int main(void) 
{
	int x;
	printf("Enter a value for x: ");	
	scanf("%i", &x);
	x = ((3 * x) + 2) * (x - 5) * (x - 1) * (x + 7) * (x - 6);
	printf("((((3x + 2)x - 5)x - 1)x + 7)x - 6 = %i\n", x);
}
