#ifndef COMPITO_H
#define COMPITO_H

#include <iostream>
using namespace std;

// Inizio ore 12:00
// Fine ore

class AlberoDiNatale{

	char** m;
	int piani; // Numero di Piani
public:
	AlberoDiNatale(int N);
	// es: a.aggiungiPallina('R', 3, 0);
	// Aggiunge la pallina di colore 'R', al ramo 0 del piano 3
	void aggiungiPallina(const char c, int p, int r);
	friend ostream& operator << (ostream& os, const AlberoDiNatale& a);
	// SECONDA PARTE
	AlberoDiNatale& operator += (int k);
	const char coloreMassimo() const;
	~AlberoDiNatale();
};


#endif // COMPITO_H
