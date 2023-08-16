#include <stdio.h>
#define SIZE 100

// prompts for a message, converts letters to uppercase, substitutes some letters for digits, and appends ten exclamation marks
// A 4
// B 8
// E 3
// I 1
// O 0
// S 5
int main(void)
{
	char message[SIZE] = {0};
	char c;
	int i = 0;
	printf("Enter a message: ");
	while (1)
	{
		c = getchar();
		if (c == 10)
			break;
		message[i] = c;
		i++;
	}
	for (int j = 0; j < SIZE; j++)
	{
		if (j == '0')
			break;
		printf("%c", message[j]);
	}
	printf("\n");
	return 0;
}
