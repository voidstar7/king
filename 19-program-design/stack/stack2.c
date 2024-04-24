#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int stack_size = 0;
static Stack *top = NULL;

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
	Stack *newNode = createNode();
  newNode->data = i;
	newNode->next = NULL;
	if (stack_size == 0)
		*s = top = newNode;
	else {
		top->next = newNode;
		top = newNode;
	}
	stack_size++;
	printf("Pushed %i to stack (size %d)\n", i, stack_size);
}

Stack *createNode(void) {
	Stack *n = malloc(sizeof(Stack));
	if (n == NULL) {
		terminate("Could not allocate node memory.");
		exit(1);
	}
	return n;
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

void print_stack(Stack **s) {
	Stack *t;
	for (t = *s; t != NULL; t = t->next)
		printf("%d ", t->data);
	printf("\n");
}
