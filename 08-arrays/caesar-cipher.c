#include <stdio.h>
#include <ctype.h>

#define MAX 80

void encrypt(char *message, int shift);

int main(void)
{
	char message[MAX];
	int shift;

	printf("Enter message (max 80 chars): ");
	fgets(message, MAX, stdin);

	printf("Enter shift amount (1-25): ");
	scanf("%d", &shift);
	encrypt(message, shift);
	printf("%s", message);

	return 0;
}

void encrypt(char *message, int shift)
{
	while (*message)
	{
		if (isalpha(*message)) 
		{
			if (isupper(*message))
				*message = ((*message - 'A') + shift) % 26 + 'A';
			else
				*message = ((*message - 'a') + shift) % 26 + 'a';
		}
		message++;
	}
}

