#include <stdio.h>

// calculates the remaining balance on a loan after the first, second, and third monthly payments

int main(void)
{
	float principle, interestRate, monthlyInterestRate, monthlyPayment, first, second, third;

	printf("Enter amount of loan: ");
	scanf("%f", &principle);
	printf("Enter the interest rate: ");
	scanf("%f", &interestRate);
	printf("Enter the monthly payment: ");
	scanf("%f", &monthlyPayment);

	monthlyInterestRate = (interestRate * .01) / 12;

	first = (principle - monthlyPayment);
	first = first * (1 + monthlyInterestRate);
	second = (first - monthlyPayment);
	second = second * (1 + monthlyInterestRate);
	third = (second - monthlyPayment);
	third = third * (1 + monthlyInterestRate);

	printf("Balance remaining after first payment: %.2f\n", first);
	printf("Balance remaining after second payment: %.2f\n", second);
	printf("Balance remaining after third payment: %.2f\n", third );

	return 0;
}
