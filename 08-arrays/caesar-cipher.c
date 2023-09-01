#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int i, shift, length = 0;
	char c;
	char message[80];
	char cipher[80];

	printf("Enter message (max 80 chars): ");
	while (1)
	{
		c = getchar();
		if (c == '\x0a')
			break;
		message[length] = c;
		length++;
	}
	printf("Enter shift amount (1-25): ");
	scanf("%d", &shift);

	for (i = 0; i < length; i++)
	{
		if (isalpha(message[i])) 
		{
			if (isupper(message[i]))
			{
				cipher[i] = ((message[i] - 'A') + shift) % 26 + 'A';
				continue;
			}
			cipher[i] = ((message[i] - 'a') + shift) % 26 + 'a';
			continue;
		}
		cipher[i] = message[i];
	}
	printf("Encrypted message: ");
	for (i = 0; i < length; i++)
		printf("%c", cipher[i]);
	printf("\n");
	return 0;
}
