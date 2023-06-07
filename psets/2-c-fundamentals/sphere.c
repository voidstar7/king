#include <stdio.h>

// calculates the volume of a sphere with a 10 meter radius 
int main(void)
{
	// v = 4/3πr³
	float r = 10.0;
	float pie = 3.14159;
	float v = (4.0f / 3.0f) * (pie * (r * r * r));
	printf("The volume of a sphere with a radius of 10 meters is %.2f cubic meters\n", v);
	return 0;
}
