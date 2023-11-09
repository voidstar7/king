#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 50

// calculates the average word length of a sentence to a single decimal point. Punctuation is considered part of a word.

void trim_initial_white_space(char *sentence);
double compute_average(const char *sentence);

int main(void)
{
	char sentence[MAX];
	printf("Enter a sentence: ");
	fgets(sentence, MAX, stdin);
	trim_initial_white_space(sentence);
	puts(sentence);
	//printf("Average word length: %.1lf\n",
	//		compute_average(sentence));
}

void trim_initial_white_space(char *sentence)
{
	char *p = sentence;
	char trimmed[MAX];

	while (*p)
	{
		if (*p == ' ')
		{
			p++;
			continue;
		}
		break;
	}
	strcpy(sentence, strcpy(trimmed, p));
}

double compute_average(const char *sentence)
{

}

