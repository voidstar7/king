#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

// evaluates an expression of from left to right regardless of operator precedence. Possible operators are +, -, *, and /

int main(void)
{
	bool NUMBER, DECIMAL;
	int flag = 0, scale = 0;
	float digit = 0.0f;
	float value = 0.0f;
	char c;
	printf("Enter an expression: ");

input:
	while (1)
	{
		c = getchar();
		if (isdigit(c)) // number
		{
			NUMBER = true;
			scale++;
			break;
		}
		switch (c)
		{
			case 10: // return
				goto end;
			case 32: // space
				scale = 0; 
				continue;
			case 46: // decimal
				DECIMAL = true;
				scale++;
				break;
			case 43: // add
				flag = 1;
				scale = 0;
				break;
			case 45: // subtract
				flag = 2; 
				scale = 0;
				break;
			case 42: // multiply
				flag = 3; 
				scale = 0;
				break;
			case 47: // divide
				flag = 4;
				scale = 0;
				break;
			default:
				continue;
		}
	}
	if (NUMBER)
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
