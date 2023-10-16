#include <stdio.h>

int main(void)
{
	int len = 0, max = 100, i;
	char message[max], c;
	printf("Enter a message: ");
	while (1)
	{
		c = getchar();
		if (len > max || c == '\n')
			break;
		message[len] = c;
		len++;
	}
	printf("Reversed: ");
	for (i = len; i >= 0; i--)
		printf("%c", message[i]);
	printf("\n");
	return 0;
}
