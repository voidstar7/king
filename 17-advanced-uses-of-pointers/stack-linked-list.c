#include <stdio.h>
#include <stdbool.h>

#define STACK_SIZE 10

void make_empty(void);
int is_empty(void);
int is_full(void);
void push(int i);
int pop(void);
void stack_underflow(void); 
void stack_overflow(void);

int top = 0;
int stack[STACK_SIZE];

int main(void) {
	// 	
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

void push(int i) {
	if (is_full())
		stack_overflow();
	else
		stack[top++] = c;
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
