#include <stdio.h>

// Converts an alphabetic phone number into a numeric one. Assumes that input is in upper case letters. If the original phone number contains digits or punctuation, leaves them unchanged.

int main(void)
{
	char c;
	int digit, sum = 0;
	printf("Enter a phone number: ");	
	do
	{
		c = getchar();
		switch (c)
		{
			case 'A': case 'B': case 'C':	digit = 2; break;
			case 'D': case 'E': case 'F':	digit = 3; break;
			case 'G': case 'H': case 'I':	digit = 4; break;
			case 'J': case 'K': case 'L':	digit = 5; break;
			case 'M': case 'N': case 'O':	digit = 6; break;
			case 'P': case 'Q': case 'R':	digit = 7; break;
			case 'S': case 'T': case 'U':	digit = 8; break;
			case 'V': case 'W': case 'X':	digit = 9; break;
			case 'Y': case 'Z':						digit = 0; break;
			case '\x0a': goto end;

		}
		if (sum == 0)
		{
			sum += digit; 
			continue;
		}
		sum = digit + (sum * 10); 
	}
	while (c != '\x0a');
	end:
		printf("%d\n", sum);
}
