#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 20
#define debug

int main(void) {
	char **words, **tmp, buffer[MAX_LEN];
	int numWords = 0, i;

	words = malloc(sizeof(char *));
	if (words == NULL) {
		printf("Could not allocate memory\n");
		return 1;
	}
	for (;;) {
		printf("Enter word: ");
		fgets(buffer, MAX_LEN, stdin);
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
			printf("%p %s", &words[i], words[i]);
#endif
	}
	for (i = 0; i < numWords; i++)
		printf("%s", words[i]);
	return 0;
}
