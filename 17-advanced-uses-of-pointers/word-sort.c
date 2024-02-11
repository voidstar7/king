#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 20

int main(void) {
	int numWords = 0, bytes = 0, len;
	char **words, **tmp, buffer[MAX_LEN + 1];

	// 1
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
	bytes += len + 1;
	printf("%s", *words);
	printf("string array is %dB\n", bytes);

	// 2
	printf("Enter word: ");
	fgets(buffer, MAX_LEN + 1, stdin);
	len = strlen(buffer);
	buffer[len] = '\0';
	*tmp = realloc(*words, bytes + (len + 1));
	if (*tmp == NULL) {
		printf("Failed to reallocate memory\n");
		exit(1);
	}
	if (*tmp != *words)
		*words = *tmp;
	strcpy(*words + (numWords++), buffer);
	bytes += len + 1;
	printf("%s", *words + 1);
	printf("string array is %dB\n", bytes);

	// 3
	printf("Enter word: ");
	fgets(buffer, MAX_LEN + 1, stdin);
	len = strlen(buffer);
	buffer[len] = '\0';
	*tmp = realloc(*words, bytes + (len + 1));
	if (*tmp == NULL) {
		printf("Failed to reallocate memory\n");
		exit(1);
	}
	if (*tmp != *words)
		*words = *tmp;
	strcpy(*words + (numWords++), buffer);
	bytes += len + 1;
	printf("%s", *words + 2);
	printf("string array is %dB\n", bytes);
	
	// 4
	printf("Enter word: ");
	fgets(buffer, MAX_LEN + 1, stdin);
	len = strlen(buffer);
	buffer[len] = '\0';
	*tmp = realloc(*words, bytes + (len + 1));
	if (*tmp == NULL) {
		printf("Failed to reallocate memory\n");
		exit(1);
	}
	if (*tmp != *words)
		*words = *tmp;
	strcpy(*words + (numWords++), buffer);
	bytes += len + 1;
	printf("%s", *words + 3);
	printf("string array is %dB\n", bytes);
}


