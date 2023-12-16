#include <stdio.h>
#include <string.h>
#include "line.h"

#define MAX_LINE_LEN 60

char line[MAX_LINE_LEN + 1];
char updated_line[MAX_LINE_LEN + 1];
int line_len = 0;
int num_words = 0;
int i;

void clear_line(void)
{
	line[0] = '\0';
	line_len = 0;
	num_words = 0;
}

void add_word(const char *word)
{
	if (num_words > 0)
	{
		line[line_len] = ' ';
		line[line_len + 1] = '\0';
		line_len++;
	}
	strcat(line, word);
	line_len += strlen(word);
	num_words++;
}

int space_remaining(void)
{
	return MAX_LINE_LEN - line_len;
}

int count_spaces(char line[], int len)
{
	int spaces = 0;
	while (*(line++))
		if (*line == ' ')
			spaces++;
	return spaces;
}

void write_line(void)
{
	for (i = 0; i < MAX_LINE_LEN; i++)
		updated_line[i] = '.';
	updated_line[MAX_LINE_LEN] = '\0';

	printf("\nline_len = %d\n", line_len);
	printf("spaces = %d\n", count_spaces(line, line_len));
	int extra_spaces, i, j;

	extra_spaces = MAX_LINE_LEN - line_len;

	printf("extra_spaces: %d\n", extra_spaces);

	for (i = 0; i < line_len; i++)
		putchar(line[i]);
	putchar('\n');

	for (i = 0; i < MAX_LINE_LEN; i++)
		putchar(updated_line[i]);
	putchar('\n');

	copy_line(extra_spaces);
}

void copy_line(int extra_spaces)
{
	char
		*oldLeft = line,
		*oldRight = line + (line_len - 1),
		*newLeft = updated_line,
		*newRight = updated_line + (MAX_LINE_LEN - 1);
	printf("oldLeft = %c\n", *oldLeft);
	printf("oldRight = %c\n", *oldRight);
	printf("newLeft = %c\n", *newLeft);
	printf("newRight = %c\n", *newRight);

	while (newLeft <= newRight)
	{
		if (*oldLeft != ' ')
		{
			*newLeft++ = *oldLeft++;
		}
		else if (*oldLeft == ' ' && extra_spaces > 0)
		{
			*newLeft++ = ' ';
			*newLeft++ = ' ';
			oldLeft++;
			extra_spaces--;
		}
		else
		{
			*newLeft++ = ' ';
			oldLeft++;
		}

		if (*oldRight != ' ')
		{
			*newRight-- = *oldRight--;
		}
		else if (*oldRight == ' ' && extra_spaces > 0)
		{
			*newRight-- = ' ';
			*newRight-- = ' ';
			oldRight--;
			extra_spaces--;
		}
		else
		{
			*newRight-- = ' ';
			oldRight--;
		}
	}




	puts(updated_line);

}

void flush_line(void)
{
	if (line_len > 0)
		puts(line);
}
