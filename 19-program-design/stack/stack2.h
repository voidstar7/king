#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#define MAX_SIZE 5

typedef struct {
	int data[MAX_SIZE];
	int top;
} Stack;

void initialize(Stack *s);
bool is_empty(Stack *s);
bool is_full(Stack *s);
void push(Stack *s, int i);
int pop(Stack *s);
Stack *createStack(Stack *s);

#endif
