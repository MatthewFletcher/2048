#ifndef NUMBER_H
#define NUMBER_H

class Number
{
public:
	Number();
	~Number();

	int getdigit();
	void setdigit(int);
	void doubledigit();
	bool isEmpty();


	Number *up;
	Number *down;
	Number *left;
	Number *right;
	Number *next;
private:
	char m_digit;
	
};

#endif // NUMBER_H
