#include <stdio.h>

// prompts for taxable income and displays the tax paid in a flat tax system

float calculate_tax(float income);

int main(void) 
{
	float income, tax;
	printf("Enter your income: "); 
	scanf("%f", &income);	
	printf("You pay $%.2f in tax on $%.2f of income\n", calculate_tax(income), income);
}

float calculate_tax(float income)
{
	float tax;
	if (income <= 750.00f)
		tax = (income * .01f);
	else if (income <= 2250.00f)
		tax = (7.50f + ((income - 750.00f) * .02f));
	else if (income <= 3750.00f)
		tax = (37.50f + ((income - 2250.00f) * .03f));
	else if (income <= 5250.00f)
		tax = (82.50f + ((income - 3750.00f) * .04f));
	else if (income <= 7000.00f)
		tax = (142.50f + ((income - 5250.00f) * .05f));
	else
		tax = (230.00f + ((income - 7000.00f) * .06f));
	return tax;
}
