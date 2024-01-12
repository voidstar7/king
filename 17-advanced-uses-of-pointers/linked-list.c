#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
	int data;
	struct node *next;
};

char get_operation(char *input);
struct node *create_node(struct node *listItem);
void print_list(struct node *head);

int numNodes = 0;

int main(void) {
	struct node *head, *listItem;
	char *input, op;
	
	for (;;) {
		printf("(a) add item\n(p) print list\n(e) exit\n>>> ");
		op = get_operation(fgets(input, 100, stdin));
		switch(op) {
			case 'a': 
				if (numNodes == 0)
					head = listItem = create_node(listItem);
				else
					listItem = create_node(listItem);
				break;
			case 'p':
				if (numNodes > 0){
					listItem->next = NULL;
					print_list(head);
					printf("\n");
				}
				else
					printf("List is empty\n\n");
				break;
			case 'e':
				return 0;
			default:
				printf("Invalid input\n\n");
				continue;
		} 
	}
	free(listItem);
	return 0;
}

char get_operation(char *input) {
	return input[0];
}

struct node *create_node(struct node *listItem) {
	struct node *newNode;

	newNode = malloc(sizeof(struct node));
	if (newNode == NULL) {
		printf("Unable to assign memory to new node\n");
		exit(1);
	}
	printf("Enter node data: ");
	scanf(" %d", &newNode->data);
	if (numNodes == 0) {
		newNode->next = NULL;
	}
	else {
		listItem->next = newNode;
		newNode->next = NULL;
	}
	numNodes++;
	return newNode;
}

void print_list(struct node *head) {
	struct node *p;
	
	for (p = head; p->next != NULL; p = p->next)
		printf("%d\n", p->data);
	printf("%d\n", p->data);
}


