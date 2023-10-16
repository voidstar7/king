#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

void palindrome_check(char *message, int len);

int main(void)
{
	int max = 100, len = 0, i;
	char message[max], c;

	printf("Enter a message: ");
	while (1)
	{
		c = getchar();
		if (c == '\n' || len > max)
			break;
		else if (!isalpha(c))
			continue;
		message[len++] = c;
	}
	palindrome_check(message, len);
}

void palindrome_check(char *message, int len)
{
	char *ptr;
	for( ptr = (message + len);
			 ptr >= message;
			 ptr--)
	{
		printf("%c", *ptr);
	}
}
