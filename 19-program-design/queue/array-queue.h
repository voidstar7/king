#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct queue_type *Queue;

struct queue_type { 
	int *array;
	int size;
	int open;
	int head;
	int maxLength;
};

Queue create(int max);
void enqueue(Queue q, int item);
int dequeue(Queue q);
bool isEmpty(Queue q);
void printQueue(Queue q);

#endif
