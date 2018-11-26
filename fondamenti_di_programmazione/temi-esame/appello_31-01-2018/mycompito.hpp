#ifndef COMPITO_H
#define COMPITO_H

#include <iostream>
using namespace std;

enum COLORE{ROSSO = 1, VERDE, BLU};

class AlberoDiNatale{
	int n_piani;
	int** piani;
	friend ostream& operator<<(ostream& out, const AlberoDiNatale& a);

public:
	AlberoDiNatale(int N);
	// Fallisce se il ramo è occupato da un'altra pallina
	// oppure se una pallina dello stesso colore è già presente
	// in un ramo adiacente dello stesso piano
	void aggiungiPallina(const char ci, int ramo, int i_piano);
	
};

#endif 