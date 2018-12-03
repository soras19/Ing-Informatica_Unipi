#ifndef COMPITO_H_INCLUDED
#define COMPITO_H_INCLUDED

#include <iostream>
using namespace std;

const int dim=5;

struct elem{
	char targa[7];
	elem* pun;
};

struct Casello{
	bool aperto;
	int n;	
	elem* testa;
};

class Barriera{

	Casello caselli[dim];
	// Funzioni per interagire con le liste di macchine
	int aggiungi(const char* nome, int min);
	void elimina(int i);
	// Utility
	bool isOkInput(const char* s);
public:
	// PRIMA PARTE
	Barriera();
	void nuovoVeicolo(const char* s);
	bool serviVeicolo(int i);
	friend ostream& operator<<(ostream& os, const Barriera& b);
	// SECONDA PARTE
	int apriOppureChiudi(double mediaIdeale);
	operator int() const;
	~Barriera();
};

#endif //COMPITO_H_INCLUDED