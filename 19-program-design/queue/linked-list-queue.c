#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

extern int size;
static struct node *first, *last, *new;

void enqueue(int item) {
	if (size == 0) {
		first = createNode();
		first->data = item;
		first->next = NULL;
		last = first;
	}
	else {
		new = createNode();
		last->next = new;
		new->data = item;
		new->next = NULL;
		last = new;
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
	int dequeued = first->data;
	struct node *newFirst = first->next;
	free(first);
	first = newFirst;
	size--;
	return dequeued;
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
