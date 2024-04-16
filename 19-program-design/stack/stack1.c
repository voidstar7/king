#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

static void terminate(const char *message)
{
  printf("%s\n", message);
  exit(EXIT_FAILURE);
}

void make_empty(Stack *s)
{
  s->top = 0;
}

bool is_empty(Stack *s)
{
  return s->top == 0;
}

bool is_full(Stack *s)
{
  return s->top == STACK_SIZE;
}

void push(Stack *s, int i)
{
  if (is_full(s))
    terminate("Error in push: stack is full.");
  s->contents[s->top] = i;
	s->top++;
}

int pop(Stack *s)
{
	int i;
  if (is_empty(s))
    terminate("Error in pop: stack is empty.");
	i = s->contents[(s->top) - 1];
	s->top--;
  return i;;
}
