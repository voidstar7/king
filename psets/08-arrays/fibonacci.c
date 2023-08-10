#include <stdio.h>
#define length 40

// prints the fibonacci sequence 
int main(void)
{
	int fib[length];
	int a = 0, b = 1;
	for (int i = 0; i < length - 2; i++)
	{
		int c = a + b;
		a = b;
		b = c;
		printf("%d ", c);
	}
	return 0;
}
