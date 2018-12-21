#ifndef COMPITO_H
#define COMPITO_H

#include <iostream>
using namespace std;

class VettoreCrescente{

	

	int* v;
	int n;

	void realloca(int nuova_dim);
public:
	VettoreCrescente(int dim);
	void set(int ind, int val);
	friend ostream& operator << (ostream& os, const VettoreCrescente& vettore);
	// PARTE 2
	operator int() const;
	void azzera();
	VettoreCrescente& operator = (const VettoreCrescente& v2);
	~VettoreCrescente();
};

#endif