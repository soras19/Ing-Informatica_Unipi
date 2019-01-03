#include "compito.h"

int Mappa::conta_segnali()
{
	int num_totale = 0;
	for(int i = 0; i < 3; i++)
		num_totale += num_segnali[i];
	return num_totale;
}

void Mappa::elimina_tutti(elem*& head)
{
	elem* tmp;
	while(head != NULL)
	{
		tmp = head->pun;
		num_segnali[head->c]--;
		if(head->c == VERDE)
			cout << "\n DELETING VERDE\n";
		delete head;
		head = tmp;
	}
}

void Mappa::riduci(int k)
{
	if(k <= 0)
		return;
	int num_totale = 0;
	for(int i = 0; i < 3; i++)
		num_totale += num_segnali[i];
	if(k > num_totale)
		elimina_tutti(head);
	else
	{
		elem* q = head;
		elem* p;
		for(int i = 0; i < num_totale-k; i++)
		{
			p = q;
			q = q->pun;
		}
		elimina_tutti(q);
		p->pun = NULL;
	}
}

ostream& operator << (ostream& os, const Mappa& m)
{
	int num_totale = 0;
	for(int i = 0; i < 3; i++)
		num_totale += m.num_segnali[i];
	os << "Numero di segnali: " << num_totale << endl;
	if(m.num_segnali[ROSSO])
		os << "[" << m.num_segnali[ROSSO] << "] ROSSO" << endl;
	if(m.num_segnali[VERDE])
		os << "[" << m.num_segnali[VERDE] << "] VERDE" << endl; 
	if(m.num_segnali[GIALLO])
		os << "[" << m.num_segnali[GIALLO] << "] GIALLO" << endl;
	return os;
}

Mappa::Mappa()
{
	head = NULL;
	for(int i = 0; i < 3; i++)
		num_segnali[i] = 0;
}

Mappa::~Mappa()
{
	elem* tmp;
	while(head != NULL)
	{
		tmp = head->pun;
		delete head;
		head = tmp;
	}
}

Mappa::Mappa(const Mappa& m)
{
	for(int i = 0; i < 3; i++)
		num_segnali[i] = m.num_segnali[i];
	head = NULL;
	if(m.head)
	{	
		// Pima creo la testa poi itero 
		head = new elem;
		head->pun = NULL;
		head->x = m.head->x;
		head->y = m.head->y;
		head->c = m.head->c;
		
		elem* q = head;
		elem* p = m.head->pun;
		while(p != NULL)
		{
		// Creo un nuovo nodo 
			q->pun = new elem;
			q = q->pun; 
		// Copio i valori nel nodo creato
			q->x = p->x;
			q->y = p->y;
			q->c = p->c;
			q->pun = NULL;
		// Scorro la lista da copiare 
			p = p->pun;
		} 
	}
		
}

void Mappa::aggiungi(colore c, double x, double y)
{
	if(x < 0 || y < 0)
		return;
	if(!head)
	{
	// Caso testa vuota
		head = new elem;
		head->pun = NULL;
		head->x = x;
		head->y = y;
		head->c = c;
	}
	else
	{
		elem* q = head;
		while(q->pun != NULL){
		// L'inserimento fallisce se in posizione x,y
		// c'è già qualcosa
			if(q->x == x && q->y == y)
				return;
			q = q->pun;
		}
		// Aggiungo l'elemento in coda
		q->pun = new elem;
		q = q->pun;
		q->pun = NULL;
		q->x = x;
		q->y = y;
		q->c = c;
	}
	num_segnali[c]++;
	
}

void Mappa::elimina(double x, double y)
{
	if(x < 0 || y < 0 || !head)
		return;
	if(head->x == x && head->y == y)
	{
		delete head;
	}
	else
	{
		elem* q = head;
		elem* p;
		// Scorro la lista con due puntatori affinchè sia in grado
		// di ricollegare la lista se elimino quello in mezzo 
		while(q->pun != NULL)
		{
			p = q;
			q = q->pun;
			if(q->x == x && q->y == y)
			{
				p->pun = q->pun;
				num_segnali[q->c]--;
				delete q;
			}
		}
		
	}
}


