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
void printParagraph(struct node *head); 
int addSpace(char **nodeString, int stringLength); 
void parse(struct node *head, struct node *tail);

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
		else {
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

	printf("\n");
	parse(head, tail);
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
	new->next = NULL; 
}

void parse(struct node *head, struct node *tail) {
	struct node *p, *q, *r, *s;
	int lineLength = 0, spacesToAdd;

	// this is way too complicated
	for (p = q = r = s = head; p != tail; p = p->next) {
		lineLength += p->length;
		if (lineLength > MAX_LINE_LEN) {
			q = p->prev;
			q->letters[(q->length)] = '\n';
			spacesToAdd = MAX_LINE_LEN - ((MAX_LINE_LEN - q->length) + 1);
			q = q->prev;
			printf("spaces to add = %d\n", spacesToAdd);
			printf("p = %s\n", p->letters);
			for (;;) {
				if (spacesToAdd > 0) {
					addSpace(&(s->letters), s->length);
					s = s->next;
					spacesToAdd--;
				}
				else
					break;
				if (spacesToAdd > 0) {
					addSpace(&(q->letters), q->length);
					q = q->prev;
					spacesToAdd--;
				}
				else
					break;
				if (s == q) {
					s = r;
					q = p->prev;
					q = q->prev;
				}
			}
		}
		else if (lineLength == MAX_LINE_LEN) {
			printf("spaces to add = 1\n");
			printf("p = %s\n", p->letters);
			p->letters[(p->length)] = '\n';
			addSpace(&(r->letters), r->length);
			lineLength = 0;
			q = r = s = p->next;
			continue;
		}
		else
			continue;
		lineLength = 0;
		p = p->prev;
		q = r = s = p->next;
	}
}


int addSpace(char **nodeString, int stringLength) {
	char *tmp, space[2] = { [0] = ' ' };

	tmp = realloc(*nodeString, 1);
	if (tmp == NULL) {
		printf("Could not increase size of node string\n");
		exit(1);
	}
	if (tmp != *nodeString)
		*nodeString = tmp;
	strcat(*nodeString, space);
	return 1;
}

void printParagraph(struct node *head) {
	struct node *p;
	int lineLength = 0;

	for (p = head; p != NULL; p = p->next)
		printf("%s", p->letters);
	printf("\n");
}
