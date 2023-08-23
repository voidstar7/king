#include <stdio.h>

int main(void)
{
	int itemNumber, month, date, year;
	float price;

	printf("Enter item number: ");
	scanf("%d", &itemNumber);
	printf("Enter unit price: ");
	scanf("%f", &price);
	printf("Enter purchase date (mm/dd/yyyy): ");
	scanf(" %d / %d / %d", &month, &date, &year);

	printf("Item\t\tUnit\t\tPurchase\n \t\tPrice\t\tDate\n%d\t\t$%7.2f\t%d/%d/%d\n", itemNumber, price, month, date, year);

	return 0;
}
