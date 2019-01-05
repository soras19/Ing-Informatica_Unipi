#ifndef COMPITO_H
#define COMPITO_H
// 22:00
#include <iostream>
using namespace std;
/*
In ogni istante, il semaforo può trovarsi in uno dei
seguenti tre stati: rosso, verde per corsia destra, 
verde per corsia sinistra.
*/

struct elem{
	char* targa;
	elem* pun;
};

class Semaforo{
	elem* destra;
	elem* sinistra;
	int num_destra, num_sinistra;
	int stato; // 0->Rosso, 1->V-Destra, 2->V-Sinistra
	void push_back(elem*& head, const char* t);
	void elimina_lista(elem*& head);
	const char* pop_back(elem*& head);
	bool isPresent(const char* t);
	void scorriCoda();
	void cambiaCorsiaHelp(elem*& head_from, elem*& head_to);
public:
	Semaforo();
	void arrivo(const char* targa, const char d);
	void cambiaStato();
	friend ostream& operator << (ostream& os, const Semaforo& s);
	// Parte 2
	bool cambiaCorsia(const char d);
	operator int() const;
	~Semaforo();
};

#endif
