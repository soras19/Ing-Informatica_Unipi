#ifndef COMPITO_H
#define COMPITO_H

#include <cstring>
#include <iostream>

using namespace std;

class Display{

	// L=Righe, C=Caratteri
	int L, C;
	// Matrice dinamica per conservare le stringe  
	// di ogni riga
	char** matrix;
	// Indice per la riga attuale
	int indexL;
	
	friend ostream& operator<<(ostream& out, const Display& d);
	//friend ostream& operator<<(ostream& os, const Display& d);
	// Funzioni di utility
	int str_size(const char* str);

	public:	
	Display(int L, int C);
	Display(const Display& d);
	void writeT(const char* str);
	int getIndexL(){return indexL;}

};

#endif
