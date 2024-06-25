#include <stdio.h>
#include "array-queue.h"

Queue create(void) {
	Queue q = malloc(sizeof(Queue));
	if (q == NULL) {
		printf("Could not allocate memory for queue\n");
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < QUEUE_MAX; i++) {
		q->array[i] = 0;
	};
	q->size = 0;
	q->open = 0;
	q->head = 0;
	return q;
};

void enqueue(Queue q, int item) {
	if (q->open == QUEUE_MAX - 1) {
		q->array[q->open] = item;
		q->open = 0;
	}
	else
		q->array[q->open++] = item;
	q->size++;
}

int dequeue(Queue q) {
	int n = q->array[q->head];
	if (q->head == QUEUE_MAX - 1) {
		q->array[q->head] = 0;
		q->head = 0;
	}
	else
		q->array[q->head++] = 0;
	q->size--;
	return n;
}

bool isEmpty(Queue q) {
	if (q->size == 0)
		return true;
	return false;
}

void printQueue(Queue q) {
	for (int i = 0; i < QUEUE_MAX; i++)
		printf("%d ", q->array[i]);
	printf("\n");
}

