#include <stdio.h>

// calculates the average word length of a sentence to a single decimal point. Punctuation is considered part of a word.

int main(void)
{
	int letters = 0, words = 0; 
	float average;
	char c;
	printf("Enter a sentence: ");
	while (1)
	{
		c = getchar();
		if (c == 10) // enter
		{
			words += 1;
			break;
		}
		else if (c != 32 && c != 10) // any char except space or enter
		{
			letters += 1;
			continue;
		}
		words += 1; // space
	}
	printf("Average word length: %.1f\n", (float)letters / (float)words);
	return 0;
}
