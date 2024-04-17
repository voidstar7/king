#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct node *top = NULL;
int stack_size = 0;

static void terminate(const char *message)
{
  printf("%s\n", message);
  exit(EXIT_FAILURE);
}

/*void make_empty(Stack *s)
{
  while (!is_empty(s))
    pop(s);
}*/

/*bool is_empty(void)
{
  return top == NULL;
}*/

/*bool is_full(Stack *s)
{
  return false;
}*/

void push(Stack **s, int i)
{
	*s = malloc(sizeof(Stack));
	if (*s == NULL)
		terminate("Error in push: stack is full.");
  (*s)->n.data = i;
	(*s)->n.next = NULL;
	stack_size++;
}

/*int pop(Stack *s)
{
  struct node *old_top;
  int i;

  if (is_empty(s))
    terminate("Error in pop: stack is empty.");

  old_top = top;
  i = top->data;
  top = top->next;
  free(old_top);
  return i;
}*/
