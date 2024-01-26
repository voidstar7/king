#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 3
#define MAX_LEN 20

int addWord(char *words[], int wordCount);

int main(void) {
	int wordCount = 0, i = 0, j, wordLength;
	char *words[MAX_WORDS];

	while (i++ < MAX_WORDS) {
		if (addWord(words, wordCount++) == 0)
			break;
	}
	for (j = 0; j < wordCount; j++) {
		printf("%s\n", words[j]);
		free(words[j]);
	}
	return 0;
}

int addWord(char *words[], int wordCount) {
  int input, i = 0;
	char buffer[MAX_LEN];

	printf("Enter word: ");
  while (isspace(input = getchar()))
    ;
  while (input != '\n') {
    if (i < MAX_LEN && !(isspace(input)))
      buffer[i++] = input;
    input = getchar();
  }
  buffer[i] = '\0';
	words[wordCount] = malloc(strlen(buffer) + 1);
	if (words[wordCount] == NULL) {
		printf("Error: unable to allocate memory\n");
		exit(1);
	}
	strcpy(words[wordCount], buffer);
  return i;
}
