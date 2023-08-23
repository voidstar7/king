#include <stdio.h>

// prompts for a phone number in (xxx) xxx-xxxx and outputs in xxx.xxx.xxxx
int main (void)
{
	int areaCode, three, four;
	printf("Enter phone number [(xxx) xxx-xxxx]: ");
	scanf("(%d) %d-%d", &areaCode, &three, &four);
	printf("You entered %d.%d.%d\n", areaCode, three, four);
	return 0;
}
