#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

extern int size;
static struct node *first, *last, *temp;

void enqueue(int item) {
	if (size == 0) {
		first = createNode();
		first->data = item;
		first->next = NULL;
		last = first;
	}
	else {
		temp = createNode();
		last->next = temp;
		temp->data = item;
		temp->next = NULL;
		last = temp;
	}
	size++;
}

struct node *createNode(void) {
	struct node *n = malloc(sizeof(struct node));
	if (n == NULL) {
		printf("Could not allocate memory for new node\n");
		exit(1);
	}
	return n;
}

int dequeue(void) {
	return 1;
}

bool isEmpty(void) {
	if (size == 0)
		return true;
	return false;
}

void printQueue(void) {
	for (struct node *n = first; n != NULL; n = n->next)
		printf("%d ", n->data);
	printf("\n");
}
