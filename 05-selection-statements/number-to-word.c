#include <stdio.h>

// prompts for a two digit number then prints the number in English
int main(void) 
{
	int number;
	while (1)
	{
		printf("Enter a two digit number: "); 
		scanf("%2d", &number);
		if (number == 10)
		{
			printf("Ten\n");
			break;
		}
		else if (number >= 10 && number < 20) 
		{
			switch (number % 10) 
			{
				case 1: printf("Eleven\n"); break;
				case 2: printf("Twelve\n"); break;
				case 3: printf("Thirteen\n"); break;
				case 4: printf("Fourteen\n"); break;
				case 5: printf("Fifteen\n"); break;
				case 6: printf("Sixteen\n"); break;
				case 7: printf("Seventeen\n"); break;
				case 8: printf("Eighteen\n"); break;
				case 9: printf("Nineteen\n"); break;
			}
			return 0;
		}
		else if (number >= 20) 
		{
			switch (number / 10) 
			{
				case 2: printf("Twenty-"); break;
				case 3: printf("Thirty-"); break;
				case 4: printf("Forty-"); break;
				case 5: printf("Fifty-"); break;
				case 6: printf("Sixty-"); break;
				case 7: printf("Seventy-"); break;
				case 8: printf("Eighty-"); break;
				case 9: printf("Ninety-"); break;
			}
			switch (number % 10) 
			{
				case 1: printf("one\n"); break;	
				case 2: printf("two\n"); break;	
				case 3: printf("three\n"); break;	
				case 4: printf("four\n"); break;	
				case 5: printf("five\n"); break;	
				case 6: printf("six\n"); break;	
				case 7: printf("seven\n"); break;	
				case 8: printf("eight\n"); break;	
				case 9: printf("nine\n"); break;	
			}
			return 0;
		}
	}
}
