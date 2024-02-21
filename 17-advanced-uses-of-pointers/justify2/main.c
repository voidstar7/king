#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 60
#define MAX_WORD_LEN 16

struct node {
	char *letters;
	int length;
	struct word *next;
};

int getWord(char *buffer);
void createNode(struct node *new, char *buffer);

int main(void) {
	char buffer[MAX_WORD_LEN];
	struct node *newNode;

	printf("Enter paragraph: ");
	while (getWord(buffer) != EOF) {
		newNode = malloc(sizeof(struct node));
		if (newNode == NULL) {
			printf("Could not allocate memory for new node pointer\n");
			return 1;
		}
		createNode(newNode, buffer);
		printf("%p %s", newNode, newNode->letters);
		return 0;
	}
}

int getWord(char *buffer) {
	int wordSize = 0;
	char c;

	while ((c = getchar()) == ' ' || c == '\t')
		;
	while (c != '\n') {
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
}

