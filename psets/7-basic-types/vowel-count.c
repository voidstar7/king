#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int count = 0;
	char c;
	printf("Enter a sentence: ");
	while (c != '\x0a')
	{
		c = getchar();
		switch(tolower(c))
		{
			case 'a':
				count += 1;
				break;
			case 'e':
				count += 1;
				break;
			case 'i':
				count += 1;
				break;
			case 'o':
				count += 1;
				break;
			case 'u':
				count += 1;
				break;
			default:
				break;
		}
	}
	printf("Your sentence contains %d vowel(s)\n", count);
	return 0;
}
