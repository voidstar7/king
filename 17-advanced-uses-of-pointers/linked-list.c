#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct node *create_node(struct node *listItem);
void print_list(struct node *head);

int numNodes = 0;

int main(void) {
	struct node *head, *listItem;

	// first node = head
	head = listItem = create_node(listItem);
	printf("%d %p\n", listItem->data, listItem);
	printf("%d %p\n", head->data, head);

	listItem = create_node(listItem);
	printf("%d %p\n", listItem->data, listItem);
	printf("%d %p\n", head->data, head);

	listItem = create_node(listItem);
	printf("%d %p\n", listItem->data, listItem);
	printf("%d %p\n", head->data, head);

	// last node = tail
	listItem->next = NULL;

	print_list(head);
	free(listItem);
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


