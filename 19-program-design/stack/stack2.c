#include <stdio.h>
#include <stdlib.h>
#include "stack2.h"

static Node *top, *head;

static void terminate(const char *message) {
  printf("%s\n", message);
  exit(EXIT_FAILURE);
}

void initialize(Node *n) {
  n->next = NULL;
	top = head = n;
}

/*bool is_empty(Stack *s) {
  return s->top == 0;
}*/

void push(Node *n, int i) {
	if (n != head) {
		top->next = n;
		top = n;
	}
	n->data = i;
	printf("Pushed %i\n", i);
}

/*int pop(Stack *s) {
	int i;
  if (is_empty(s))
    terminate("Error: stack is empty");
	i = s->data[(s->top) - 1];
	s->top--;
  return i;
}*/

Node *createStack(Node *n) {
	Node *m = malloc(sizeof(Node));
	if (m == NULL) {
		terminate("Error: could not allocate memory for node\n");
	}
	return m;
}
