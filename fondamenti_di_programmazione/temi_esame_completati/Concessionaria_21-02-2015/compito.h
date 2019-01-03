// 19:00 -> 20:00
#ifndef COMPITO_H
#define COMPITO_H

#include <iostream>

using namespace std;

struct elem{
	char* nome;
	elem* pun;
};

class Concessionaria
{
	elem* head;
	int n; // Numero di macchine presenti nella concessionaria
public:
	Concessionaria();
	Concessionaria& operator += (const char* nome);
	friend ostream& operator << (ostream& os, const Concessionaria& c);
	operator int() const;
	Concessionaria& operator -= (int k);
	int cerca(const char* str) const;
	~Concessionaria();
};

#endif
