#include <stdio.h>
#include <ctype.h>

#define debug

// incomplete
int main(void)
{
	char sentence[100];
	char reverseSentence[100];
	char i, j, input;
	int length = 0, wordLength = 0, reverseIndex = 0, wordStart;

	printf("Enter a sentence: ");
	while (1)
	{
		input = getchar();
		if (input == '\x0a')
			break;
		sentence[length] = input;
		length++;
	}
	for (i = length - 1; i >= 0; i--)
	{
		if (isalpha(sentence[i])) 
		{
			wordLength++;
#ifdef debug
		printf("sentence[%d] is %c word length %d\n", i, sentence[i], wordLength);
#endif
			continue;
		}
		else if (sentence[i] == '\x20')
		{
			wordStart = i + 1;
			for (j = 0; j < wordLength; j++)
			{
				reverseSentence[reverseIndex] = sentence[wordStart + j];
				reverseIndex++;
			}
			reverseSentence[reverseIndex] = '\x20';
			reverseIndex++;
			wordLength = 0;
		}
	}
	for (i = 0; i < length; i++)
		printf("%c", reverseSentence[i]);
}
