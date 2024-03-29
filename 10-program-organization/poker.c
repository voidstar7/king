#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool straight, flush, four, fullHouse, three, twoPair, onePair, royalFlush;

void read_cards(void);
bool check_for_duplicate(int rank, int suit);
void analyze_hand(void);
void print_result(void);
void clear_hand(void);
void sort_hand(int ranks[5][2]);
int sum_ranks(int ranks[5][2]);

int hand[5][2];
char printHand[5][30];

int main (void)
{
	for (;;)
	{
		read_cards();
		analyze_hand();
		print_result();
		clear_hand();
	}
}

void read_cards(void)
{
	char ch, rank_ch, suit_ch;
	bool bad_card, first_card = true;
	int cards_read = 0, rank, suit;

	while (cards_read < 5)
	{
		bad_card = false;
		printf("Enter a card: ");
		rank_ch = getchar();
		switch (rank_ch)
		{
			case '0': exit(EXIT_SUCCESS);
			case '2': rank = 1; 
								strcpy(printHand[cards_read], "Two of ");
								break;
			case '3': rank = 2;
								strcpy(printHand[cards_read], "Three of "); 
								break;
			case '4': rank = 3;
								strcpy(printHand[cards_read], "Four of ");  
								break;
			case '5': rank = 4;
								strcpy(printHand[cards_read], "Five of ");  
								break;
			case '6': rank = 5;
								strcpy(printHand[cards_read], "Six of ");  
								break;
			case '7': rank = 6;
								strcpy(printHand[cards_read], "Seven of ");  
								break;
			case '8': rank = 7;
								strcpy(printHand[cards_read], "Eight of ");  
								break;
			case '9': rank = 8;
								strcpy(printHand[cards_read], "Nine of ");  
								break;
			case 't': 
			case 'T': rank = 9;
								strcpy(printHand[cards_read], "Ten of ");  
								break;
			case 'j': 
			case 'J': rank = 10;
								strcpy(printHand[cards_read], "Jack of ");  
								break;
			case 'q': 
			case 'Q': rank = 11;
								strcpy(printHand[cards_read], "Queen of ");  
								break;
			case 'k': 
			case 'K': rank = 12;
								strcpy(printHand[cards_read], "King of ");  
								break;
			case 'a': 
			case 'A': rank = 13;
								strcpy(printHand[cards_read], "Ace of ");  
								break;
			default: bad_card = true;
		}
		suit_ch = getchar();
		switch (suit_ch) 
		{
			case 'c': 
			case 'C': suit = 1; 
								strcat(printHand[cards_read], "Clubs");
								break;
			case 'd': 
			case 'D': suit = 2;
								strcat(printHand[cards_read], "Diamonds");
								break;
			case 'h': 
			case 'H': suit = 3; 
								strcat(printHand[cards_read], "Hearts");
								break;
			case 's': 
			case 'S': suit = 4; 
								strcat(printHand[cards_read], "Spades");
								break;
			default: bad_card = true;
		}
		while ((ch = getchar()) != '\n')
			if (ch != ' ')
				bad_card = true;
		if (bad_card)
		{
			printf("Bad card; ignored\n");
			continue;
		}
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
	for (i = 0; i < 5; i++)
		if (hand[i][0] == rank && hand[i][1] == suit)
			return true;
	return false;
}

void analyze_hand(void)
{
	int ranks[5][2];
	int suit, i, j, sum,
			num_consec = 1, suit_consec = 1;
	royalFlush = false;
	straight = false;
	flush = false;
	fullHouse = false;
	four = false;
	three = false;
	twoPair = false;
	onePair = false;

	// check for flush
	suit = hand[0][1];
	for (i = 1; i < 5; i++)
		if (hand[i][1] == suit)
				suit_consec++;
	if (suit_consec == 5)
		flush = true;

	// sort by rank
	sort_hand(ranks);
	sum = sum_ranks(ranks);

	// check for straight
	for (i = 1; i < 5; i++)
		if (ranks[i][0] - 1 == ranks[i - 1][0])
			num_consec++;
	// check for ace low straight
	if (num_consec == 5 || (
			 ranks[0][0] == 1 &&
			 ranks[1][0] == 2 &&
			 ranks[2][0] == 3 &&
			 ranks[3][0] == 4 &&
			 ranks[4][0] == 13 
			))
	{
		straight = true;
		// check for royal flush 
		if (ranks[0][0] == 9 && flush == true)
			royalFlush = true;
		return;
	}
	if (flush == true)
		return;

	// check for four of a kind, full house, three of a kind, and pairs
	if (sum == 7)
		onePair = true;
	if (sum == 9)
		twoPair = true;
	if (sum == 11)
		three = true;
	if (sum == 13)
		fullHouse = true;
	if (sum == 17)
		four = true;
}

void print_result(void)
{
	printf("Your hand:\n");
	for (int i = 0; i < 5; i++)
		printf("%s\n", printHand[i]);
	printf("*** ");

	if (royalFlush) printf("Royal flush");
	else if (straight && flush) printf("Straight flush");
	else if (four) printf("Four of a kind");
	else if (fullHouse) printf("Full house");
	else if (flush) printf("Flush");
	else if (straight) printf("Straight");
	else if (three) printf("Three of a kind");
	else if (twoPair) printf("Two pairs");
	else if (onePair) printf("Pair");
	else printf("High card");

	printf(" ***\n\n");
}

void sort_hand(int ranks[5][2])
{
	int i, j, temp;
	for (int i = 0; i < 5; i++)
		 ranks[i][0] = hand[i][0];

	for (int i = 0; i < 5; i++)
		 ranks[i][1] = 0;

	for (i = 0; i < 4; i++)
	{
		for (j = i + 1; j < 5; j++)
			if (ranks[i][0] > ranks[j][0])
			{
				temp = ranks[i][0];
				ranks[i][0] = ranks[j][0];
				ranks[j][0] = temp;
			}
	}
}

int sum_ranks(int ranks[5][2])
{
	int i, j, sum = 0;
	for (i = 0; i < 5; i++)
		for (j = 0; j < 5; j++)
			if (hand[i][0] == ranks[j][0])
				ranks[j][1]++;

	for (i = 0; i < 5; i++)
		sum += ranks[i][1];

	return sum;
}

void clear_hand(void)
{
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 2; j++)
			hand[i][j] = 0;
}
