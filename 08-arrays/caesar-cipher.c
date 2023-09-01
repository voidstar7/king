#include <stdio.h>

int main(void)
{
	int shift, length = 0;
	char c;
	char alphabet[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
	char message[80];

	printf("Enter message (max 80 chars): ");
	while (1)
	{
		c = getchar();
		if (c == '\x0a')
			break;
		message[length] = c;
		length++;
	}
	printf("Enter shift amount (1-25): ");
	scanf("%d", &shift);
}
