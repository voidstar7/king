#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#define STACK_SIZE 5 

// a RPC calculator that accepts single digit operands

char prompt(void);
void calculate(char pushed);
bool is_empty(void);
bool is_full(void);
void push(int i);
int pop(void);
void stack_underflow(void);
void stack_overflow(void);

char stack[STACK_SIZE];
int top = 0; 
int total = 0;

int main(void)
{
	char c, pushed;
	while (1)
	{
		pushed = prompt();
		if (isdigit(pushed))
			continue;
		else if (ispunct(pushed))
		{
			calculate(pushed);
			for (int i = 0; i < STACK_SIZE; i++)
				printf("[%d]%c ", i, stack[i]);
			printf("\n");
			continue;
		}
		else if (pushed == 'p')
		{
			if (is_empty())
			{
				printf("total = %d\n", total);
				return 0;
			}
			stack_underflow();
			return 1;
		}
	}
}

char prompt(void)
{
	int n;
	char input;
	printf(">>> ");
	scanf(" %c", &input);
	if (input == 'p')
		return 'p';
	push(input);
	printf("Pushed %d onto stack (top: %d)\n",
			input - 48, top);
	for (int i = 0; i < STACK_SIZE; i++)
		printf("[%d]%c ", i, stack[i]);
	printf("\n");
	return input;
}

void calculate(char pushed)
{
	switch (pushed)
	{
		case '+':
			total = 
				(stack[top - 2] - 48)+
				(stack[top - 3] - 48);
			pop();
			printf("+ detected (top: %d)\n", top);
			break;
		case '-':
			total = 
				(stack[top - 2] - 48)-
				(stack[top - 3] - 48);
			break;
		case '*':
			total = 
				(stack[top - 2] - 48)*
				(stack[top - 3] - 48);
			break;
		case '/':
			total = 
				(stack[top - 2] - 48)/
				(stack[top - 3] - 48);
			break;
		default:
			printf("Error: illegal char pushed\n");
			exit(EXIT_FAILURE);
	}
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
		stack_overflow();
		exit(EXIT_FAILURE);
	}
	else
		stack[top++] = i;
}

int pop(void)
{
	int i;
	if (is_empty())
	{
		stack_underflow();
		exit(EXIT_FAILURE);
	}
	else
	{
		for (i = 1; i <= 3; i++)
		{
			stack[top - i] = 0;
		}
		top -= 3;
		return top;
	}
}

void stack_underflow(void)
{
	printf("Error: stack underflow\n");
}

void stack_overflow(void)
{
	printf("Error: stack overflow\n");
}
