#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

// evaluates an expression of from left to right regardless of operator precedence. Possible operators are +, -, *, and /

int main(void)
{
	bool number, decimal;
	int flag = 0, scale = 0;
	float digit = 0.0f, value = 0.0f, oldNumber = 0.0f;
	char c;
	printf("Enter an expression: ");

input:
	while (1)
	{
		c = getchar();
		if (isdigit(c)) // number
		{
			number = true;
			flag = 0;
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
				decimal = true;
				scale++;
				break;
			case 43: // add
				flag = 1;
				scale = 0;
				oldNumber = digit;
				number = false;
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
	if (number)
	{
		if (scale == 1)
		{
			digit = (float)c - 48;
			goto input;
		}
		digit = (digit * 10) + ((float)c - 48);
		goto input;
	}
	if (flag)
	{
		if (flag == 1)
		{
			value = oldNumber + digit;
			goto input;
		}
		return 1;
	}
	return 1;

end:
		printf("Old number: %f\n", oldNumber);
		printf("Digit: %f\n", digit);
		printf("Value: %f\n", value);
		return 0;
}
