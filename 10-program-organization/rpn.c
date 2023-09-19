#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#define STACK_SIZE 10 
//#define debug

// a RPC calculator that accepts single digit operands

bool is_empty(void);
bool is_full(void);
void push(int i);
int pop(void);
void print_stack(void);
void calculate(char operator);

int stack[STACK_SIZE];
int top = 0; 

int main(void)
{
	char input;
	int count = 0;
	printf(">>> ");
	while (1)
	{
		scanf(" %c", &input);
		if (isdigit(input))
		{
			stack[top++] = input - 48;
		}
		else if (
				input == '+' ||
				input == '-' ||
				input == '*' ||
				input == '/' 
				)
			calculate(input);
		else if (input == 'p')
			break;
		else
			continue;
	}
#ifdef debug
	print_stack();
	printf("top: %d\n", top);
#endif
	printf("%d\n", stack[top - 1]);
	return 0;
}

bool is_empty(void)
{
	return top == 0;
}

bool is_full(void)
{
	return top == STACK_SIZE;
}

void push(int i)
{
	if (is_full())
	{
		printf("Stack overflow\n");
		exit(EXIT_FAILURE);
	}
	else
		stack[top++] = i;
}

int pop(void)
{
	if (is_empty())
	{
		printf("Stack underflow\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		stack[--top] = 0;
		return top;
	}
}

void calculate(char operator)
{
	int temp;
	switch (operator)
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

void print_stack(void)
{
	for (int i = STACK_SIZE - 1; i >= 0; i--)
		printf("[%d]%d\n", i, stack[i]);
}
