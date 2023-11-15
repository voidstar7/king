#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX 128

bool is_palindrome(char *message);

int main(void)
{
	char message[MAX];

	printf("Enter a message: ");
	fgets(message, MAX, stdin);

	message[strlen(message) - 1] = '\0';
	for (int i = 0; i < strlen(message); i++)
		message[i] = tolower(message[i]);

	if (is_palindrome(message))
		printf("Message is a palindrome\n");
	else
		printf("Message is not a palindrome\n");
	return 0;
}

bool is_palindrome(char *message)
{
	char *p = message;
	int 
		len = (int)strlen(message),
		mid = len / 2,
		end = len - 1;

	if (len % 2)
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
	while ((p - message) <= mid)
	{
		if (*p == *(message + end--))
			p++;
		else
			return false;
	}
	return true;
}
