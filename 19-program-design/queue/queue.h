#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#define QUEUE_MAX 5

void enqueue(int item);
int dequeue(void);
//int returnFirst(void);
//int returnLast(void);
bool isEmpty(void);
void printQueue(void);

#endif
