#include <stdio.h>

// evaluates an expression of floats from left to right regardless of operator precedence. Possible operators are +, -, *, and

int main(void)
{
	char c;
	float value = 0;

	printf("Enter an expression: ");
	c = getchar();
	c -= 48;
	value += (float)c;
	printf("value: %f", value);
}
