#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

struct nav {
	struct nav *p;
};

typedef struct {
  int data;
  struct nav *next;
} Node;

//void make_empty(Stack *s);
//bool is_empty(Stack *s);
//bool is_full(Stack *s);
void push(Node **n, int i);
//int pop(Stack *s);
//void print_stack(Node **n);

#endif
