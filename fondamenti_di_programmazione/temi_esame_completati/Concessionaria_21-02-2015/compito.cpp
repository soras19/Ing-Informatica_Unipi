#include "compito.h"

#include <cstring>
/*
struct elem{
	char* nome;
	elem* pun;
};

class Concessionaria
{
	elem* head;
public:
	Concessionaria();
	Concessionaria& operator += (const char* nome);
	friend ostream& operator << (ostream& os, const Concessionaria& c);
	operator int();
	Concessionaria& operator -= (int k);
	int cerca(const char* str);
	//~Concessionaria();
};
*/

int Concessionaria::cerca(const char* str) const
{
	if(!str || strlen(str) == 0)
		return 0;
	int n_car = 0;
	int len = strlen(str); 
	elem* q = head;
	// Itero tutte le supercar
	while(q != NULL)
	{
		if(strlen(q->nome) == len && strcmp(q->nome, str) == 0)
			n_car++;
		else if(strlen(q->nome) > len)
		{
			for(int i = 0; i < strlen(q->nome) - len; i++)
			{
				if(strncmp(&(q->nome[i]), str, len) == 0)
				{
					n_car++;
					break;
				}
			}
		}
		q = q->pun;
	}
	return n_car;
}

Concessionaria& Concessionaria::operator -= (int k)
{
	if(k > 0)
	{
		if(k > n) // Le elimino tutte
			k = n;
		for(int i = 0; i < k; i++)
		{	
			elem* tmp = head->pun;
			delete head->nome;
			delete head;
			head = tmp;
			n--;
		}
	}
	return *this;
}

ostream& operator << (ostream& os, const Concessionaria& c)
{
	elem* q = c.head;
	os << c.n << ":";
	while(q != NULL)
	{
		os << "=>" << q->nome;
		q = q->pun;
	}
	//os << q->nome;
	return os;
}

Concessionaria::operator int() const
{
	return n;
}

Concessionaria::Concessionaria()
{
	head = NULL;
	n = 0;
}

Concessionaria::~Concessionaria()
{
	while(head)
	{
		elem* to_delete = head;
		head = head->pun;
		delete to_delete->nome;
		delete to_delete;
	}
}

Concessionaria& Concessionaria::operator += (const char* nome)
{
	// Fallisce
	if(!nome || strlen(nome) == 0)
		return *this;
	if(!head)
	{
		head = new elem;
		head->pun = NULL;
		head->nome = new char[strlen(nome)+1];
		strcpy(head->nome, nome);
	}
	else
	{	
		// Faccio un inserimento ordinato così da facilitare
		// l'implementazione di c -= k e del cout
		// Se head->nome viene prima in ordine alfabetico allora
		// strcmp ritorna un valore negativo < 0
		if(strcmp(head->nome, nome) > 0) 
		{
		// Caso inserimento ordinato in testa
			elem* q = head;
			head = new elem;
			head->pun = q;
			head->nome = new char[strlen(nome)+1];
			strcpy(head->nome, nome);
		}
		else
		{
			elem* q = head;
			elem* p;
			while(q->pun != NULL)
			{
				p = q; // p è l'elemento precedente 
				q = q->pun;
			// Caso inserimento nel mezzo della lista	
				if(strcmp(q->nome, nome) > 0)
				{
					p->pun = new elem;
					p = p->pun;
					p->pun = q;
					p->nome = new char[strlen(nome)+1];
					strcpy(p->nome, nome);
					n++;
					return *this;
				}
			}
			// Caso inserimento in coda
			q->pun = new elem;
			q = q->pun;
			q->pun = NULL;
			q->nome = new char[strlen(nome)+1];
			strcpy(q->nome, nome);
		}
	}
	n++;
	return *this;
}
