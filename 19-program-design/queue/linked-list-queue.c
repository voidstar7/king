#include <stdio.h>
#include <stdlib.h>
#include "linked-list-queue.h"

Queue create(int i) {
	Queue q = malloc(sizeof(struct linked_list));
	if (q == NULL) {
		printf("Could not allocate memory for new queue\n");
		exit(1);
	}
	q->maxLength = i;
	q->size = 0;
	q->front = NULL;
	return q;
}

void enqueue(Queue q, int item) {
	struct node *new = createNode();
	if (new == NULL) {
		printf("Could not allocate memory for new node\n");
		exit(1);
	}
	new->data = item;
	new->next = NULL;
	if (q->size == 0)
		q->front = new;
	else {
		struct node *n = q->front;
		for (; n->next != NULL; n = n->next)
			;
		n->next = new;
	}
	q->size++;
}

struct node *createNode(void) {
	struct node *n = malloc(sizeof(struct node));
	if (n == NULL) {
		printf("Could not allocate memory for new node\n");
		exit(1);
	}
	return n;
}

int dequeue(Queue q) {
	int i = q->front->data;
	struct node *n = q->front;
	q->front = q->front->next;
	q->size--;
	free(n);
	return i;
}

bool isEmpty(Queue q) {
	if (q->size == 0)
		return true;
	return false;
}

void printQueue(Queue q) {
	for (struct node *n = q->front; n != NULL; n = n->next)
		printf("%d ", n->data);
	printf("\n");
}
