#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define FLUSH_INPUT	while ((c = getchar()) != '\n');

struct node {
	int data;
	int id;
	struct node *next;
};

struct node *create_node(struct node *listItem);
void print_list(struct node *head);
struct node *delete_node(struct node *head, int deleteId);

int numNodes = 0;
int nodeId = 100;

int main(void) {
	struct node *head, *listItem;
	char op, c;
	int deleteId;
	
	for (;;) {
		printf("(a) add node\n(d) delete node\n(p) print list\n(e) exit\n>>> ");
		scanf(" %c", &op);
		FLUSH_INPUT
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
			case 'd':
					printf("Enter node ID to delete: ");
					scanf(" %d", &deleteId);
					free(delete_node(head, deleteId));
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

struct node *create_node(struct node *listItem) {
	struct node *newNode;

	newNode = malloc(sizeof(struct node));
	if (newNode == NULL) {
		printf("Unable to assign memory to new node\n");
		exit(1);
	}
	newNode->id = nodeId++;
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
		printf("%p id:%d %d\n", p, p->id, p->data);
	printf("%p id:%d %d\n", p, p->id, p->data);
}

// doesn't work if you delete the first node (head) or the last one
// handle deletion when there are only two or one nodes left
struct node *delete_node(struct node *head, int deleteId) {
	struct node *cur, *prev;
	
	for (cur = prev = head; 
			 cur->next != NULL;
			 prev = cur,
			 cur = cur->next) {

		if (cur->id == deleteId) {
			prev->next = cur->next;
			numNodes--;
			break;
		}
	}
	return cur;
}
