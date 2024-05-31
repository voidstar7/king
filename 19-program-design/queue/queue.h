#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#define QUEUE_MAX 5

struct node {
	int data;
	struct node *next;
};

typedef struct { 
	int array[QUEUE_MAX];
	int size;
	int open;
	int head;
} Queue;

void enqueue(Queue *q, int item);
int dequeue(Queue *q);
bool isEmpty(Queue *q);
void printQueue(Queue *q);

struct node *createNode(void);
void init(Queue *q);

#endif
