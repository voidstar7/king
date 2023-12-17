#include <stdio.h>

#define GENERIC_MAX(type) \
	type type##_max(type x, type y) \
	{ return x > y ? x : y; }

GENERIC_MAX(long);
GENERIC_MAX(float);

int main(void)
{
	printf("%ld", long_max(3, 2));
}
