#include <stdio.h>

// Converts an alphabetic phone number into a numeric one. Assumes that input is in upper case letters. If the original phone number contains digits or punctuation, leaves them unchanged.

/*
	2=ABC 
	3=DEF
	4=GHI
	5=JKL 
	6=MNO 
	7=PRS 
	8-TUV 
	9=WXY
*/

int main(void)
{
	char c;
	int digit, sum = 0, count = 0;
	printf("Enter a phone number: ");	
	do
	{
		c = getchar();
		switch (c)
		{
			case 'A': 
			case 'B':
			case 'C':	digit = 2;
								break;
		}
		if (sum == 0)
		{
			sum += digit; count++;
			continue;
		}
	}
	while (c != '\x0a');
	printf("%d\n", sum);
}
