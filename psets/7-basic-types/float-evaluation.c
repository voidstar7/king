#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

// evaluates an expression of from left to right regardless of operator precedence. Possible operators are +, -, *, and /

int main(void)
{
	bool number, decimal, add, subtract, multiply, divide;
	int scale = 0;
	float digit = 0.0f;
	float value = 0.0f;
	char c;
	printf("Enter an expression: ");

input:
	while (1)
	{
		c = getchar();
		if (isdigit(c))
		{
			number = true;
			scale++;
			break;
		}
		switch (c)
		{
			case 10: 
				goto end;
			case 32: 
				scale = 0;
				continue;
			case 43:
				add = true;	
				scale = 0;
				break;
			case 45:
				subtract = true; 
				scale = 0;
				break;
			case 42:
				multiply = true; 
				scale = 0;
				break;
			case 47:
				divide = true;
				scale = 0;
				break;
			case 46:
				decimal = true; 
				scale++;
				break;
			default:
				continue;
		}
	}
	if (number == true)
	{
		if (scale == 1)
		{
			digit = (float)c - 48;
			goto input;
		}
		digit = (digit * 10) + ((float)c - 48);
		goto input;
	}

end:
		printf("Value of expression: %f\n", digit);
		return 0;
}
