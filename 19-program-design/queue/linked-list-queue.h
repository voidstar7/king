#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef struct linked_list *Queue;

struct node {
	int data;
	struct node *next;
};

struct linked_list { 
	int maxLength;
	int size;
	struct node *front;
};

Queue create(int i);
void enqueue(Queue q, int item);
int dequeue(Queue q);
bool isEmpty(Queue q);
void printQueue(Queue q);
struct node *createNode(void);

#endif
