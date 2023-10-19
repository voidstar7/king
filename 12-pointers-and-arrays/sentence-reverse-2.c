#include <stdio.h>

int main(void)
{
	int max = 100, len = 0;
	char message[max], c, *p;
	printf("Enter a message: ");
	while (1)
	{
		c = getchar();
		if (message > (message + max) || c == '\n')
			break;
		*(message + len) = c;
		len++;
	}
	printf("Reversed: ");
	for (p = message + len; p >= message; p--)
		printf("%c", *p);
	printf("\n");
	return 0;
}
