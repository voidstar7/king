#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

struct node {
  int data;
  struct node *next;
};

typedef struct {
	struct node n;
} Stack;

void make_empty(Stack *s);
bool is_empty(Stack *s);
bool is_full(Stack *s);
void push(Stack **s, int i);
int pop(Stack *s);
void print_stack(Stack **s);

#endif
