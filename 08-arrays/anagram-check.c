#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(void)
{
	char c;
	int i;
	bool firstWordEntered = false;
	int word[26] = { 0 };

	printf("Enter first word: ");
input:
	while (c != 10)
	{
		c = getchar();
		if (!isalpha(c))
			continue;
		c = tolower(c);
		if (firstWordEntered == false)
		{
			word[c - 'a'] += 1;
			continue;
		}
		word[c - 'a'] -= 1;
	}
	if (firstWordEntered == false)
	{
		c = 0; // clears newline from input buffer
		firstWordEntered = true;
		printf("Enter second word: ");
		goto input;
	}
	for (i = 0; i < 26; i++)
	{
		if (word[i] != 0)
		{
			printf("The words are not anagrams\n");
			return 0;
		}
	}
	printf("The words are anagrams\n");
	return 0;
}
