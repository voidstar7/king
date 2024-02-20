#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 60
#define MAX_WORD_LEN 16

struct word {
	char *letters;
	int length;
	struct word *next;
};

int main(void) {
	char buffer[MAX_WORD_LEN], c;
	int count = 0;

	while ((c = getchar()) == ' ' || c == '\t')
		;
	while (c != '\n') {
		buffer[count++] = c;
		if (c == ' ')
			break;
		c = getchar();
	}
	buffer[count++] = '\0';
}

