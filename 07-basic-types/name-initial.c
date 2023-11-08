#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 30

void reverse_name(char *name);

int main(void)
{
	char name[MAX];

	printf("Enter a first and last name: ");
	fgets(name, MAX, stdin);
	reverse_name(name);
	puts(name);
}

void reverse_name(char *name)
{
	char buffer[MAX];
	char initial;
	char *pl = name,
			 *pr = name + ((int)strlen(name) - 2);

	for (;; pl++)
	{
		if (*pl == ' ')
			continue;
		initial = *pl;
		break;
	}

	while (*--pr != ' ')
		;
	pr++;
	strcpy(buffer, pr);
	*(buffer + ((int)strlen(buffer) - 1)) = '\0';
	sprintf(name, "%s, %c.", buffer, initial);
}
