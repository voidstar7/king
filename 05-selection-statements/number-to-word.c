#include <stdio.h>
#include <string.h>

// prompts for a two digit number then prints the number in English
int main(void) 
{
	char *oneToNine[] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	char *elevenToNineteen[] = { "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
	char *twentyToNinety[] = { "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
	char *s[25];

	int number;
	while (1)
	{
		printf("Enter a two digit number: "); 
		scanf("%d", &number);
		if (number < 10 || number > 99)
			continue;
		else if (number == 10)
		{
			printf("Ten\n");
			break;
		}
		else if (number >= 10 && number < 20) 
		{
			puts(elevenToNineteen[(number - 10) - 1]);
			break;
		}
		else if (number >= 20) 
		{
			sprintf(
					s, "%s-%s",
					twentyToNinety[(number / 10) - 2],
					oneToNine[(number % 10) - 1]);
			puts(s);
			break;
		}
	}
	return 0;
}
