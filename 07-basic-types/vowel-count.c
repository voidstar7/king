#include <stdio.h>
#include <ctype.h>

#define MAX 128

int compute_vowel_count(const char *sentence);

int main(void)
{
	int count = 0;
	char sentence[MAX];

	printf("Enter a sentence: ");
		fgets(sentence, MAX, stdin);
	printf("Your sentence contains %d vowel(s)\n",
			compute_vowel_count(sentence));
	return 0;
}

int compute_vowel_count(const char *sentence)
{
	int count = 0;
	char c;
	for (; *sentence; sentence++)
	{
		c = tolower(*sentence);
		if (
				c == 'a' ||
				c == 'e' ||
				c == 'i' ||
				c == 'o' ||
				c == 'u' )
			count++;
	}
	return count;
}

