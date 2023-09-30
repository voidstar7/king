#include <stdio.h>
#include <ctype.h>

/*
 _ 
|_|
|_|

*/

int prompt_for_digits(void);
void process_digits(int digitCount);
void print_digits(void);

char input[10];
char digits[3][36];
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
	process_digits(prompt_for_digits());
	print_digits();
	return 0;
}

int prompt_for_digits(void)
{
	char ch;
	int i, j, count = 0;
	printf("Enter digits (10 max): ");
	while (1)
	{
		if (count > 10)
		{
			count--;
			break;
		}
		ch = getchar();
		if (ch == '\n')
			break;
		else if (!isdigit(ch))
			continue;
		input[count] = ch;
		count++;
	}

	printf("count is %d\ninput: ", count);
	for (i = 0; i < 10; i++)
		printf("%c", input[i]);
	printf("\n");

	return count;
}

void process_digits(int digitCount)
{
/*
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
*/
	
	int i, j, k, pointer = 0;
	printf("digitCount is %d\n", digitCount);
	printf("p = %d\n", pointer);
	for (i = 0; i < digitCount; i++)
	{
		printf(" i = %d\n", i);
		for (j = 0; j < 3; j++)
		{
			printf("  j = %d\n", j);
			for (k = 0; k < 3; k++)
			{
				printf("   k = %d\n", k);
				printf("    p + k = %d\n", pointer + k);
				printf("      input[i] = %d\n", input[i] - '0');

				digits[j][pointer + k] = 
				segments[input[i] - '0'][j][k];
			}
		}
		pointer += 3;
		printf("p = %d\n", pointer);
	}
}

void print_digits(void)
{
	int i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 36; j++)
			printf("%c", digits[i][j]);
		printf("\n");
	}
}


