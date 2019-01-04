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

	//Row iteration
	for (int i = 0; i < ARRAY_SIZE; ++i)
	{
		//Column iteration
		for (int j = 0; j < ARRAY_SIZE; ++j)
		{

			//Set pointers on edge of board to NULL


			//Top of board
			if(i==0) 
			{
				board[i][j].up = NULL;
			}

			//Bottom of board
			if(i==ARRAY_SIZE-1) 
			{
				board[i][j].down = NULL;
			}

			//Left of board
			if(j==0) 
			{
				board[i][j].left = NULL;
			}

			//Right of board
			if(j==ARRAY_SIZE-1) 
			{
				board[i][j].right = NULL;
			}



			//Set directional pointers for everything else
			//Up
			if(i!=0) 
			{
				board[i][j].up = &(board[i-1][j]);
			}

			//Down
			if(i!=ARRAY_SIZE-1) 
			{
				board[i][j].down = &(board[i+1][j]);
			}

			//Left
			if(j!=0) 
			{
				board[i][j].left = &(board[i][j-1]);
			}

			//Right
			if(j!=ARRAY_SIZE-1) 
			{
				board[i][j].right = &(board[i][j+1]);

				//Set next pointer for easier iteration
				board[i][j].next = &(board[i][j+1]);

			}

			else if(i!=ARRAY_SIZE-1)
			{
				board[i][j].next = &(board[i+1][0]);
			}

			else

			{
				board[i][j].next = NULL;
			}

		}
	}

	//Initialize 2 squares to 2's


	bool debug = true;

	if(debug)
	{
		board[0][1].setdigit(2);
		board[1][1].setdigit(2);
	}

	else
	{
	srand(time(0));

	board[rand()%4][rand()%4].setdigit(2);
	board[rand()%4][rand()%4].setdigit(2);
	}
}

void Game::printBoard(Number board[ARRAY_SIZE][ARRAY_SIZE])
{
	Number *temp = &(board[0][0]);

	while ((temp->next != NULL))
	{

		cout << temp->getdigit() << " ";

		if(temp->right == NULL)
		{
			cout << endl;
		}


		if(temp->next != NULL) 
		{
			temp = temp->next;
		}
		if(temp->next == NULL)
		{
			cout << temp->getdigit() << endl;
		}
	}




}


void Game::printShiftMenu()
{

	string dirs[4];
	cout << "\nEnter shift direction:\n"
		<< "w: up \n"
		<< "a: left \n"
		<< "s: down \n"
		<< "d: right \n"

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

	//Shift horizontal
	if ((shiftDir == 'a') || (shiftDir == 'd'))
	{
		
		for (int row_idx = 0; row_idx < ARRAY_SIZE; ++row_idx)
		{

			Number *temp = &(board[row_idx][0]);
			int j = 0;
			while(temp->right!=NULL)
			{
				++j; 

				if(temp->isEmpty())
				{
					temp = temp->right;
					continue;
				}

				if((temp->getdigit() == temp->right->getdigit()))
				{
					return true;
				}
				temp = temp->right;
			}

			
		}


		

	}

	//Shift vertical 
	if ((shiftDir == 'w') || (shiftDir == 's'))
	{
		
		for (int col_idx = 0; col_idx < ARRAY_SIZE; ++col_idx)
		{

			Number *temp = &(board[0][col_idx]);
			
			while(temp->down!=NULL)
			{
				

				if(temp->isEmpty())
				{
					temp = temp->down;
					continue;
				}

				if((temp->getdigit() == temp->down->getdigit()))
				{
					return true;
				}
				temp = temp->down;
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

	    if (++asdf>5) break;
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