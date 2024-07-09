#include <stdio.h>
#include <stdlib.h>
#include "array-queue.h"

int main(void) {
	Queue q1 = create();
	Queue q2 = create();
	Queue qp;
	int input, selectedQueue;
	char op;
	for (;;) {
		printf("Select queue (1 / 2): ");
		scanf("%d", &selectedQueue);
		if (selectedQueue == 1)
			qp = q1;
		else if (selectedQueue == 2)
			qp = q2;
		else {
			printf("Invalid selection\n");
			continue;
		}
		getchar();
		printf("(e)nqueue / (d)equeue / (p)rint: ");
		op = getchar();
		switch(op) {
			case 'e':
				if (qp->size == QUEUE_MAX) {
					printf("Queue is full\n");
					continue;
				}
				else
					printf("Enter a number: ");
					scanf("%d", &input);
					enqueue(qp, input);
				break;
			case 'd':
				if (isEmpty(qp)) {
					printf("Queue is empty\n");
					continue;
				}
				else
					printf("%d\n", dequeue(qp));
				break;
			case 'p':
				if (isEmpty(qp)) {
					printf("Queue is empty\n");
					continue;
				}
				printQueue(qp);
				break;
			default:
				printf("Invalid entry\n");
		}
	}
}
