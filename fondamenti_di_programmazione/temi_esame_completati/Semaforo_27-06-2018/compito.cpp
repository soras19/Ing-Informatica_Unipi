#include "compito.h"
#include <cstring>

ostream& operator << (ostream& os, const Semaforo& s)
{
	/* Stampa tipo:
	   <STATO_SEMAFORO>
	   [targhe_destra...
	   [targhe_sinistra...
	*/
	if(s.stato == 0)
		os << "<Rosso>" << endl;
	else if(s.stato == 1)
		os << "<Verde Destra>" << endl;
	else
		os << "<Verde Sinistra>" << endl;
	os << "[";
	elem* q = s.destra;
	if(q){
		while(q->pun != NULL)
		{
			os << q->targa << ',';
			q = q->pun;
		}
		os << q->targa;
	}
	os << endl << "[";
	q = s.sinistra;
	if(q){
		while(q->pun != NULL)
		{
			os << q->targa << ',';
			q = q->pun;
		}
		os << q->targa;
	}
	os << endl;
	return os;
}

bool Semaforo::isPresent(const char* targa)
{
	elem* q = destra;
	while(q != NULL){
		if(strcmp(q->targa, targa) == 0)
			return true;
		q = q->pun;
	}
	q = sinistra;
	while(q != NULL){
		if(strcmp(q->targa, targa) == 0)
			return true;
		q = q->pun;
	}
	return false;
}

Semaforo::operator int() const
{
	return num_destra + num_sinistra;
}

void Semaforo::push_back(elem*& head, const char* targa)
{
	if(!head){
		head = new elem;
		head->pun = NULL;
		head->targa = new char[8];
		strcpy(head->targa, targa);
		head->targa[7] = '\0';
	}
	else{
		elem* q = head;
		while(q->pun != NULL)
			q = q->pun;
		q->pun = new elem;
		q = q->pun;
		q->pun = NULL;
		q->targa = new char[8];
		strcpy(q->targa, targa);
		q->targa[7] = '\0';
	}
}

Semaforo::Semaforo()
{
	destra = NULL;
	sinistra = NULL;
	stato = 0; // Rosso
	num_destra = 0;
	num_sinistra = 0;
}

Semaforo::~Semaforo()
{
	elimina_lista(destra);
	elimina_lista(sinistra);
}

void Semaforo::arrivo(const char* targa, const char d)
{
	if(!targa || strlen(targa) != 7 || (d != 'D' && d != 'S') || isPresent(targa))
		return;
	// Aggiungo macchina in coda alla lista della corsia destra
	if(d == 'D'){
		push_back(destra, targa);
		num_destra++;
	}
	else{
		push_back(sinistra, targa);
		num_sinistra++;
	}
	scorriCoda();
}

void Semaforo::cambiaCorsiaHelp(elem*& head_from, elem*& head_to)
{
	if(!head_from->pun)
	{
	// In questo caso sicuramente non ci sono macchine nella
	// corsia dove si vuole andare
		head_to = head_from;
		head_from = NULL;
	}
	else
	{
		elem* q = head_from;
		elem* p;
	// Prendo il puntatore all'ultima macchina in fila e la sposto
	// alla fine della seconda coda
		while(q->pun != NULL)
		{
			p = q; 
			q = q->pun;
		}
		elem* s = head_to;
		while(s->pun != NULL)
			s = s->pun;
		s->pun = q;
		p->pun = NULL;
	}
} 

bool Semaforo::cambiaCorsia(const char d)
{
	if(d != 'D' && d != 'S')
		return false;
	if(d == 'D')
	{
		if(!destra || num_sinistra >= num_destra)
			return false;
		cambiaCorsiaHelp(destra, sinistra);	
		num_destra--;
		num_sinistra++; 
		
	}
	else
	{
		if(!sinistra || num_sinistra < num_destra)
			return false;
		cambiaCorsiaHelp(sinistra, destra);
		num_sinistra--;
		num_destra++;
	}
	return true;
}

void Semaforo::elimina_lista(elem*& head)
{
	while(head != NULL)
	{
		elem* to_delete = head;
		head = head->pun;
		delete[] to_delete->targa;
		delete to_delete;
	}
}

void Semaforo::cambiaStato()
{
	stato++;
	if(stato >= 3)
		stato = 0;
	scorriCoda();
}

void Semaforo::scorriCoda()
{
	if(stato == 1){
		elimina_lista(destra);
		num_destra = 0;
	}
	else if(stato == 2){
		elimina_lista(sinistra);
		num_sinistra = 0;
	}
}
