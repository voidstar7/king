#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACK_SIZE 5 

void stack_overflow(void);
void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(int i);
int pop(void);
void stack_overflow(void);
void stack_underflow(void);

int contents[STACK_SIZE];
int top = 0;

int main(void)
{
	int n, count;
	char c = 0;

	make_empty();
	printf("Enter numbers to push onto the stack: ");
	while (c != '\x0a')
	{
		scanf("%d", &n);
		push(n);
		printf("Pushed %d onto stack\n", n);
		c = getchar();
	}
	printf("*** Top is %d ***\n", top);
	for (int i = 0; i < STACK_SIZE; i++)
		printf("[%d]%d ", i, contents[i]);
	printf("\n");
	for (int i = 0; i < STACK_SIZE; i++)
	{
		printf("Popped %d off stack\n", pop());
	}
	printf("*** Top is %d ***\n", top);
	if (is_empty())
		printf("Stack is empty\n");
	return 0;
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

void push(int i)
{
	if (is_full())
		stack_overflow();
	else
		contents[top++] = i;
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
