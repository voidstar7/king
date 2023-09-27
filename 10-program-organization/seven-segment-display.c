#include <stdio.h>

/*
			 0	
			___
	5	 |   |  1
		 |_6_|
  	 |   |  
  4	 |___|  2
			 3

 _ 
|_|
|_|

*/

//void clear digits_array(void);
//void process_digit(int digit, int position);
//void print_digits_array(void);

int main(void)
{
	char a[3][3];
	int i, j;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (i == 0 && (j == 0 || j == 2))
				a[i][j] = ' ';
			else if (j == 1)
				a[i][j] = '_';
			else
				a[i][j] = '|';
	
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			printf("%c", a[i][j]);
		printf("\n");
	}
}
/*
 _ 
|_|
|_|

*/
