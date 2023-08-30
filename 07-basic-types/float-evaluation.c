#include <stdio.h>
#include <ctype.h>

// INCOMPLETE

// evaluates an expression of from left to right regardless of operator precedence. Possible operators are +, -, *, and /

int main(void)
{
	int i;
	char c;
	int value = 0;
	
	printf("Enter an expression: ");
	while (1)
	{
		scanf("%d", &i);
		value += i;
		c = getchar();
		if (c == 10)
			break;
	}
	printf("%d", value);
}
