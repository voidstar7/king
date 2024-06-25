#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


int main(void) {
	Queue *q = malloc(sizeof(Queue));
	if (q == NULL) {
		printf("Could not allocate memory for queue\n");
		exit(1);
	}
	init(q);
	int input;
	char op;
	for (;;) {
		printf("(e)nqueue / (d)equeue / (p)rint: ");
		scanf(" %c", &op);
		switch(op) {
			case 'e':
				if (q->size == QUEUE_MAX) {
					printf("Queue is full\n");
					continue;
				}
				else
					printf("Enter a number: ");
					scanf("%d", &input);
					enqueue(q, input);
				break;
			case 'd':
				if (isEmpty(q)) {
					printf("Queue is empty\n");
					continue;
				}
				else
					printf("%d\n", dequeue(q));
				break;
			case 'p':
				if (isEmpty(q)) {
					printf("Queue is empty\n");
					continue;
				}
				printQueue(q);
				break;
			default:
				printf("Invalid entry\n");
		}
	}
}
