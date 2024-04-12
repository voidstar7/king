#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#define QUEUE_MAX 5

void enqueue(int item);
struct node *createNode(void);
int dequeue(void);
//int returnFirst(void);
//int returnLast(void);
bool isEmpty(void);
void printQueue(void);

struct node {
	int data;
	struct node *next;
};

#endif
