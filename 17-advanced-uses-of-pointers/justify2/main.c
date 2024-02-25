#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 40
#define MAX_WORD_LEN 16

struct node {
	char *letters;
	int length;
	struct node *prev;
	struct node *next;
};

int getWord(char *buffer);
void createNode(struct node *new, char *buffer);
//void printParagraph(struct node *head); 
void printParagraph(struct node *tail); 

int main(void) {
	char buffer[MAX_WORD_LEN + 1];
	struct node *head, *middle, *newNode, *tail;
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
			head->prev = NULL;
		}
		else if (wordCount == 1) {
			head->next = newNode;
			newNode->prev = head;
		}
		else  {
			middle->next = newNode;
			newNode->prev = middle;
		}
		middle = newNode;
		wordCount++;
	}
	newNode = malloc(sizeof(struct node));
	if (newNode == NULL) {
		printf("Could not allocate memory for tail node pointer\n");
		return 1;
	}
	createNode(newNode, buffer);
	middle->next = newNode;
	newNode->prev = middle;
	newNode->next = NULL;
	tail = newNode;

	//printParagraph(head);
	printParagraph(tail);
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
	new->next = NULL; 
}

//void printParagraph(struct node *head) {
void printParagraph(struct node *tail) {
	struct node *p;
	int lineLen = 0;

	//for (p = head; p != NULL; p = p->next) {
	for (p = tail; p != NULL; p = p->prev) {
		lineLen += p->length;
		if (lineLen < MAX_LINE_LEN) {
			printf("%s", p->letters);
		}
		else {
			printf("\n");
			lineLen = p->length;
			printf("%s", p->letters);
		}
	}
	printf("\n");
}
