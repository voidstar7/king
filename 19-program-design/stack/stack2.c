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

void pop(Node **head) {
	if (isEmpty())
		terminate("Error: stack is empty");
	if (top == *head) {
		printf("popped %d (%p)\n", (*head)->data, *head);
		free(*head);
		top = NULL;
	}
	else if (top == ((*head)->next)) {
		printf("popped %d (%p)\n", ((*head)->next)->data, (*head)->next);
		free((*head)->next);
		(*head)->next = NULL;
		top = *head;
	}
	else {
		Node *n = *head;
		while (n->next != top) {
			n = n->next;
		}
		printf("popped %d (%p)\n", (n->next)->data, n->next);
		free(n->next);
		n->next = NULL;
		top = n;
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
