#include <stdio.h>

/*
			 0	
			___
	5	 |   |  1
		 |_6_|
  	 |   |  
  4	 |___|  2
			 3

 _ 
|_|
|_|

*/

//void clear digits_array(void);
//void process_digit(int digit, int position);
//void print_digits_array(void);

char segments[10][9] =
{
	{ ' ', '_', ' ', '|', ' ', '|', '|', '_', '|' }, // 0
	{ ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', '|' }, // 1
	{ ' ', '_', ' ', ' ', '_', '|', '|', '_', ' ' }, // 2
	{ ' ', '_', ' ', ' ', '_', '|', ' ', '_', '|' }, // 3
	{ ' ', ' ', ' ', '|', '_', '|', ' ', ' ', '|' }, // 4
	{ ' ', '_', ' ', '|', '_', ' ', ' ', '_', '|' }, // 5
	{ ' ', '_', ' ', '|', '_', ' ', '|', '_', '|' }, // 6
	{ ' ', '_', ' ', ' ', ' ', '|', ' ', ' ', '|' }, // 7
	{ ' ', '_', ' ', '|', '_', '|', '|', '_', '|' }, // 8
	{ ' ', '_', ' ', '|', '_', '|', ' ', '_', '|' }  // 9
};

int main(void)
{
	int input, i, j;
	printf("Enter a number between 0 and 9: ");
	scanf("%d", &input);

	for (j = 0; j < 9; j++)
		if (j == 2 || j == 5 || j == 8)
		{
			printf("%c", segments[input][j]);
			printf("\n");
		}
		else
			printf("%c", segments[input][j]);
	printf("\n");
	return 0;
}

