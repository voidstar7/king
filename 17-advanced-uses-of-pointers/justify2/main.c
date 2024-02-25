#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 60
#define MAX_WORD_LEN 16

struct node {
	char *letters;
	int length;
	struct node *next;
};

int getWord(char *buffer);
void createNode(struct node *new, char *buffer);
void printParagraph(struct node *head); 

int main(void) {
	char buffer[MAX_WORD_LEN + 1];
	struct node *head, *newNode, *tmp;
	int wordCount = 0;

	printf("Enter paragraph: ");
	while (getWord(buffer) != '\n') { 
		newNode = malloc(sizeof(struct node));
		if (newNode == NULL) {
			printf("Could not allocate memory for new node pointer\n");
			return 1;
		}
		createNode(newNode, buffer);
		if (wordCount == 0) {
			head = newNode;
			head->next = NULL;
		}
		else if (wordCount == 1)
			head->next = newNode;
		else 
			tmp->next = newNode;
		tmp = newNode;
		wordCount++;
	}
	newNode = malloc(sizeof(struct node));
	if (newNode == NULL) {
		printf("Could not allocate memory for tail node pointer\n");
		return 1;
	}
	createNode(newNode, buffer);
	tmp->next = newNode;
	newNode->next = NULL;
	printParagraph(head);
	return 0;
}

int getWord(char *buffer) {
	int wordSize = 0;
	char c;

	while ((c = getchar()) == ' ' || c == '\t')
		;
	// need to cover truncation
	while (c != '\n' && wordSize < MAX_WORD_LEN) {
		buffer[wordSize++] = c;
		if (c == ' ')
			break;
		c = getchar();
	}
	buffer[wordSize++] = '\0';
	return c;
}

void createNode(struct node *new, char *buffer) {
	int wordLength = strlen(buffer);

	new->letters = malloc(wordLength);
	if (new->letters == NULL) {
		printf("Could not allocate memory for node string\n");
		exit(1);
	}
	strcpy(new->letters, buffer);
	new->length = wordLength;
	new->next = NULL; // ???
}

void printParagraph(struct node *head) {
	struct node *p;

	for (p = head; p != NULL; p = p->next)
		printf("%p %s\n", p, p->letters);
}
