#include <stdio.h>
#include <ctype.h>

int main(void)
{
	char c, initial;
	printf("Enter a first and last name: ");
	initial = getchar();
	while (1)
	{
		c = getchar();
		if (c == 32) // space
			break;
		else
			continue;
	}
	while (1)
	{
		c = getchar();
		if (c == 10) // return
			break;
		else
			putchar(c);
	}
	printf(", %c.\n", initial);
	return 0;
}
