#ifndef COMPITO_H
#define COMPITO_H

#include <iostream>
using namespace std;

class Display
{
	char** m;
	int N;
	int flag[3]; // 0='-', 1='|', 2='/'
public:
	Display(int n);
	Display(const Display& d2);
	void set(char ch);
	friend ostream& operator << (ostream& os, const Display& d);
	Display& operator |= (const Display& d2);
	void specchia();
	Display& operator = (const Display& d2);
	~Display();
};

#endif 
