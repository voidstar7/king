#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 20
#define debug

void readWord(char *buffer, char **words, int numWords);

int main(void) {
	char **words, **tmp, buffer[MAX_LEN], c;
	int numWords = 0, i;

	words = malloc(sizeof(char *));
	if (words == NULL) {
		printf("Could not allocate memory\n");
		return 1;
	}
	for (;;) {
		readWord(buffer, words, numWords);
		fflush(stdin); // this is undefined and apparently very bad to use
		if (buffer[0] == '\n')
			break;
		if (numWords > 0) {
			tmp = realloc(words, sizeof(char *) * (numWords + 1));
			if (tmp == NULL) {
				printf("Could not reallocate memory\n");
				return 1;
			}
			if (tmp != words) {
#ifdef debug
				printf("realloc block moved\nold %p\nnew %p\n", 
						words, tmp);
#endif
				words = tmp;
			}
		}
		words[numWords] = malloc(strlen(buffer));
		strcpy(words[numWords], buffer);
		numWords++;
#ifdef debug
		for (i = 0; i < numWords; i++)
			printf("%p %s\n", &words[i], words[i]);
#endif
	}
}

void readWord(char *buffer, char **words, int numWords) {
	int input, i, length = 0;

	printf("Enter word: ");
	while (length < MAX_LEN && (char)(input = getchar()) != '\n') 
		buffer[length++] = input;
	printf("length %d\n", length);
	buffer[length] = '\0';
	if (length == 0) {
	for (i = 0; i < numWords; i++)
		printf("%s\n", words[i]);
	exit(1);
	}
}
