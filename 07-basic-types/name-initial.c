#include <stdio.h>
#include <ctype.h>

#define LENGTH 20

int main(void)
{
	char lastName[LENGTH];
	char c, initial;
	int i, count = 0;
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
	for (i = 0; i < LENGTH; i++)
	{
		c = getchar();
		if (c == 10) // return
			break;
		else
		{
			lastName[i] = c;
			count++;
		}
	}
	for (i = 0; i < count; i++)
		printf("%c", lastName[i]);
	printf(", %c.\n", initial);
	return 0;
}
