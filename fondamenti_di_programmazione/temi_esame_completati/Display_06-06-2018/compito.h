#ifndef COMPITO_H
#define COMPITO_H

#include <iostream>
using namespace std;

class Display{

	char** m; 		// Matrice che rappresenta il display
	int l, c; 		// Dimensioni matrice
	int cur_pos; 	// Indice della linea attuale
	
	inline void incrementa_pos();
public:
	Display(int L, int C);
	Display(const Display& d);
	void writeT(const char* str);
	friend ostream& operator << (ostream& os, const Display& d);
	// Parte 2
	void writeW(const char* str);
	Display& operator = (const Display& d);
	~Display();
};

#endif
