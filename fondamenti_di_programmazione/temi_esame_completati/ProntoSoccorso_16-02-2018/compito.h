#ifndef COMPITO_H
#define COMPITO_H

#include <iostream>
using namespace std;

enum tipo{BIANCO=0, VERDE, GIALLO, ROSSO};

const int dim = 4; // numero dei tipi di priorità

struct elem{
	char nome[21];
	elem* pun;
}; // Lista FIFO con push_back ed estrazione in testa

class ProntoSoccorso{
	elem* l[dim];
	int pazienti;
public:
	ProntoSoccorso();
	void ricovero(const char* nome, tipo liv);
	int prossimo(char*& nome);
	friend ostream& operator<<(ostream& os, const ProntoSoccorso& ps);
	// Seconda parte
	ProntoSoccorso& operator=(const ProntoSoccorso& ps);
	ProntoSoccorso(const ProntoSoccorso& ps);
	~ProntoSoccorso();
};

#endif
