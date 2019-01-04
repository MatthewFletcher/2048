#include "Game.h"
#include "Number.h"
#define ARRAY_SIZE 4

#include <iostream>
#include <cstdlib>
#include <climits>

using namespace std;

Game::Game()
{

}

Game::~Game()
{

}


void Game::initBoard(Number board[ARRAY_SIZE][ARRAY_SIZE])
{

	// for (int i = 0; i < ARRAY_SIZE; ++i)
	// {
	// 	for (int j = 0; j < ARRAY_SIZE; ++j)
	// 	{
			
	// 	}
	// }

	//Initialize 2 squares to 2's
	
	
	srand(time(0));

	board[rand()%4][rand()%4].setdigit(2);
	board[rand()%4][rand()%4].setdigit(2);
}

void Game::printBoard(Number board[ARRAY_SIZE][ARRAY_SIZE])
{
	for (int i = 0; i < ARRAY_SIZE; ++i)
	{
		for (int j = 0; j < ARRAY_SIZE; ++j)
		{

			cout << board[i][j].getdigit() << " ";
		}

		cout << endl;
	}
}


void Game::printShiftMenu()
{

	string dirs[4];
	cout << "\nEnter shift direction:\n"
		<< "w: up \n"
		<< "a: left \n"
		<< "s: right \n"
		<< "d: down \n"

		<< endl << ">>";
}
char Game::getShiftDirection()
{
	printShiftMenu();
	char dir;
	cin >> dir;

	if((dir != 'w') && (dir != 'a') && (dir != 's') && (dir != 'd'))
	{
		cout << "invalid input" << endl;
		return getShiftDirection();
	}

	return dir;
}



bool Game::hasAdjacent(Number board[ARRAY_SIZE][ARRAY_SIZE], char shiftDir)
{

	//Shift horiztonal
	if ((shiftDir == 'a') || (shiftDir == 'd'))
	{
		for (int i = 0; i < ARRAY_SIZE; ++i)
		{
			for (int j = 0; j < ARRAY_SIZE-1; ++j)
			{
				//If cell is 0, ignore it
	 			if(board[i][j].isEmpty())
	 				continue;

				if(board[i][j].getdigit() == board[i][j+1].getdigit())	
					return true;

			}
		}
	}

	//Shift vertical 
	if((shiftDir == 's') || (shiftDir == 'w'))
		{
				for (int j = 0; j < ARRAY_SIZE; ++j)
				{
					for (int i = 0; i < ARRAY_SIZE-1; ++i)
					{
						//If cell is 0, ignore it
			 			if(board[i][j].isEmpty())
			 				continue;
		
		
						if(board[i][j].getdigit() == board[i+1][j].getdigit())	
							return true;
					}
				}
		}
	return false;
}


bool Game::isShifted(Number board[ARRAY_SIZE][ARRAY_SIZE], char shiftDir)
{
	if((shiftDir == 'a') || (shiftDir == 'd'))
	{
		for (int i = 0; i < ARRAY_SIZE; ++i)
		{
			for (int j = 0; j < ARRAY_SIZE-1; ++j)
			{
				if(board[i][j].isEmpty())
				{
					continue;
				}
			
				if(board[i][j+1].isEmpty())
					return false;
			}
		}

		return true;
	}

	return false;
}

void Game::shiftBoard(Number board[ARRAY_SIZE][ARRAY_SIZE], char shiftDir)
{
//	cout << "Board shifted " << shiftDir << endl;

	//This function consists of 2 parts:
	//Part 1: find all adjacent numbers and combine

	if(hasAdjacent(board, shiftDir))
	{
		cout << "Board has adjacent tiles" << endl;
	}
	else
	{
		cout << "Board has no adjacent tiles" << endl;
	}



	//Part 2: Shift all values over to respective side of board


	int asdf = 0;
	while(!isShifted(board, shiftDir)) 
	{
	    for (int i = 0; i < ARRAY_SIZE; ++i)
	    {
	    	for (int j = 0; j < ARRAY_SIZE; ++j)
	    	{
	    			
	    	}
	    }

	    if (asdf>5) break;
	}


	//Arrays to hold 
	int rowCount[ARRAY_SIZE];
	int colCount[ARRAY_SIZE];

	//Initialize arrays to zeros
	for (int i = 0; i < ARRAY_SIZE; ++i)
	{
		rowCount[i], colCount[i] = 0;

	}



	if((shiftDir == 'a') || (shiftDir == 'd'))
	{
		//Count elements in rows with non-zero elements
		for (int i = 0; i < ARRAY_SIZE; ++i)
		{
			for (int j = 0; j < ARRAY_SIZE; ++j)
			{
				if (board[i][j].getdigit())
				{
					rowCount[i]++;
				} 
			}
		}
	}


	// switch(shiftDir)
	// {
	// 	case 'a':
	// 		cout << "Shift left" << endl;
	// 		break;
	// 	case 'd':
	// 		cout << "Shift Right" << endl;
	// 		break;

	// 	case 'w':
	// 		cout << "Shift up" << endl;
	// 		break;

	// 	case 's':
	// 		cout << "Shift down" << endl;
	// 		break;
	// 	default:
	// 		cout << "You should not see this" << endl;
	// }

	cout << "--------------------" << endl;
}


bool Game::doTurn(Number board[ARRAY_SIZE][ARRAY_SIZE])
{

	printBoard(board);
	shiftBoard(board, getShiftDirection());


	//TODO check if game is over and return value
	return false;

}


void Game::playGame()
{
	Number board[ARRAY_SIZE][ARRAY_SIZE];

	cout << "Welcome!" << endl;
	initBoard(board);


	bool isOver = false;

	while(!isOver)
		{
			isOver = doTurn(board);
		}

}