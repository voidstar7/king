#include <stdio.h>
#include <ctype.h>

int main(void)
{
	char c;
	int i;
	int firstWord[26] = { 0 };

	printf("Enter a word: ");
	while (c != 10)
	{
		c = getchar();
		if (!isalpha(c))
			continue;
		c = tolower(c);
		firstWord[c - 'a'] += 1;
	}
	for (i = 0; i < 26; i++)
		printf("%d ", firstWord[i]);
}
