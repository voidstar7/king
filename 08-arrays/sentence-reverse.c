#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(void)
{
	char sentence[100];
	char reverseSentence[100];
	char i, j, input, terminator;
	bool hasTerminator;
	int length = 0, wordLength = 0, reverseIndex = 0, wordStart;

	sentence[0] = '\x02'; // assign STX to first element
	length++;
	printf("Enter a sentence: ");
	while (1)
	{
		input = getchar();
		if (input == '\x0a')
			break;
		sentence[length] = input;
		length++;
	}
	if (ispunct(sentence[length - 1]))
	{
		terminator = sentence[length - 1];
		hasTerminator = true;
	}
	for (i = length; i >= 0; i--)
	{
		if (isalpha(sentence[i]) || ispunct(sentence[i])) 
		{
			wordLength++;
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
		else if (sentence[i] == '\x02')
		{
			wordStart = i + 1;
			for (j = 0; j < wordLength; j++)
			{
				reverseSentence[reverseIndex] = sentence[wordStart + j];
				reverseIndex++;
			}
		}
	}
	printf("Reversal of sentence: ");
	for (i = 0; i < length; i++)
	{
		if (reverseSentence[i] == terminator && reverseSentence[i + 1] == '\x20')
			continue;
		printf("%c", reverseSentence[i]);
	}
	printf("%c", terminator);
	printf("\n");
}
