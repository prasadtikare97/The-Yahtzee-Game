// header files
#include "yahtzee_lib.h"
// main program
int main()
{
// initialize program
// initialize the random number generator
initializePlayer();
// declare the variable to store the user's choice
char choice;
// inialize the variable that stores the play
int play = NO_PLAY;
// print a title
printf("\nWelcome to Simple Yahtzee!\n");
printf("==========================\n\n");
// prompt the user for the play
printf("Do you want to roll the dice (y/n): ");
// wait for user input
choice = getChoice();
int dice[NUM_DICE];

int i,j;
while (choice=='y')
	{
	//initializing the random numbers from 1 to 6
	printf("\nYour roll : ");
	 	for (i = 0; i < NUM_DICE; i++)
		{
        dice[i] = rollDice(); // Roll the dice and store the result in the array.
        printf("%d", dice[i]);
		if (i < 4) {
            printf(", "); // Add a comma and space between values except for the last one.
        }
    	}
			printf("\n");
	 	// calling decide play and storing in variable
	 	play = decidePlay(dice);

		// get the play from decide play function and print the message for roll
		 switch (play)
            {
                case YAHTZEE:
                    printf("You rolled a Yahtzee!\n\n");
                    break;
                case FOUR_OF_A_KIND:
                    printf("You rolled a Four of a Kind!\n\n");
                    break;
                case THREE_OF_A_KIND:
                    printf("You rolled a Three of a Kind!\n\n");
                    break;
                case FULL_HOUSE:
                    printf("You rolled a Full House!\n\n");
                    break;
                case L_STRAIGHT:
                    printf("You rolled a Large Straight!\n\n");
                    break;
                case S_STRAIGHT:
                    printf("You rolled a Small Straight!\n\n");
                    break;
                case NO_PLAY:
                    printf("You rolled no particular play.\n\n");
                    break;
            }

		printf("\nPlay again? (y/n): ");
		// Read the choice
		//call get choice function
		choice = getChoice();
	}
// end the program
printf("\nThanks for playing Yahtzee!\n");
// return success
return 0;
}

