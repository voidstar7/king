#include <stdio.h>

/*
 _ 
|_|
|_|

*/

//void clear digits_array(void);
//void process_digit(int digit, int position);
//void print_digits_array(void);

char digits[10][4];
char segments[10][3][3] =
{
	{ { ' ', '_', ' ' }, { '|', ' ', '|' }, { '|', '_', '|' } }, // 0
	{ { ' ', ' ', ' ' }, { ' ', ' ', '|' }, { ' ', ' ', '|' } }, // 1
	{ { ' ', '_', ' ' }, { ' ', '_', '|' }, { '|', '_', ' ' } }, // 2
	{ { ' ', '_', ' ' }, { ' ', '_', '|' }, { ' ', '_', '|' } }, // 3
	{ { ' ', ' ', ' ' }, { '|', '_', '|' }, { ' ', ' ', '|' } }, // 4
	{ { ' ', '_', ' ' }, { '|', '_', ' ' }, { ' ', '_', '|' } }, // 5
	{ { ' ', '_', ' ' }, { '|', '_', ' ' }, { '|', '_', '|' } }, // 6
	{ { ' ', '_', ' ' }, { ' ', ' ', '|' }, { ' ', ' ', '|' } }, // 7
	{ { ' ', '_', ' ' }, { '|', '_', '|' }, { '|', '_', '|' } }, // 8
	{ { ' ', '_', ' ' }, { '|', '_', '|' }, { ' ', '_', '|' } }  // 9
};

int main(void)
{
	char input[10], ch;
	int i, count = 0;
	printf("Enter digits (10 max): ");
	while (1)
	{
		if (count > 10)
		{
			printf("Too many digits\n");
			return 1;
		}
		ch = getchar();
		if (ch == '\n')
			break;
		input[count] = ch;
		count++;
	}
}

