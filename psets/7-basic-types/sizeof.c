#include <stdio.h>

int main(void)
{
	int i = sizeof(int); printf("int: %dB\n", i);
	int s = sizeof(short); printf("short: %dB\n", s);
	int l = sizeof(long); printf("long: %dB\n", l);
	int f = sizeof(float); printf("float: %dB\n", f);
	int d = sizeof(double); printf("double: %dB\n", d);
	int ld = sizeof(long double); printf("long double: %dB\n", ld);
	return 0;
}
