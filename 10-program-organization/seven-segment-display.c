#include <stdio.h>
#include <ctype.h>

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
	return count;
}

void process_digits(int digitCount)
{
	int i, j, k, pointer = 0;
	for (i = 0; i < digitCount; i++)
	{
		for (j = 0; j < 3; j++)
			for (k = 0; k < 3; k++)
				digits[j][pointer + k] = segments[input[i] - '0'][j][k];
		pointer += 3;
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
