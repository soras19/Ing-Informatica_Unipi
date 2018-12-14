#ifndef COMPITO_H 
#define COMPITO_H

#include <iostream>

using namespace std;

struct elem{
	char* id;
	bool isCheck;
	elem* pun;		
};

class NastroTrasportatore
{
	
	elem* head;
	void push(char* id);
public:
	NastroTrasportatore();
	void aggiungi(const char* id);
	void rimuovi();
	friend ostream& operator<<(ostream& os, const NastroTrasportatore& n);
	NastroTrasportatore(const NastroTrasportatore& n);
	// PARTE 2
	void controlla(int i);
	operator int() const;
		//dtor
};

#endif