#include <stdio.h>
#include <ctype.h>

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
	for (i = 0; i < len; i++)
		printf("%c", message[i]);
}
