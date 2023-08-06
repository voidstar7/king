#include <stdio.h>
#include <stdbool.h>

// evaluates an expression of from left to right regardless of operator precedence. Possible operators are +, -, *, and /

int main(void)
{
	bool number, decimal, add, subtract, multiply, divide;
	int scale = 0;
	float value = 0.0f;
	printf("Enter an expression: ");

input:
	while (1)
	{
		char c = getchar();
		if (isdigit(c))
		{
			number = true;
			scale++;
			break;
		}
		switch (c)
		{
			case '10': 
				goto end;
			case '32': 
				continue;
			case '43':
				add = true;	
				break;
			case '45':
				subtract = true; 
				break;
			case '42':
				multiply = true; 
				break;
			case '47':
				divide = true;
				break;
			case '46':
				decimal = true; 
				break;
			default:
				continue;
		}

end:
		printf("Value of expression: ");
		return 0;
	}
}
