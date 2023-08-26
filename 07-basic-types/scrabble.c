#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int alphabet[26] = { 1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10 };
	int score = 0, position;
	char c;
	printf("Enter a word: ");
	while(1)
	{
		c = getchar();	
		if (isalpha(c))
		{
			if (isupper(c))
				position = (int)c - 65;
			else
				position = (int)c - 97;
			score += alphabet[position];
		}
		else if (c == '\x0a')
			break;
		else
		{
			printf("Invalid entry\n");
			return 1;
		}
	}
	printf("Scrabble value: %d\n", score);
	return 0;
}
