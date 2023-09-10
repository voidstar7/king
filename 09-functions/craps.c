#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// on the first roll, the player wins if the sum is 7 or 11
// they lose if the sum is 2, 3, or 12
// any other roll becomes the point and the game continues
// on subsequent rolls, the player wins if they roll the point
// they lose by rolling a 7
// the game continues with any other rolls
// when a game is over, the program records whether or not it was won or lost
// the user is asked if they want to play again (y / n)
// if yes, a new game is initiated
// if no, the number of games won and lost is displayed, then the program exits

int wins = 0, losses = 0, point = 0;
bool firstRoll = true;

int roll_dice(void);
bool play_game(void);

int main(void)
{
	char c;
	srand(time(NULL));

	while (1)
	{
		if (play_game())
			wins++;
		else 
			losses++;
		printf("Play again? (y / n)\n");
		c = getchar();
		if (c == 'y')
		{
			getchar(); // clears LF from input buffer
			firstRoll = true;
			point = 0;
			continue;
		}
		else
		{
			printf("Wins: %d | Losses: %d\n", wins, losses);
			return 0;
		}
	}
}

int roll_dice(void)
{
	int dice1 = rand() % 6 + 1;
	int dice2 = rand() % 6 + 1;
	return dice1 + dice2;
}

bool play_game(void)
{
	int roll;
	while (1)
	{
		roll = roll_dice();
		printf("You rolled %d\n", roll);
		if ((firstRoll == true && (roll == 7 || roll == 11)) || (firstRoll == false && roll == point))
		{
			printf("You win!\n");
			return true;
		}
		else if ((firstRoll == true && (roll == 2 || roll == 3 || roll == 12)) || (firstRoll == false && roll == 7))
		{
			printf("You lose!\n");
			return false;
		}
		else
		{
			if (firstRoll == true)
			{
				point = roll;
				printf("** The point is %d **\n", point);
				firstRoll = false;
				continue;
			}
			continue;
		}
	}
}
