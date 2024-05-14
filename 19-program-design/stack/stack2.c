#include <stdio.h>
#include <stdlib.h>
#include "stack2.h"

static Node *top = NULL; 

static void terminate(const char *message) {
  printf("%s\n", message);
  exit(EXIT_FAILURE);
}

bool isEmpty() {
  return top == NULL;
}

void push(Node **head, int i) {
	if (isEmpty()) {
		*head = createNode();
		(*head)->data = i;
		(*head)->next = NULL;
		top = *head;
		printf("pushed %d (%p)\n", (*head)->data, *head);
	}
	else {
		Node *new, *oldTop;
		new = createNode();
		new->data = i;
		new->next = NULL;
		oldTop = findTop(*head);
		oldTop->next = new;
		top = new;
		printf("pushed %d (%p)\n", new->data, new);
	}
}

Node *createNode(void) {
	Node *new = malloc(sizeof(Node));
	if (new == NULL)
		terminate("Error: could not allocate memory for node\n");
	return new;
}

Node *findTop(Node *head) {
	Node *n;
	for (n = head; n->next != NULL; n = n->next) 
		;
	return n;
}
