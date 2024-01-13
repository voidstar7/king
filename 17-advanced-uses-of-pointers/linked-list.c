#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define FLUSH_INPUT	while ((c = getchar()) != '\n');
#define PRINT_NODE printf("add: %p\ndata: %d\nid: %d \nnext: %p\n\n", p, p->data, p->id, p->next)

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
	struct node *head, *listItem, *nodeToDelete;
	char op, c;
	int deleteId;
	
	for (;;) {
		printf("(a) add node\n(d) delete node\n(p) print list\n(e) exit\n>>> ");
		scanf(" %c", &op);
		FLUSH_INPUT
		// invalid input isn't handled for each switch. No cancel op
		switch(op) {
			case 'a': 
				if (numNodes == 0)
					head = listItem = create_node(listItem);
				else
					listItem = create_node(listItem);
				break;
			case 'p':
					if (numNodes > 0)
						// listItem will always be the last node created = tail
						listItem->next = NULL;
					print_list(head);
					printf("\n");
					break;
			case 'd':
					printf("Enter node ID to delete: ");
					scanf(" %d", &deleteId);
					nodeToDelete = delete_node(head, deleteId);
					if (nodeToDelete == head)
						head = nodeToDelete->next;
					free(nodeToDelete);
					break;
			case 'e':
				return 0;
			default:
				// this will still add the valid input in the input string
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
	
	if (numNodes > 0) {
		printf("Number of nodes: %d\n\n", numNodes);
		// exits loop at 2nd to last node
		for (p = head; p->next != NULL; p = p->next)
			PRINT_NODE;
		PRINT_NODE;
	}
	else
		printf("List is empty\n");
}

struct node *delete_node(struct node *head, int deleteId) {
	struct node *cur, *prev;
	
	for (cur = prev = head; 
			 prev->next != NULL; // catches prev up to cur when cur reaches tail
			 prev = cur,
			 cur = cur->next) {

		if (cur->id == deleteId) {
			if (cur->next == NULL) {
				prev->next = NULL;
				break;
			}
			prev->next = cur->next;
			break;
		}
	}
	numNodes--;
	return cur;
}
