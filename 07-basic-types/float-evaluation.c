#include <stdio.h>
#include <ctype.h>

// evaluates an expression of from left to right regardless of operator precedence. Possible operators are +, -, *, and /

int main(void)
{
	float f, value;
	char c;
	
	printf("Enter an expression: ");
	scanf("%f", &value);
	while (1)
	{
		scanf("%c", &c);
		if (c == '\x0a')
			break;
		scanf("%f", &f);
		if (c == '+')
		{
			value += f;
			continue;
		}
		else if (c == '-')
		{
			value -= f;
			continue;
		}
		else if (c == '*')
		{
			value *= f;
			continue;
		}
		else if (c == '/')
		{
			value /= f;
			continue;
		}
	}
	printf("Value of expression: %.1f\n", value);
	printf("Operands evaluated from left to right, regardless of precedence\n");
}
