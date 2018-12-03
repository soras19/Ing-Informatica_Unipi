#ifndef COMPITO_H
#define COMPITO_H

#include <iostream>

using namespace std;

enum tipo{contrario, favorevole};

struct elem{
	int id;
	char v[11];
	elem* pun;
};

class Seggio{
	int n_v;
	int n_c;
	elem* l; // in coda
	elem* l_v; // hanno votato
	int voti_fav;// voti[0] favorevoli [1] contrari
	int voti_con;
public:
	Seggio();
	void nuovoElettore(int id);
	friend ostream& operator<<(ostream& os, const Seggio& s);
	// Seconda Parte
	void nuovoVoto(tipo v);
	void spoglioDeiVoti();
	~Seggio();	
};

#endif // COMPITO_H