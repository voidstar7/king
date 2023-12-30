#include <stdio.h>

#define list_size (int)(sizeof(countries) / sizeof(countries[0])) 

struct country_code
{
	char *country;
	int code;
} countries;

int main(void)
{
	struct country_code countries[] = 
	{
			{"Argentina", 54}, {"Australia", 61},
			{"Brazil", 55}, {"Canada", 1},
			{"China", 86}, {"France", 33},
			{"Germany", 49}, {"India", 91},
			{"Italy", 39}, {"Japan", 81},
			{"Mexico", 52}, {"Netherlands", 31},
			{"Russia", 7}, {"South Africa", 27},
			{"South Korea", 82}, {"Spain", 34},
			{"Sweden", 46}, {"Switzerland", 41},
			{"United Kingdom", 44}, {"United States", 1},
			{"Vietnam", 84}, {"Turkey", 90},
			{"Thailand", 66}, {"Singapore", 65}
	};
	int input, i;

	printf("Enter a country code: ");
	scanf("%d", &input);
	for (i = 0; i < list_size; i++)
	{
		if (input == countries[i].code)
		{
			printf("%s\n", countries[i].country);
			return 0;
		}
	}
	printf("Country not found\n");
	return 1;
}
