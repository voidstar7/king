#include <stdio.h>

/*
 _ 
|_|
|_|

*/

//void clear digits_array(void);
//void process_digit(int digit, int position);
//void print_digits_array(void);

char digits[3][27];
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
	/*
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
	*/
	int i, j;

	digits[0][0] = segments[3][0][0];
	digits[0][1] = segments[3][0][1];
	digits[0][2] = segments[3][0][2];

	digits[1][0] = segments[3][1][0];
	digits[1][1] = segments[3][1][1];
	digits[1][2] = segments[3][1][2];

	digits[2][0] = segments[3][2][0];
	digits[2][1] = segments[3][2][1];
	digits[2][2] = segments[3][2][2];

	digits[0][3] = segments[5][0][0];
	digits[0][4] = segments[5][0][1];
	digits[0][5] = segments[5][0][2];

	digits[1][3] = segments[5][1][0];
	digits[1][4] = segments[5][1][1];
	digits[1][5] = segments[5][1][2];

	digits[2][3] = segments[5][2][0];
	digits[2][4] = segments[5][2][1];
	digits[2][5] = segments[5][2][2];

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 27; j++)
			printf("%c", digits[i][j]);
		printf("\n");
	}
}

