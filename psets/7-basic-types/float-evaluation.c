#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

/* 
 * evaluates an expression of from left to right regardless of operator precedence. Possible operators are +, -, *, and /
 *
 * FLAGS:
 * 1 number
 * 2 decimal
 * 3 add
 * 4 subtract
 * 5 multiply
 * 6 divide
*/

int main(void)
{
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
			flag = 1;
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
			case 46: // decimal
				flag = 2; 
				scale++;
				break;
			case 43: // add
				flag = 3;
				scale = 0;
				break;
			case 45: // subtract
				flag = 4; 
				scale = 0;
				break;
			case 42: // multiply
				flag = 5; 
				scale = 0;
				break;
			case 47: // divide
				flag = 6;
				scale = 0;
				break;
			default:
				continue;
		}
	}
	if (flag == 1)
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
