#include "compito.h"

/*
 struct elem{
	int k;
	elem* pun;
}
class Anfiteatro
{
	
public:
	Anfiteatro(int n);
	Anfiteatro(const Anfiteatro& a);
	// AggiungiMattonelle alla prima colonna con meno mattonelle
	void aggiungiMattonelle(int mattonelle);
	// AggiungiColonna alla fine dell'anfiteatro
	void aggiungiColonna(int mattonelle); 
	// Operatore di uscita del tipo <[0],[0],[0],[0]>
	friend ostream& operator << (ostream& os, const Anfiteatro& a);
	// Eliminna la j-esima colonna
	void togliColonna(int j);
	Anfiteatro& operator = (const Anfiteatro& a);
	~Anfiteatro();

}; 
 */
Anfiteatro& Anfiteatro::operator = (const Anfiteatro& a)
{
	if(this != &a)
	{
		n = a.n;
		if(n > 0)
		{
			head = new elem;
			head->pun = NULL;
			head->k = a.head->k;
			elem* q = head;
			elem* p = a.head->pun;
			for(int i = 1; i < n; i++){
				q->pun = new elem;
				q = q->pun;
				q->k = p->k;
				p = p->pun;
			}
		}
		else
			head = NULL;
	}
	return *this;
		
}
Anfiteatro::Anfiteatro(const Anfiteatro& a)
{
	n = a.n;
	if(n > 0)
	{
		head = new elem;
		head->pun = NULL;
		head->k = a.head->k;
		elem* q = head;
		elem* p = a.head->pun;
		for(int i = 1; i < n; i++){
			q->pun = new elem;
			q = q->pun;
			q->k = p->k;
			p = p->pun;
		}
	}
	else
		head = NULL;
}

void Anfiteatro::togliColonna(int j)
{
	if(j <= 0 || j > n || head == NULL){
		return;
	}
	// Caso eliminazione testa
	if(j == 1){
		elem* tmp = head->pun;
		delete head;
		head = tmp;
	}
	else{
		elem* q = head;
		elem* p;
		// se j è 4 allora farà q=q->pun->pun->pun
		for(int i = 1; i < j; i++){
			p = q;
			q = q->pun;
		}
		// p è il nodo precedente, devo eliminare q e collegare p a q->pun;
		p->pun = q->pun;
		delete q;
	}
	n--;
}

ostream& operator << (ostream& os, const Anfiteatro& a)
{
	elem* q = a.head;
	if(!q){
		os << "<>";
		return os;
	}
	os << "<";
	for(int i = 0; i < a.n-1; i++){
		os << "[" << q->k << "],";
		q = q->pun;
	}
	os << "[" << q->k << "]>";
	return os;
}

void Anfiteatro::aggiungiColonna(int k)
{
	if(k < 0)
		k = 0;
	if(n == 0){
		// Se non ci sono colonne devo gestire il caso di testa vuota
		head = new elem;
		head->pun = NULL;
		head->k = k;
	}
	else{
		elem* q = head;
		// Scorro fino alla fine della lista con q
		while(q->pun != NULL)
			q = q->pun;
		// Aggiungo una colonna di k mattonelle
		q->pun = new elem;
		q = q->pun;
		q->pun = NULL;
		q->k = k;
	}
	n++;
}

void Anfiteatro::aggiungiMattonelle(int mattonelle)
{
	if (mattonelle <= 0 || !head)
			return;
	// Cerco la prima colonna con meno mattonelle
	int min = head->k; 
	elem* p_min = head; // Puntatore alla colonna con meno mattonelle
	elem* q = head->pun;// Iteratore per scorrere la lista fino alla fine  
	for(int i = 1; i < n; i++)
	{
		if(min > q->k)
		{
			min = q->k;
			p_min = q;
		}
		q = q->pun;
	}
	p_min->k += mattonelle;
	
}

Anfiteatro::Anfiteatro(int _n)
{
	// Gestione numero di colonne negativo 
	if(_n <= 0)
		_n = 1;
	n = _n;
	head = new elem;
	head->k = 0;
	head->pun = NULL;
	elem *q = head;
	for(int i = 1; i < n; i++){
		q->pun = new elem;
		q = q->pun;
		q->k = 0;
		q->pun = NULL;
	}
}

Anfiteatro::~Anfiteatro()
{
	if(n > 0){
		elem* q = head;
		for(int i = 0; i < n; i++){
			head = head->pun;
			delete q;
			q = head;
		}
	}
}

