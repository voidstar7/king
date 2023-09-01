#include <stdio.h>
#include <ctype.h>

int main(void)
{
	char sentence[100];
	char reverseSentence[100];
	char i, j, input;
	int length = 0, wordLength = 0, reverseIndex = 0;

	printf("Enter a sentence: ");
	while (1)
	{
		input = getchar();
		if (input == 10)
			break;
		sentence[length] = input;
		length++;
	}
	for (i = length - 1; i >= 0; i--)
	{
		printf("sentence[%d] is (%c)\n", i, sentence[i]);
		if (isalpha(sentence[i])) 
		{
			wordLength++;
			printf("word length is %d\n", wordLength);
			continue;
		}
		else if (sentence[i] == 32)
		{
			for (j = reverseIndex; j < wordLength; j++)
			{
				reverseSentence[reverseIndex] = sentence[(i + 1) - reverseIndex];
				printf("reverseSentence[%d] is (%c)\n", j, reverseSentence[reverseIndex]);
				reverseIndex++;
			}
			wordLength = 0;
			printf("word length is %d\n", wordLength);
		}
	}
}
