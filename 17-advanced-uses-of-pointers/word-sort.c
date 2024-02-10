#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LEN 20

int main(void) {
	int numWords = 0, len;
	char *words[numWords], buffer[MAX_LEN + 1];

	printf("Enter word: ");
	fgets(buffer, MAX_LEN + 1, stdin);
	len = strlen(buffer);
	buffer[len] = '\0';
	*words = malloc(len + 1);
	if (*words == NULL) {
		printf("Could not allocate memory\n");
		return 1;
	}
	strcpy(*words + (numWords++), buffer);

	printf("%s\n", *words);
}

