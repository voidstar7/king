#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACK_SIZE 5 

// a RPC calculator that accepts single digit operands

void prompt(void);
bool is_empty(void);
bool is_full(void);
void push(int i);
int pop(void);

char stack[STACK_SIZE];
int top = 0; 
int total = 0;

int main(void)
{
	while (1)
	{
		prompt();
	}
}

void prompt(void)
{
	int n;
	char c, input;
	printf(">>> ");
	scanf(" %c", &input);
	push(input);
	printf("Pushed %d onto stack\n", input);

	printf("*** Top is %d ***\n", top);

	for (int i = 0; i < STACK_SIZE; i++)
		printf("[%d]%c ", i, stack[i]);
	printf("\n");
	return;
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
	if (is_empty())
	{
		printf("Stack underflow\n");
		exit(1);
	}
	else
	{
		stack[--top] = 0;
		return top;
	}
}

