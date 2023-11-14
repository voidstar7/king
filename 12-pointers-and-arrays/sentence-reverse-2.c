#include <stdio.h>
#include <string.h>

#define MAX 128

void reverse(char *message);
void swap(char *left, char *right);

int main(void)
{
	char message[MAX];

	printf("Enter a message: ");
	fgets(message, MAX, stdin);
	message[strlen(message) - 1] = '\0';
	reverse(message);
	printf("%s\n", message);
}

void reverse(char *message)
{
	char 
		*left = message, 
		*right = message + (strlen(message) - 1);

	if (strlen(message))
	{
		for (; 
				left != message + ((strlen(message) / 2)); 
				left++, right--)
			swap(left, right);
		return;
	}
	for (; 
			left != right; 
			left++, right--)
		swap(left, right);
}

void swap(char *left, char *right)
{
	char tmp;

	tmp = *left;
	*left = *right;
	*right = tmp;
}

