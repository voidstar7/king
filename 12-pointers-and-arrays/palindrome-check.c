#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

bool palindrome_check(char message[], int len);

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
		message[len++] = tolower(c);
	}
	if (palindrome_check(message, len))
		printf("Message is a palindrome\n");
	else
		printf("Message is not a palindrome\n");
	return 0;
}

bool palindrome_check(char message[], int len)
{
	char *p = &message[0];
	bool odd;
	int mid = len / 2;
	int end = len - 1;

	if (len % 2 == 1)
		odd = true;
	if (odd)
	{
		while ((p - message) < mid)
		{
			if (*p == *(message + end--))
				p++;
			else
				return false;
		}
		return true;
	}
	// else if len = even
	while ((p - message) <= mid)
	{
		if (*p == *(message + end--))
			p++;
		else
			return false;
	}
	return true;
}
