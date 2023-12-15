#include <stdio.h>

#ifdef READ_LINE_H
#define READ_LINE_H
#include "readline.h"
#endif

int read_line(char str[], int n) 
{
	int ch, i = 0;
	
	while ((ch = getchar()) != '\n')
		if (i < n)
			str[i++] = ch;
	str[i] = '\0';
	return i;
}	
