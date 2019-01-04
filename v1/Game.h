#ifndef GAME_H
#define GAME_H
#define ARRAY_SIZE 4
#include "Number.h"

class Game
{
public:
	Game();
	~Game();

	void initBoard(Number[ARRAY_SIZE][ARRAY_SIZE]);
	void printBoard(Number[ARRAY_SIZE][ARRAY_SIZE]);
	void printShiftMenu();
	char getShiftDirection();
	bool hasAdjacent(Number[ARRAY_SIZE][ARRAY_SIZE], char);
	bool isShifted(Number[ARRAY_SIZE][ARRAY_SIZE], char);
	void shiftBoard(Number[ARRAY_SIZE][ARRAY_SIZE], char);


	bool doTurn(Number[ARRAY_SIZE][ARRAY_SIZE]);


	void playGame();

private:

	
};

#endif // GAME_H
