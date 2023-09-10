#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

int roll_dice(void);
int play_game(void);

int main(void)
{
	int roll;
	srand(time(NULL));

	while (1)
	{
		roll = roll_dice();
		printf("You rolled %d\n", roll);
			if (roll == 7 || roll == 11)
			{
				printf("You win!");
				return 0;
			}
			else if (roll == 2 || roll == 3 || roll == 12)
			{
				printf("You lose!");
				return 0;
			}
			else
				continue;
	}
}

int roll_dice(void)
{
	int dice1 = rand() % 6 + 1;
	int dice2 = rand() % 6 + 1;
	return dice1 + dice2;
}
