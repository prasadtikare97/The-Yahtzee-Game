#include "yahtzee_lib.h"
void initializePlayer()
{
srand(time(0)); // Using current time for each execution
}

char getChoice()
{
//declaring variables
char variable;
    int number = 0;

    do {
        scanf(" %c", &variable); // Read a character from user input, including leading whitespace.

        // Convert the character to lowercase using the tolower function.
        variable = tolower(variable);

        if (variable == 'y' || variable == 'n') {
            number = 1; // Set validInput to 1 if 'y' or 'n' is entered.
        } 
		else
		{
            printf("Invalid option. Please type 'y' to play or 'n' to exit: ");
        }

    } while (!number);
}
int rollDice()
{
	// return dice number one at a time
	 return  rand() % NUM_DICE +1;

}
void countNumber(const int dice[NUM_DICE], int counts[NUM_SIDES])
{

	// count the occurrence of dices
	int count1 = 0,i,j,k,count2 = 0,count3 = 0,count4 = 0,count5 = 0,count6 = 0;

	// Initialize the counts array to all zeros.
    for ( i = 0; i < NUM_SIDES; i++) {
        counts[i] = 0;
    }

    // Iterate through the dice array and count the occurrences of each number.
    for ( j = 0; j < NUM_SIDES; j++) {
        if (dice[j]== 1){
        	count1++;
		}
		else  if (dice[j]== 2){
        	count2++;
		}
		else  if (dice[j]== 3){
        	count3++;
		}
		else  if (dice[j]== 4){
        	count4++;
		}
		else  if (dice[j]== 5){
        	count5++;
		}
		else  if (dice[j]== 6){
        	count6++;
		}
    }
    counts[0]=count1;
    counts[1]=count2;
    counts[2]=count3;
    counts[3]=count4;
    counts[4]=count5;
    counts[5]=count6;
for ( i = 0; i < NUM_SIDES; i++) {
       printf("\n %d", counts[i]);
    }

}

bool isYahtzee(const int dice[NUM_DICE])
{	// check if it is  a yahtzee else false
	int i;
	for(i=0;i<NUM_DICE;i++)
	{
		if(dice[i] !=dice[0])
		{
			return 0;
		}
	}
	return YAHTZEE;
}

bool isFourOfAKind(const int counts[NUM_SIDES])
{	// check if it is four of a kind else false
int i;
	for(i=0;i<NUM_SIDES;i++)
	{
		if(counts[i] == 4)
		{
			return true;
		}
		else{
			return false;
		}
	}

}

bool hasThreeEqual(const int counts[NUM_SIDES])
{	// check if it is three values are equal
int i;
	for( i=0;i<NUM_SIDES;i++)
		{
			if(counts[i] == 3)
			{
				return true;
			}				
		}
return false;
}

bool hasTwoEqual(const int counts[NUM_SIDES])
{		// check if it is two values are equal
int i;
		for(i=0;i<NUM_SIDES;i++)
		{
			if(counts[i] == 2)
			{
				return true;
			}
		}
		return false;
}

bool isThreeOfAKind(const int counts[NUM_SIDES])
{		// check if it is three of a kind else false
	if(hasThreeEqual(counts) == true  && hasTwoEqual(counts) == false)
	{
		return true;
	}
	else{
		return false;
	}
}

bool isFullHouse(const int counts[NUM_SIDES])
{		// check if it is full house if three and two distinct values are equal else false
	if(hasThreeEqual(counts) == true  && hasTwoEqual(counts) == true)
	{
	return true;
	}
	else
	{
	return false;
	}
}

bool isLargeStraight(const int counts[NUM_SIDES])
{		// check if it is large straight sequence values else false
			if((counts[0] >= 1 && counts[1] >= 1 && counts[2] >= 1 && counts[3] >= 1 && counts[4] >= 1) ||
        		(counts[1] >= 1 && counts[2] >= 1 && counts[3] >= 1 && counts[4] >= 1 && counts[5] >= 1))
			{
        		return true;
			}

	return false;

}

bool isSmallStraight(const int counts[NUM_SIDES])
{	// check if it is small straight sequence values else false
	if ((counts[0] >= 1 && counts[1] >= 1 && counts[2] >= 1 && counts[3] >= 1) ||
        (counts[1] >= 1 && counts[2] >= 1 && counts[3] >= 1 && counts[4] >= 1) ||
        (counts[2] >= 1 && counts[3] >= 1 && counts[4] >= 1 && counts[5] >= 1))
		{
        return true; // Small straight found, return true.
    	}

    return false; // Small straight not found, return false.

}

int decidePlay(const int dice[NUM_DICE])
{		// count the dices
	int count[NUM_SIDES];

		countNumber(dice,count);

		// check the conditions here and pass the appropriate values.
	 	if(isYahtzee(dice) == 1)
		{
			return YAHTZEE;
		}
		else if(isFourOfAKind(count) == true)
		{
			return FOUR_OF_A_KIND;
		}
		else if(isThreeOfAKind(count) == true)
		{
			return THREE_OF_A_KIND;
		}
		else if(isFullHouse(count) == true)
		{
			return FULL_HOUSE;
		}
		else if(isLargeStraight(count) == true)
		{
			return L_STRAIGHT;
		}
		else if(isSmallStraight(count) == true)
		{
			return S_STRAIGHT;
		}
		else
		{
			return NO_PLAY;
		}

}
