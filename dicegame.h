#ifndef DICEGAME_H
#define DICEGAME_H

enum ROUNDTYPE {BONUS, DOUBLE, REGULAR};
/*
	Function: getRandomNumber
	-------------------------
	Generates a random number

		int min: minimum number in random range
		int max: maximum number in random range
	
		Returns: a random number
*/
int getRandomNumber(int, int);

/*
	Function: getRoundType
	----------------------
	Gets the round type for the round
	
		Returns: an enumeration ROUNDTYPE roundType
*/
enum ROUNDTYPE getRoundType();

/*
	Function: getRoundPoints
	------------------------
	Generates a random number and based on the random number changes the round points
	
		ROUNDTYPE roundType: changes round points based on the roundtype
	
		Returns: updated points based on round type
*/
int gerRoundPoints(enum ROUNDTYPE);

/*
	Function: printPlayerPoints
	---------------------------
	prints current player points for the round	

		p1: the player 1 points
		p2: the player 2 points

*/
void printPlayerPoints(int, int);

/*
	Function: printRoundInfo
	------------------------
	prints the type of round, dice points, and current points
	
		ROUNDTYPE t: the round type
		dice: the dice number
		points: the points
*/
void printRoundInfo(enum ROUNDTYPE, int, int);


#endif
