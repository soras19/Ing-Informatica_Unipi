#ifndef COMPITO_H
#define COMPITO_H

#include <iostream>
using namespace std;

enum colore{ROSSO = 0, VERDE, GIALLO};

struct elem{
	double x, y;
	colore c;
	elem* pun;
};

class Mappa
{
	elem* head;
	int num_segnali[3]; 
	int conta_segnali();
	void elimina_tutti(elem*& head);
public:
	Mappa();
	Mappa(const Mappa& m);
	void aggiungi(colore c, double x, double y);
	void elimina(double x, double y);
	friend ostream& operator <<(ostream& os, const Mappa& m);
	void riduci(int k);
	~Mappa();
};

#endif
