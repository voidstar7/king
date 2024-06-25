#include <stdio.h>
#include <stdlib.h>
#include "array-queue.h"


int main(void) {
	Queue q1 = create();
	int input;
	char op;
	for (;;) {
		printf("(e)nqueue / (d)equeue / (p)rint: ");
		scanf(" %c", &op);
		switch(op) {
			case 'e':
				if (q1->size == QUEUE_MAX) {
					printf("Queue is full\n");
					continue;
				}
				else
					printf("Enter a number: ");
					scanf("%d", &input);
					enqueue(q1, input);
				break;
			case 'd':
				if (isEmpty(q1)) {
					printf("Queue is empty\n");
					continue;
				}
				else
					printf("%d\n", dequeue(q1));
				break;
			case 'p':
				if (isEmpty(q1)) {
					printf("Queue is empty\n");
					continue;
				}
				printQueue(q1);
				break;
			default:
				printf("Invalid entry\n");
		}
	}
}
