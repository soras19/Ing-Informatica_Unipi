#include "mycompito.h"

#include <cstring>
#include <iostream>

using namespace std;


Display::Display(int L, int C){
	if(C<1 || L<1){
		this->L = 5;
		this->C = 8;	
	}
	else{
		this->L = L;
		this->C = C;	
	}
	// Inizializza una matrice di L righe 
	// composta ognuna da C+1 char per il
	// carattere di terminazione stringa 
	// '\0'
	matrix = new char*[L];
	for(int i = 0; i < L; i++)
		matrix[i] = new char[C+1];
}

Display::Display(const Display& d){
	this->L = d.L;
	this->C = d.C;
}

void Display::writeT(const char* str){
	if(!str || indexL == L-1)
		return;
	char* buffer = new char[C+1];
	if(str_size(str) > C){
		strncpy(buffer, str, C);
		buffer[C] = '\0';	
	}
	else{
		strcpy(buffer, str);	
	}
	strcpy(matrix[indexL], buffer);
	indexL++;
	delete buffer;
}

ostream& operator<<(ostream& out, const Display& d){
	for(int i = 0; i < d.indexL; i++){
		out << "[" << i+1 << "]" << d.matrix[i] << endl;
	}
	out << "[" << d.indexL+1 << ">" << endl;
	return out;
}

int Display::str_size(const char* str){
	int size = 0;
	while(str[size] != '\0')
		size++;
	return size;
}
