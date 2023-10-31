#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// prompts for words until a 4 letter word is entered, then displays the "largest" and "smallest" words entered according to their dictionary order. The max word length is 20 letters.

int main(void)
{
	char input[21], 
			 smallest[21] = {'\0'},
			 largest[21] = {'\0'}; 

	while (strlen(input) != 4)
	{
		printf("Enter word: ");
		scanf("%s", input);
		if (*smallest == '\0')
		{
			strcpy(smallest, input);
			continue;
		}
		if (*largest == '\0')
		{
			if (strcmp(smallest, input) > 0)
				strcpy(smallest, input);
			else
				strcpy(largest, input);
			continue;
		}
		if (strcmp(smallest, input) > 0)
		{
			strcpy(smallest, input);
			continue;
		}
		if (strcmp(largest, input) < 0)
			strcpy(largest, input);
	}
	printf("Smallest word: %s\n", smallest);
	printf("Largest word: %s\n", largest);
	return 0;
}
