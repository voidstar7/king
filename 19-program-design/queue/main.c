#include <stdio.h>
#include "queue.h"

int size = 0;

int main(void) {
	int input;
	char op;
	for (;;) {
		printf("(e)nqueue / (d)equeue / (p)rint: ");
		scanf(" %c", &op);
		switch(op) {
			case 'e':
				if (size == QUEUE_MAX) {
					printf("Queue is full\n");
					continue;
				}
				else
					printf("Enter a number: ");
					scanf("%d", &input);
					enqueue(input);
				break;
			case 'd':
				if (isEmpty()) {
					printf("Queue is empty");
					continue;
				}
				else
					printf("%d\n", dequeue());
				break;
			case 'p':
				printQueue();
				break;
			default:
				printf("Invalid entry\n");
		}
	}
}
