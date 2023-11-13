#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define STACK_SIZE 50
//#define debug

// a RPC calculator that accepts single digit operands

bool is_empty(void);
bool is_full(void);
void push(int i);
int pop(void);
int evaluate_expression(const char *expression);
void print_stack(void);

int stack[STACK_SIZE];
char input[STACK_SIZE * 2];

int top = 0;

int main(void)
{
	printf(">>> ");
	fgets(input, STACK_SIZE * 2, stdin);
	printf("%d\n", evaluate_expression(input));
}

int evaluate_expression(const char *expression)
{
	char *p = (char *)expression;
	while (*p)
	{
		if (isdigit(*p))
		{
			push(*p - '0');
			p++;
		}
		else if (ispunct(*p))
		{
			int temp;
			switch (*p)
			{
				case '+':
					{
						temp = stack[top - 2] + stack[top - 1];
						pop(); pop();
						push(temp);
						break;
					}
				case '-':
					{
						temp = stack[top - 2] - stack[top - 1];
						pop(); pop();
						push(temp);
						break;
					}
				case '*':
					{
						temp = stack[top - 2] * stack[top - 1];
						pop(); pop();
						push(temp);
						break;
					}
				case '/':
					{
						temp = stack[top - 2] / stack[top - 1];
						pop(); pop();
						push(temp);
						break;
					}
				default:
					exit(EXIT_FAILURE);
			}
		}
		p++;
	}
#ifdef debug
	print_stack();
#endif
	return stack[0];
}

bool is_empty(void)
{
	return top == 0;
}

bool is_full(void)
{
	return top == STACK_SIZE - 1;
}

void push(int i)
{
#ifdef debug
	printf("top = %d\n", top);
#endif
	if (is_full())
	{
		printf("Stack overflow\n");
		exit(EXIT_FAILURE);
	}
	stack[top++] = i;
}

int pop(void)
{
	if (is_empty())
	{
		printf("Stack underflow\n");
		exit(EXIT_FAILURE);
	}
	stack[--top] = 0;
	return top;
}

void print_stack(void)
{
	for (int i = STACK_SIZE - 1; i >= 0; i--)
		printf("[%d]%d\n", i, stack[i]);
}
