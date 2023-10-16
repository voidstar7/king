#include <stdio.h>

int main(void)
{
	int max = 100, len = 0, i;
	char message[max], c;
	char *ptrMessage = &message[0];

	printf("Enter a message: ");
	while (1)
	{
		c = getchar();
		if (ptrMessage > (message + max) || c == '\n')
			break;
		*(ptrMessage++) = c;
		len++;
	}
	printf("Reversed: ");
	for (i = len; i >= 0; i--)
		printf("%c", message[i]);
	printf("\n");
	return 0;
}
