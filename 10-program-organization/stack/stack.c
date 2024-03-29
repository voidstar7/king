#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "stack.h"

int main(void)
{
	char input = 0;
	printf("Enter parentheses and/or braces: ");
	while (input != '\x0a')
	{
		scanf("%c", &input);
		if (input == '{' || input == '(')
		{
			push(input);	
#ifdef DEBUG
			DEBUG_PUSH(input, top);
#endif
		}
		else if (input == '}')
		{
			if (pop() == '{')
			{
#ifdef DEBUG
				DEBUG_POP(contents[top], top);
#endif
				contents[top] = 0;
			}
		}
		else if (input == ')')
		{
			if (pop() == '(')
			{
#ifdef DEBUG
				DEBUG_POP(contents[top], top);
#endif
				contents[top] = 0;
			}
		}
	}
	if (!is_empty())
	{
		printf("Parentheses/braces are NOT nested correctly\n");
		return 0;
	}
	printf("Parentheses/braces are nested correctly\n");
	return 0;
}
