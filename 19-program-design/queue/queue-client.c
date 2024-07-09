#include <stdio.h>
#include <stdlib.h>
#include "array-queue.h"

int main(void) {
	Queue q1 = create(5);
	Queue q2 = create(3);
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
				if (qp->size == qp->maxLength) {
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
