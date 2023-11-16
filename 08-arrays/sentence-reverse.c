#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 30
#define MAX_LEN 20

char terminator;

int process_sentence(char *input, char words[][MAX_LEN]);

int main(void)
{
	int count, i;
	char words[MAX_WORDS][MAX_LEN];
	char input[MAX_WORDS * MAX_LEN];

	printf("Enter a sentence: ");
	fgets(input, MAX_WORDS * MAX_LEN, stdin);
	count = process_sentence(input, words);

	if (terminator)
		words[0][strlen(words[0])] = terminator;

	for (i = count; i >= 0; i--)
		printf("%s ", words[i]);
	printf("\n");
	return 0;
}

int process_sentence(char *input, char words[][MAX_LEN])
{

	if (ispunct(*(input + (strlen(input) - 2))))
	{
		terminator = *(input + (strlen(input) - 2));
		*(input + (strlen(input) - 2)) = '\0';
	}
	else
		*(input + (strlen(input) - 1)) = '\0';

	if (terminator)
		printf("terminator: %c\n", terminator);
	for (int i = 0; i <= strlen(input); i++)
		printf("%p - %d\n", &input[i], input[i]);

	int i = 0;
	char 
		*p = input,
		*q = input;
	while (*p)
	{
		if (*p == ' ')
		{
			*p = '\0';
			strcpy(words[i++], q);
			q += ((p - q) + 1);
			//printf("%p\n", &*q);
		}
		p++;
	}
	strcpy(words[i], q);
	return i;
}
