#ifndef ANFITEATRO_H
#define ANFITEATRO_H

#include <iostream>
using namespace std;

struct elem{
	int k;
	elem* pun;
};

class Anfiteatro
{
	elem* head;
	int n;
	
public:
	Anfiteatro(int _n);
	Anfiteatro(const Anfiteatro& a);
	// AggiungiMattonelle alla prima colonna con meno mattonelle
	void aggiungiMattonelle(int mattonelle);
	// AggiungiColonna alla fine dell'anfiteatro
	void aggiungiColonna(int mattonelle); 
	// Operatore di uscita del tipo <[0],[0],[0],[0]>
	friend ostream& operator << (ostream& os, const Anfiteatro& a);
	// Eliminna la (j-1)-esima colonna
	void togliColonna(int j);
	Anfiteatro& operator = (const Anfiteatro& a);
	~Anfiteatro();

};

#endif // ANFITEATRO_H
