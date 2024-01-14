#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACK_SIZE 10
#define PRINT_COMMANDS printf("Commands:\n(p) push\n(o) pop\n(t) print\n(e) exit\n")


void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(int input);
int pop(void);
void print_stack(void);
void stack_underflow(void); 
void stack_overflow(void);

int top = 0;
int stack[STACK_SIZE];

int main(void) {
	int input;
	char op;

	PRINT_COMMANDS;
	for (;;) {
		printf("Enter command: ");
		scanf(" %c", &op);
		switch(op) {
			case 'p':
				printf("Enter an integer: ");
				scanf(" %d", &input);
				push(input);
				break;
			case 'o':
				pop();
				stack[top] = 0; 
				break;
			case 't':
				print_stack(); break;
			case 'e':
				return 0;
			default:
				printf("Invalid command\n");
				PRINT_COMMANDS;
				break;
		}
	}
	return 0;
}

void make_empty(void) {
	top = 0;
}

bool is_empty(void) {
	return top == 0;
}

bool is_full(void) {
	return top == STACK_SIZE;
}

void push(int input) {
	if (is_full())
		stack_overflow();
	else
		stack[top++] = input;
}

int pop(void) {
	if (is_empty()) {
		stack_underflow();
		return 0;
	}
	else
		return stack[--top];
}

void stack_overflow(void) {
	printf("Stack overflow\n");
	exit(1);
}

void stack_underflow(void) {
	printf("Stack underflow\n");
	exit(1);
}

void print_stack(void) {
	int i;

	for (i = STACK_SIZE - 1; i >= 0; i--)
		printf("%p %d\n", &stack[i], stack[i]);
}
