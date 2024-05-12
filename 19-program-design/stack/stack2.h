#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef struct node {
	int data;
	struct node *next;
} Node;

void initialize(Node *n);
//bool is_empty(Stack *s);
void push(Node *s, int i);
//int pop(Stack *s);
Node *createStack(Node *n);

#endif
