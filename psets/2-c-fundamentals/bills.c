#include <stdio.h>

// Write a program that asks the user to enter a U.S. dollar amount and then shows how to pay that amount using the smallest number of $20, $10, $5, and $1 bills

int main(void)
{
	int amount, remainder, twentyBills, tenBills, fiveBills, oneBills;
	printf("Enter a US dollar amount: ");
	scanf("%i", &amount);

	twentyBills = amount / 20; 
	amount = amount - (twentyBills * 20);
	tenBills = amount / 10;
	amount = amount - (tenBills * 10);
	fiveBills = amount / 5;
	amount = amount - (fiveBills * 5);
	oneBills = amount / 1;

	printf("$20 bills: %i\n", twentyBills);
	printf("$10 bills: %i\n", tenBills);
	printf("$5 bills: %i\n", fiveBills);
	printf("$1 bills: %i\n", oneBills);

	return 0;
}
