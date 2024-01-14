#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACK_SIZE 10
#define PRINT_COMMANDS printf("Commands:\n(p) push\n(o) pop\n(t) print\n(e) exit\n")

struct stackItem {
	int value;
	struct stackItem *next;
};

struct stackItem *push(int input, struct stackItem *tail);
struct stackItem *pop(struct stackItem *head, struct stackItem *tail);
void print_stack(struct stackItem *head); 

int stackSize = 0;

int main(void) {
	struct stackItem *head, *tail;
	int input; 
	char op;

	PRINT_COMMANDS;
	for (;;) {
		printf("Enter command: ");
		scanf(" %c", &op);
		switch(op) {
			case 'p':
				printf("Enter an integer: ");
				scanf(" %d", &input);
				if (stackSize == 0)
					head = tail = push(input, tail);
				else
					tail = push(input, tail);
				break;
			case 'o':
				if (stackSize == 1) {
					stackSize--;
					free(head);
				}
				else
					tail = pop(head, tail);
				break;
			case 't':
				print_stack(head); 
				break;
			case 'e':
				return 0;
			default:
				printf("Invalid command\n");
				PRINT_COMMANDS;
				break;
		}
	}
	return 0;
}

struct stackItem *push(int input, struct stackItem *tail) {
	struct stackItem *newItem;

	newItem = malloc(sizeof(struct stackItem));
	if (newItem == NULL) {
		printf("Could not allocate memory for new stack item\n");
		exit(1);
	}
	newItem->value = input;
	if (stackSize == 0)
		newItem->next = NULL;
	else {
		tail->next = newItem; 
		newItem->next = NULL;
	}
	stackSize++;
	return newItem;
}

struct stackItem *pop(
		struct stackItem *head,
		struct stackItem *tail) {
	struct stackItem *p, *q;

	if (stackSize == 0) {
		printf("Stack underflow\n");
		exit(1);
	}
	for (p = head; p->next != tail; p = p->next)
		q = p;
	if (stackSize == 2)
		head->next = NULL;
	else {
		q->next = p;
		p->next = NULL;
	}
	free(tail);
	stackSize--;
	return p;
}

void print_stack(struct stackItem *head) {
	struct stackItem *p;

	if (stackSize == 0) {
		printf("Stack is empty\n");
		return;
	}
	for (p = head; p->next != NULL; p = p->next)
		printf("%p %d\n", p, p->value);
	printf("%p %d\n", p, p->value);
}
