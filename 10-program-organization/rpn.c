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
			printf("total = %d\n", total);
			pop();
			for (int i = 0; i < STACK_SIZE; i++)
				printf("[%d]%c ", i, stack[i]);
			printf("\n");
			return 0;
		}
		else
			return 0;
	}
}

char prompt(void)
{
	int n;
	char input;
	printf(">>> ");
	scanf(" %c", &input);
	push(input);
	printf("Pushed %d onto stack (top: %d)\n", input, top);

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
			exit(1);
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
		printf("Stack overflow\n");
		exit(1);
	}
	else
		stack[top++] = i;
}

int pop(void)
{
	int i;
	if (is_empty())
	{
		printf("Stack underflow\n");
		exit(1);
	}
	else
	{
		for (i = 1; i <= 3; i++)
			stack[top - i] = 0;
		return top;
	}
}

