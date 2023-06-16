#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"dicegame.h"

int main(int argc, char* argv[])
{
	// Getting the seed to generate a random number each time
	srand((int)time(0));
	// Declaring and initializing all the variables
	int p1 = 0;
	int p2 = 0;
	int i = 0;
	int rounds = 0;
	int dice = 0;
	int points = 0;
	int randomPlayer = 0;
	int roundType = 0;
	// Getting the number of rounds from the user
	printf("Enter the number of rounds: ");
	scanf("%d", &rounds);
	// Calling the function printPlayerPoints()
	printPlayerPoints(p1, p2);
	// Generating a random Player number and calling getRandomNumber()
	randomPlayer = getRandomNumber(1, 2);
	// looping through each of the rounds indicated by the user
	for (i = 1; i <= rounds; i++)
	{
		// calling getRoundType() to generate a random round type
		roundType = getRoundType();
		// calling getRandomNumber() to generate a random number for the dice
		dice = getRandomNumber(1, 6);
		// calling getRandomPoints() to the number of points based on the kind of random round type
		points = getRoundPoints(roundType);
		// printing title for each round
		printf("ROUND %d\n", i);
		printf("--------\n");
		printf("Player\t: %d\n", randomPlayer);
		// calling printRoundInfo() to print each rounds information: the type, dice, and points
		printRoundInfo(roundType, dice, points);

		// MAIN GAME LOGIC
		// Success 
		if ((randomPlayer % 2 == 0) && (dice % 2 == 0))
			p2 += points;
		else if ((randomPlayer % 2 != 0) && (dice % 2 != 0))
			p1 += points;

		// Failure
		else if ((randomPlayer % 2 == 0) && (dice % 2 != 0))
		{
			p2 = p2 - points;
			randomPlayer = 1;
		}
		else if ((randomPlayer % 2 != 0) && (dice % 2 == 0))
		{
			p1 = p1 - points;
			randomPlayer = 2;
		}
		//calling printPLayerPoints() to print the players current points
		printPlayerPoints(p1, p2);
	}
	// printing game over after looping through the rounds and which player won
	printf("\nGAME OVER!!\n");
	if (p1 > p2)
		printf("P1 Won\n");
	else
		printf("P2 Won\n");


	return 0;
}
