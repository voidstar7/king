#include <stdio.h>
#include <stdlib.h>
#include "stack1.h"

static void terminate(const char *message) {
  printf("%s\n", message);
  exit(EXIT_FAILURE);
}

void initialize(Stack *s) {
  s->top = 0;
}

bool is_empty(Stack *s) {
  return s->top == 0;
}

bool is_full(Stack *s) {
  return s->top == MAX_SIZE;
}

void push(Stack *s, int i) {
  if (is_full(s))
    terminate("Error: stack is full");
  s->data[s->top] = i;
	s->top++;
	printf("Pushed %i\n", i);
}

int pop(Stack *s) {
	int i;
  if (is_empty(s))
    terminate("Error: stack is empty");
	i = s->data[(s->top) - 1];
	s->top--;
  return i;
}

Stack *createStack(Stack *s) {
	Stack *t = malloc(sizeof(Stack));
	if (t == NULL) {
		printf("Error: could not allocate memory for stack\n");
		exit(1);
	}
	return t;
}
