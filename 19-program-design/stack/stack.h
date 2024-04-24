#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

// need to track size in each stack
typedef struct node {
  int data;
	struct node *next;
} Stack;

//void make_empty(Stack *s);
//bool is_empty(Stack *s);
//bool is_full(Stack *s);
void push(Stack **s, int i);
//int pop(Stack *s);
void print_stack(Stack **s);
Stack *createNode(void);

#endif
