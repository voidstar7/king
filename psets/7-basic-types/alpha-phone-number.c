#include <stdio.h>

// Converts an alphabetic phone number into a numeric one. Assumes that input is in upper case letters. If the original phone number contains digits or punctuation, leaves them unchanged.

int main(void)
{
	char c;
	printf("Enter a phone number: ");	
	while (1)
	{
		c = getchar();
		if (c >= 65 && c <= 90)
		{
			switch (c)
			{
				case 'A': case 'B': case 'C':	printf("2"); break;
				case 'D': case 'E': case 'F':	printf("3"); break;
				case 'G': case 'H': case 'I':	printf("4"); break;
				case 'J': case 'K': case 'L':	printf("5"); break;
				case 'M': case 'N': case 'O':	printf("6"); break;
				case 'P': case 'Q': case 'R':	printf("7"); break;
				case 'S': case 'T': case 'U':	printf("8"); break;
				case 'V': case 'W': case 'X':	printf("9"); break;
				case 'Y': case 'Z':	printf("0"); break;
			}
		}
		else if (c == '\x0a')
			break;
		else
			printf("%c", c);
	}
	printf("\n");
	return 0;
}
