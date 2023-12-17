#include <stdio.h>
#include <string.h>

#define TOUPPER(c) ('a' <= (c) && (c) <= 'z' ? (c) - 'a' + 'A' : (c))

int main(void)
{
	char s[10];
	char t[10];
	int i = 0;

	strcpy(s, "abcd");
	putchar(TOUPPER(s[1]));

	printf("\n"); 

	strcpy(t, "0123");
	putchar(TOUPPER(t[1]));
}
