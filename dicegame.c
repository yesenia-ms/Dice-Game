#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"dicegame.h"

int getRandomNumber(int min, int max)
{
	int randomNum = 0;
	randomNum = (rand() % max) + min;
	return randomNum;
}
enum ROUNDTYPE getRoundType()
{
	// declaring variables
	enum ROUNDTYPE roundType;
	int stateNum = 0;
	// generating a random number and saving it in stateNum
	stateNum = getRandomNumber(0, 9);
	// Probability: 50% REGULAR, 20% BONUS, 30% DOUBLE
	// 50% probability
	if ((stateNum >= 0) && (stateNum <= 4))
		roundType = REGULAR;
	// 20% probability
	else if ((stateNum >= 5) && (stateNum <= 6))
		roundType = BONUS;
	// 30% probability
	else if ((stateNum >= 7) && (stateNum <= 9))
		roundType = DOUBLE;
	return roundType;
}
int getRoundPoints(enum ROUNDTYPE roundType)
{
	int roundPoints = 0;
	// called getRandomNumber() to generate a random number between 1 and 10
	// multiply it by 10
	roundPoints = (10 * (getRandomNumber(1,10)));
	// returns roundPoints based on the round type
	// REGULAR round
	if (roundType == 2)
		return roundPoints;
	// BONUS round
	else if (roundType == 0)
	{
		roundPoints = 200;
		return roundPoints;
	}
	// DOUBLE round
	else
		roundPoints = 2 * roundPoints;
		return roundPoints;
}
void printPlayerPoints(int p1, int p2)
{
	printf("P1\t: %d\n", p1);
	printf("P2\t: %d\n\n", p2);
}
void printRoundInfo(enum ROUNDTYPE t, int dice, int points)
{
	//prints the kind of round
	if (t == 2)
		printf("Type\t: REGULAR\n");
	else if (t == 0)
		printf("Type\t: BONUS\n");
	else
		printf("Type\t: DOUBLE\n");
	//prints the dice number
	printf("DICE\t: %d\n", dice);
	// prints the current number of points
	printf("POINTS\t: %d\n", points);
}
