#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5

bool straight, flush, four, three;
int pairs;

void read_cards(void);
void print_array(void);
bool check_for_duplicate(int rank, int suit);
//void analyze_hand(int num_in_rank[NUM_RANKS], int num_in_suit[NUM_SUITS]);
//void print_result(void);

int hand[5][2];

int main (void)
{
	for (;;)
	{
		read_cards();
		//print_array();
		return 0;
		//analyze_hand(num_in_rank, num_in_suit);
		//print_result();
	}
}

void read_cards(void)
{
	char ch, rank_ch, suit_ch;
	bool bad_card, first_card = true;
	int cards_read = 0, rank, suit;

	while (cards_read < NUM_CARDS)
	{
		print_array();
		bad_card = false;
		printf("Enter a card: ");
		rank_ch = getchar();
		switch (rank_ch)
		{
			case '0': exit(EXIT_SUCCESS);
			case '2': rank = 0; break;
			case '3': rank = 1; break;
			case '4': rank = 2; break;
			case '5': rank = 3; break;
			case '6': rank = 4; break;
			case '7': rank = 5; break;
			case '8': rank = 6; break;
			case '9': rank = 7; break;
			case 't': case 'T': rank = 8; break;
			case 'j': case 'J': rank = 9; break;
			case 'q': case 'Q': rank = 10; break;
			case 'k': case 'K': rank = 11; break;
			case 'a': case 'A': rank = 12; break;
			default: bad_card = true;
		}
		suit_ch = getchar();
		switch (suit_ch) 
		{
			case 'c': case 'C': suit = 0; break;
			case 'd': case 'D': suit = 1; break;
			case 'h': case 'H': suit = 2; break;
			case 's': case 'S': suit = 3; break;
			default: bad_card = true;
		}
		while ((ch = getchar()) != '\n')
			if (ch != ' ')
				bad_card = true;
		if (bad_card)
			printf("Bad card; ignored\n");
		if (first_card)
		{
			hand[cards_read][0] = rank;
			hand[cards_read][1] = suit;
			first_card = false;
			cards_read++;
			continue;
		}
		if (check_for_duplicate(rank, suit))
		{
			printf("Duplicate card\n");
			hand[cards_read][0] = 0;
			hand[cards_read][1] = 0;
			continue;
		}
		hand[cards_read][0] = rank;
		hand[cards_read][1] = suit;
		cards_read++;
	}
}

bool check_for_duplicate(int rank, int suit)
{
	int i, j;
	printf("rank is %d suit is %d\n", rank, suit);
	for (i = 0; i < 5; i++)
		if (hand[i][0] == rank && hand[i][1] == suit)
			return true;
	return false;
}

void print_array(void)
{
	int i, j;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 2; j++)
			printf("[%d][%d]%d ", i, j, hand[i][j]);
		printf("\n");
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
