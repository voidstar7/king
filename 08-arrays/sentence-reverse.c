#include <stdio.h>

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
		printf("input is %c\n", input);
		length++;
	}
	printf("length is %d\n", length);
	for (i = length - 1; i >= 0; i--)
	{
		printf("i is %d\n", i);
		if (sentence[i] != 32) 
		{
			wordLength++;
			//printf("index %d is %c\n", i, sentence[i]);
			printf("word length is %d\n", wordLength);
			continue;
		}
		for (j = reverseIndex; j < wordLength; j++)
		{
			reverseSentence[reverseIndex] = sentence[(i + 1) + j];
			printf("reverse sentence index %d is %c\n", j, reverseSentence[reverseIndex]);
			reverseIndex++;
		}
		reverseSentence[reverseIndex + 1] = '\x20';
		wordLength = 0;
	}
	for (i = 0; i < reverseIndex; i++)
		printf("%c", reverseSentence[i]);
}
