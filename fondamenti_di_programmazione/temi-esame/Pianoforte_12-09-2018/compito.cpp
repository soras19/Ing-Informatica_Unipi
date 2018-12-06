#include "compito.h"
/*
class Pianoforte{
	char* m;
	int dim;
public:
	Pianoforte(int ott);
	void accordo(const char mano, int tasto);
	Pianoforte& operator-=(const char mano);
	// Seconda Parte
	void nota(const char mano, int tasto;)
	Pianoforte& operator-=(int tasto);
	~Pianoforte();
};

*/

ostream& operator<<(ostream& os, const Pianoforte& p){
	os << p.m ;
	return os;
}

Pianoforte::Pianoforte(int ott){
	if(ott <= 0){
		ott = 1;
		cout << "Valore per ott invalido, inserito 1 di default\n";
	}
	ott *= 12;
	dim = ott;
	m = new char[dim+1];
	for(int i = 0; i < dim; i++)
		m[i] = '-';
	m[dim] = '\0';
	p_s = p_d = 0;
}

Pianoforte::~Pianoforte(){
	delete[] m;
}

void Pianoforte::accordo(const char mano, int tasto){
	// Preme cinque tasti con la  mano 's' o 'd' , es 'd'  = d-d-d-d-d
	if((mano != 'd' && mano != 's') || tasto < 0 || (tasto+10)>=dim)
		return;
	int index = tasto; // se tasto 1 indice di partenza 0
	// Se è occupato
	for(int i = index; i < index+10; i+=2)
		if(m[i] != '-')
			return;
	for(int i = index; i < index+10; i+=2)
		m[i] = mano;
	
}

Pianoforte& Pianoforte::operator-=(const char mano){
	if(mano != 'd'  && mano != 's')
		return *this;
	for(int i = 0; i < dim; i++)
		if(m[i] == mano)
			m[i] = '-';
	return *this;
}

void Pianoforte::void nota(const char mano, int tasto){
	if((mano != 'd' && mano != 's') || tasto < 0 || tasto >= dim)
		return;
	if(m[tasto] == '-')
		m[tasto] = mano;
	
}