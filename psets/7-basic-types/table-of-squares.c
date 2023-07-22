#include <stdio.h>

int main(void)
{

// when i is an int, when i goes above 46,340 then i * i is no longer correct. This indicates that the max (signed) int value on this machine is 2,147,483,647 with a size of 4B.

 int n; 
 char c;
 printf("Enter the number of entries of the table: ");
 scanf("%d", &n);
 getchar(); // clears \n from the input buffer in scanf so it isn't used in the while statement below
 for (int j = 1, i = 1; i <= n; j++, i++) {
		printf("%20d%20d\n", i, i * i);
		if (j % 24 != 0) 
			continue;
		do {
			printf("\n%18cPress Enter to continue ...\n", 32);
			c = getchar();
		}
		while (c != '\x0a');
	}
/*
               46338          2147210244
               46339          2147302921
               46340          2147395600
               46341         -2147479015
               46342         -2147386332
               46343         -2147293647
*/
	
// when i is a short and it goes over 181, then i * i is no longer correct. This indicates that the max (signed) short int value on this machine is 32,767 with a size of 2B

// short n;
// printf("Enter the number of entries of the table: ");
// scanf("%hi", &n);
//	for (short i = 1; i <= n; i++) {
//		printf("%20hi%20hi\n", i, (short)(i * i)); 
		// have to explicitly cast to short because during arithmatic operations on types smaller than int  (ex. char, short), the smaller types are promoted to int (according to C99 standard - integer promotion)
//	}
/*
                 179               32041
                 180               32400
                 181               32761
                 182              -32412
                 183              -32047
                 184              -31680
*/

// when i is a long and it goes over 3,037,000,499 then i * i is no longer correct. This indicates that the max (signed) long value on this machine is 9,223,372,036,854,775,807 with a size of 8B.

 // long n;
 // printf("Enter the number of entries of the table: ");
 // scanf("%ld", &n);
// 	for (long i = 3037000497; i <= n; i++) {
// 		printf("%30ld%30ld\n", i, i * i);
// 	}
	/*
	Enter the number of entries of the table: 3037000503 (do this to jump straight to the limit)

                    3037000497           9223372018778247009
                    3037000498           9223372024852248004
                    3037000499           9223372030926249001
                    3037000500          -9223372036709301616
                    3037000501          -9223372030635300615
                    3037000502          -9223372024561299612
                    3037000503          -9223372018487298607
	*/
}
