#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACK_SIZE 10
#define PRINT_COMMANDS printf("Commands:\n(p) push\n(o) pop\n(t) print\n(e) exit\n")

struct stackItem {
	int value;
	struct stackItem *next;
};

void make_empty(void);
bool is_empty(void);
struct stackItem *push(int input, struct stackItem *tail);
int pop(void);
void print_stack(struct stackItem *head); 
void stack_underflow(void); 

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
		//	case 'o':
		//		pop();
		//		stack[top] = 0; 
		//		break;
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

//void make_empty(void) {
//	top = 0;
//}

//bool is_empty(void) {
//	return top == 0;
//}

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
		// newItem becomes the new tail
		tail->next = newItem; 
		newItem->next = NULL;
	}
	stackSize++;
	return newItem;
}

/*
int pop(void) {
	if (is_empty()) {
		stack_underflow();
		return 0;
	}
	else
		return stack[--top];
}
*/

void stack_underflow(void) {
	printf("Stack underflow\n");
	exit(1);
}

void print_stack(struct stackItem *head) {
	struct stackItem *p;

	for (p = head; p->next != NULL; p = p->next)
		printf("%p %d\n", p, p->value);
	printf("%p %d\n", p, p->value);
}
