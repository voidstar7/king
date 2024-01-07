#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	int position;
	struct node *next;
};

struct node *add_to_list(struct node *head, int n);
struct node *read_numbers(void);
void print_list(struct node *head);

int main(void) {
	struct node *head = read_numbers();
	print_list(head);
}

struct node *read_numbers(void) {
	struct node *head = NULL;
	int n;

	printf("Enter a series of integers (0 to terminate): ");
	for (;;) {
		scanf("%d", &n);
		if (n == 0)   
			return head;
		head = add_to_list(head, n);
	}
}

struct node *add_to_list(struct node *head, int n) {
	static int p = 0;
	struct node *newNode;

	newNode = malloc(sizeof(struct node));
	if (newNode == NULL) {
		printf("Could not assign memory for new node\n"); 
		exit(1);
	}
	newNode->value = n;
	newNode->position = p;
	newNode->next = head;
	p++;
	return newNode;
}

void print_list(struct node *head) {
	struct node *p;

	for (p = head; p != NULL; p = p->next)
		printf("[%d]%d ", p->position, p->value);
	printf("\n");
}
