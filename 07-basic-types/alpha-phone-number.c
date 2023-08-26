#include <stdio.h>
#include <ctype.h>

#define LENGTH 15

// Converts an alphabetic phone number into a numeric one. Assumes that input is in upper case letters. If the original phone number contains digits or punctuation, leaves them unchanged.

int main(void)
{
	char c;
	char number[LENGTH];
	int i;
	printf("Enter a phone number: ");	
	for (i = 0; i < LENGTH; i++)
	{
		c = getchar();
		if (isalpha(c) || c == '-')
		{
			switch (c)
			{
				case 'A': case 'B': case 'C':	
					number[i] = '2'; 
					break;
				case 'D': case 'E': case 'F':
					number[i] = '3'; 
					break;
				case 'G': case 'H': case 'I':
					number[i] = '4'; 
					break;
				case 'J': case 'K': case 'L':
					number[i] = '5'; 
					break;
				case 'M': case 'N': case 'O':
					number[i] = '6'; 
					break;
				case 'P': case 'Q': case 'R':
					number[i] = '7'; 
					break;
				case 'S': case 'T': case 'U':
					number[i] = '8'; 
					break;
				case 'V': case 'W': case 'X':
					number[i] = '9'; 
					break;
				case 'Y': case 'Z':
					number[i] = '0'; 
					break;
				case '-':
					number[i] = '-';
			}
		}
		else if (isdigit(c))
		{
			number[i] = (int)c;
		}
		else if (c == '\x0a')
			break;
		else
			continue;
	}
	printf("In numeric form: ");
	for (i = 0; i < LENGTH; i++)
		printf("%c", number[i]);
	printf("\n");
	return 0;
}
