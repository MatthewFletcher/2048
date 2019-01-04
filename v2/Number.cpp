#include "Number.h"
#include <iostream>
using namespace std;

Number::Number()
{


	this->m_digit = 0;


	this->up = NULL;
	this->down = NULL;
	this->right = NULL;
	this ->left = NULL;

	this->next = NULL;
	//cout << "Num init" << endl;

}


Number::~Number()
{

}


int Number::getdigit()
{
	return m_digit;
}

void Number::setdigit(int digit)
{
	m_digit = digit;
}


void Number::doubledigit()
{
	m_digit *= 2;
}


bool Number::isEmpty()
{
	return (this->m_digit == 0);


}