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

struct node *createNode(char *buffer);

int main(void) {
	int count = 0;
	char buffer[MAX_WORD_LEN], c;
	struct node *newNode;

	while ((c = getchar()) == ' ' || c == '\t')
		;
	while (c != '\n') {
		buffer[count++] = c;
		if (c == ' ')
			break;
		c = getchar();
	}
	buffer[count++] = '\0';
	// should i allocate newNode memory here and pass a pointer to newNode to createNode() probably should do it here right?
	newNode = createNode(buffer);
	printf("%s", newNode->letters);
}

struct node *createNode(char *buffer) {
	struct node *word;
	int wordLength = strlen(buffer);

	// or do i allocate the memory here?
	word = malloc(sizeof(struct node));
	if (word == NULL) {
		printf("Could not allocate memory for new node\n");
		exit(1);
	}
	word->letters = malloc(wordLength);
	if (word->letters == NULL) {
		printf("Could not allocate memory for node string\n");
		exit(1);
	}
	strcpy(word->letters, buffer);
	word->length = wordLength;
	return word;
}

