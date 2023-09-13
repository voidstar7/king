#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACK_SIZE 100 

void stack_overflow(void);
void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(char c);
int pop(void);
void stack_overflow(void);
void stack_underflow(void);

int contents[STACK_SIZE];
int top = 0;

int main(void)
{
	char input = 0;
	printf("Enter parentheses and/or braces: ");
	while (input != '\x0a')
	{
		scanf("%c", &input);
		push(input);	
	}
	for (int i = 0; i < STACK_SIZE; i++)
		printf("%c", contents[i]);
}

void make_empty(void)
{
	top = 0;
}

bool is_empty(void)
{
	return top == 0;
}

bool is_full(void)
{
	return top == STACK_SIZE;
}

void push(char c)
{
	if (is_full())
		stack_overflow();
	else
		contents[top++] = c;
}

int pop(void)
{
	if (is_empty())
	{
		stack_underflow();
		return 0;
	}
	else
		return contents[--top];
}

void stack_overflow(void)
{
	printf("Stack overflow\n");
}

void stack_underflow(void)
{
	printf("Stack underflow\n");
}
