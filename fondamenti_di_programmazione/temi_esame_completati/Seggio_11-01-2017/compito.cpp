#include "compito.hpp"

#include <cstring>
/*
struct elem{
	int id;
	elem* pun;
}

class Seggio{

	elem* l; // Estrazione in testa e inserimento in coda
	int voti[2];// voti[0] favorevoli [1] contrari

public:
	Seggio();
	void nuovoElettore(int id);
	friend ostream& operator<<(ostream& os, const Seggio& s);
	// Seconda Parte
	void nuovoVoto(const char* v);
	void spoglioDeiVoti();
	~Seggio();	
		
}
*/

ostream& operator<<(ostream& os, const Seggio& s){
	os << "Elettori che hanno votato: " << s.n_v << endl;
	if(s.n_v){
		elem* q = s.l_v;
		while(q != NULL){
			os << "->" << q->id;
			q = q->pun;
		}
		os << endl;
	}
	else
		os << endl;
	os << "Elettori in coda: " << s.n_c << endl;
	
	return os;
}

Seggio::Seggio(){
	l = NULL;
	l_v = NULL;
	voti_fav = 0;
	voti_con = 0;
	n_v = 0;
	n_c = 0;
}

void Seggio::nuovoElettore(int id){
	// Caso testa vuota
	if(!l){
		l = new elem;
		l->pun = NULL;
		l->id = id;
		n_c++;
		return;
	}
	// Itero fino alla fine della lista
	elem* q = l;
	elem* p = NULL;
	while(q != NULL){
		// Se l'id è già in coda per votare non faccio nulla
		if(q->id == id)
			return;
		p = q;
		q = q->pun;	
	}
	q = new elem;
	q->id = id;
	q->pun = NULL;
	p->pun = q;
	n_c++;
	
}

void Seggio::nuovoVoto(tipo v){
	if(!l)
		return;
	if(!l_v){
		l_v = l;
		l = l->pun;
		l_v->pun = NULL;
	}
	else{
		elem* p = l_v;
		while(p->pun != NULL)
			p = p->pun;
		p->pun = l;
		p = p->pun;
		l = l->pun;
		p->pun = NULL;
	}
	if(v == favorevole)
		voti_fav++;
	else
		voti_con++;	
	n_v++;
	n_c--;
}

void Seggio::spoglioDeiVoti(){
	if(l != NULL){
		cout << "Spoglio impossibile!" << endl;
		return;
	}
	cout << "Favorevoli: " << voti_fav << endl << "Contrari: " << voti_con << endl;
	if(voti_fav == voti_con)
		cout << "Pareggio!" << endl;
	else if(voti_fav > voti_con)
		cout << "Vittoria dei favorevoli!" << endl;
	else
		cout << "Vittoria dei contrari!" << endl;
	 
}

Seggio::~Seggio(){
	elem* q = l;
	while(l != NULL){
		l = l->pun;
		delete q;
		q = l;
	}
	q = l_v;
	while(l_v != NULL){
		l_v = l_v->pun;
		delete q;
		q = l_v;
	}
}