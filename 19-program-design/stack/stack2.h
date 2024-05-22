#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef struct node {
	int data;
	struct node *next;
} Node;

bool isEmpty();
void push(Node **head, int i);
void pop(Node **head);
Node *createNode(void);
Node *findTop(Node *n);

#endif
