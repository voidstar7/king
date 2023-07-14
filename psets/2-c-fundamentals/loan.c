#include <stdio.h>

// calculates the remaining balance on a loan after the first, second, and third monthly payments

int main(void)
{
	float principle, interestRate, monthlyPayment, balance;
	int numberPayments;

	printf("Enter amount of loan: "); scanf("%f", &principle);
	printf("Enter the interest rate: "); scanf("%f", &interestRate);
	printf("Enter the monthly payment: "); scanf("%f", &monthlyPayment);
	printf("Enter the number of payments: "); scanf("%d", &numberPayments);

	if (numberPayments <= 0) {
		printf("Balance: %.2f\n", principle);
		return 0;
	}
	float monthlyInterestRate = (interestRate / 100) / 12;
	if (numberPayments == 1)
		return 0;
	for (int i = 1; i <= numberPayments; i++) {
		principle *= 1.0f + monthlyInterestRate;
		balance = principle - monthlyPayment;
		printf("Balance remaining after payment %d: %.2f\n", i, balance);
		principle -= monthlyPayment;
	}
	return 0;
}
