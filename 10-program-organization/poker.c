#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5

bool straight, flush, four, three;
int pairs;

void read_cards(void);
bool check_for_duplicate(int rank, int suit);
void analyze_hand(void);
void print_result(void);
void print_array(int array[][2], int row);

int hand[5][2];

int main (void)
{
	for (;;)
	{
		read_cards();
		analyze_hand();
		print_result();
	}
}

void read_cards(void)
{
	char ch, rank_ch, suit_ch;
	bool bad_card, first_card = true;
	int cards_read = 0, rank, suit;

	while (cards_read < NUM_CARDS)
	{
		print_array(hand, 5);
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

void analyze_hand(void)
{
	int num_consec = 1, suit_consec = 1;
	int suit, i, j;
	straight = false;
	flush = false;
	four = false;
	three = false;
	pairs = 0;

	// check for flush
	suit = hand[0][1];
	for (i = 1; i < NUM_CARDS; i++)
		if (hand[i][1] == suit)
				suit_consec++;
	if (suit_consec == NUM_CARDS)
		flush = true;

	// check for straight
	for (i = 1; i < NUM_CARDS; i++)
		if (hand[i][0] - 1 == hand[i - 1][0])
			num_consec++;
	if (num_consec == NUM_CARDS)
	{
		straight = true;
		return;
	}

	// check for four of a kind, three of a kind, and pairs
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

void print_array(int array[][2], int row)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 2; j++)
			printf("[%d][%d]%d ", i, j, array[i][j]);
		printf("\n");
	}
}
