#ifndef COMPITO_H
#define COMPITO_H

#include <iostream>
using namespace std;

enum tipo{BIANCO=0, VERDE, GIALLO, ROSSO};

const int dim;

struct elem
	char nome[21];
	elem* pun;
}

class ProntoSoccorso{

	elem* l[4];	

public:
	ProntoSoccorso();
	void ricovero(const char* nome, tipo liv);	
	int prossimo(char* nome);
	friend ostream& operator<<(ostream& os, const ProntoSoccorso& ps);
	// Seconda parte
	ProntoSoccorso(const ProntoSoccorso& ps);
	friend ProntoSoccorso& operator=(ProntoSoccorso& ps2, const ProntoSoccorso& ps);
	// dtor
};

#endif