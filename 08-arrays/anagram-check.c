#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool are_anagrams(const char *word1, const char *word2);
void sort_letters(char *word);

int main(void)
{
	char word1[32], word2[32];

	printf("Enter first word: ");
	scanf("%s", word1);
	printf("Enter second word: ");
	scanf("%s", word2);

	if (are_anagrams(word1, word2))
		printf("The words are anagrams\n");
	else
		printf("The words are not anagrams\n");

	return 0;
}

bool are_anagrams(const char *word1, const char *word2)
{
	char *pw1 = (char *)word1,
			 *pw2 = (char *)word2;

	sort_letters(pw1);
	sort_letters(pw2);

	if (strcmp(pw1, pw2) == 0)
		return true;
	return false;
}

void sort_letters(char *word)
{
	int i, j, tmp,
			len = strlen(word);

	for (i = 0; i < len; i++)
		word[i] = tolower(word[i]);

	for (i = 0; i < len; i++)
		for (j = i + 1; j < len; j++)
			if (word[i] > word[j])
			{
				tmp = word[i];
				word[i] = word[j];
				word[j] = tmp; 
			}
}
