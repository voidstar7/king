#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include <stdlib.h>
#define QUEUE_MAX 5

typedef struct queue_type *Queue;

struct queue_type { 
	int array[QUEUE_MAX];
	int size;
	int open;
	int head;
};

Queue create(void);
void enqueue(Queue q, int item);
int dequeue(Queue q);
bool isEmpty(Queue q);
void printQueue(Queue q);

#endif
