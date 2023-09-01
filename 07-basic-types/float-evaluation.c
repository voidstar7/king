#include <stdio.h>
#include <ctype.h>

// INCOMPLETE

// evaluates an expression of from left to right regardless of operator precedence. Possible operators are +, -, *, and /

int main(void)
{
	int i;
	char c;
	int value;
	
	printf("Enter an expression: ");
	scanf("%d", &value);
	while (1)
	{
		scanf("%c", &c);
		if (c == '\x0a')
			break;
		scanf("%d", &i);
		if (c == '+')
		{
			value += i;
			continue;
		}
		else if (c == '-')
		{
			value -= i;
			continue;
		}
		else if (c == '*')
		{
			value *= i;
			continue;
		}
		else if (c == '/')
		{
			value /= i;
			continue;
		}
	}
	printf("Value of expression: %d", value);
}
