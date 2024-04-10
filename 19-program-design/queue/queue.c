#include <stdio.h>
#include "queue.h"

static int queue[QUEUE_MAX] = { 0 },
					 open, head;
extern int size;

void enqueue(int item) {
	queue[open++] = item;
	size++;
}

int dequeue(void) {
	int n = queue[head];
	queue[head++] = 0;
	size--;
	return n;
}

bool isEmpty(void) {
	int i;
	for (i = 0; i < QUEUE_MAX; i++) {
		if (i != 0) {
			return false;
		}
	}
	open = head = size = 0;
	return true;
}

void printQueue(void) {
	int i;
	for (i = 0; i < QUEUE_MAX; i++)
		printf("%d ", queue[i]);
	printf("\n");
}

