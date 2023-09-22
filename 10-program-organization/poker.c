#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5

bool straight, flush, four, three;
int pairs;

void read_cards(void);
//void analyze_hand(int num_in_rank[NUM_RANKS], int num_in_suit[NUM_SUITS]);
//void print_result(void);

int hand[5][2];

int main (void)
{
	for (;;)
	{
		read_cards();
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 2; j++)
				printf("[%d][%d]%d ", i, j, hand[i][j]);
			printf("\n");
		}
		return 0;
		//analyze_hand(num_in_rank, num_in_suit);
		//print_result();
	}
}

void read_cards(void)
{
	char ch, rank_ch, suit_ch;
	bool bad_card;
	int cards_read = 0;

	while (cards_read < NUM_CARDS)
	{
		bad_card = false;
		printf("Enter a card: ");
		rank_ch = getchar();
		switch (rank_ch)
		{
			case '0': exit(EXIT_SUCCESS);
			case '2': hand[cards_read][0] = 0; break;
			case '3': hand[cards_read][0] = 1; break;
			case '4': hand[cards_read][0] = 2; break;
			case '5': hand[cards_read][0] = 3; break;
			case '6': hand[cards_read][0] = 4; break;
			case '7': hand[cards_read][0] = 5; break;
			case '8': hand[cards_read][0] = 6; break;
			case '9': hand[cards_read][0] = 7; break;
			case 't': case 'T': hand[cards_read][0] = 8; break;
			case 'j': case 'J': hand[cards_read][0] = 9; break;
			case 'q': case 'Q': hand[cards_read][0] = 10; break;
			case 'k': case 'K': hand[cards_read][0] = 11; break;
			case 'a': case 'A': hand[cards_read][0] = 12; break;
			default: bad_card = true;
		}
		suit_ch = getchar();
		switch (suit_ch) 
		{
			case 'c': case 'C': hand[cards_read][1] = 0; break;
			case 'd': case 'D': hand[cards_read][1] = 1; break;
			case 'h': case 'H': hand[cards_read][1] = 2; break;
			case 's': case 'S': hand[cards_read][1] = 3; break;
			default: bad_card = true;
		}
		while ((ch = getchar()) != '\n')
			if (ch != ' ')
				bad_card = true;
		if (bad_card)
			printf("Bad card; ignored\n");
		else 
			cards_read++;
	}
}
/*
void analyze_hand(int num_in_rank[NUM_RANKS], int num_in_suit[NUM_SUITS])
{
	int num_consec = 0;
	int rank, suit;
	straight = false;
	flush = false;
	four = false;
	three = false;
	pairs = 0;

	// check for flush
	for (suit = 0; suit < NUM_SUITS; suit++)
		if (num_in_suit[suit] == NUM_CARDS)
			flush = true;

	// check for straight
	rank = 0;
	while (num_in_rank[rank] == 0)
		rank++;
	for (; rank < NUM_RANKS && num_in_rank[rank] > 0; rank++)
		num_consec++;
	if (num_consec == NUM_CARDS)
	{
		straight = true;
		return;
	}

	// check for four of a kind, three of a kind, and pairs
	for (rank = 0; rank < NUM_RANKS; rank++)
	{
		if (num_in_rank[rank] == 4) four = true;
		if (num_in_rank[rank] == 3) three = true;
		if (num_in_rank[rank] == 2) pairs++;
	}
}

void print_result(void)
{
	if (straight && flush) printf("Straight flush");
	else if (four) printf("Four of a kind");
	else if (three && pairs == 1) printf("Full house");
	else if (flush) printf("Flush");
	else if (straight) printf("Straight");
	else if (three) printf("Three of a kind");
	else if (pairs == 2) printf("Two pairs");
	else if (pairs == 1) printf("Pair");
	else printf("High card");

	printf("\n\n");
}
*/
