#include <stdio.h>

// calculates the volume of a sphere 
int main(void)
{
	// v = 4/3πr³
	printf("Enter the radius in meters: ");
	float r;
	scanf("%f", &r);
	float pi = 3.14159;
	float v = (4.0f / 3.0f) * pi * (r * r * r);
	printf("The volume of a sphere with a radius of %.2f meters is %.2f cubic meters\n", r, v);
	return 0;
}
