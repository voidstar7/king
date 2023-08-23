#include <stdio.h>
#include <ctype.h>
#define SIZE 100

// prompts for a message, converts letters to uppercase, substitutes some letters for digits, and appends ten exclamation marks
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
		c = toupper(c);
		switch (c)
		{
			case 'A':	message[i] = '4'; break;
			case 'B':	message[i] = '8'; break;
			case 'E':	message[i] = '3'; break;
			case 'I':	message[i] = '1'; break;
			case 'O':	message[i] = '0'; break;
			case 'S':	message[i] = '5'; break;
			default: message[i] = c; break;
		}
		i++;
	}
	for (int j = 0; j < SIZE; j++)
	{
		if (j == '0')
			break;
		printf("%c", message[j]);
	}
	printf("!!!!!!!!!!\n");
	return 0;
}
