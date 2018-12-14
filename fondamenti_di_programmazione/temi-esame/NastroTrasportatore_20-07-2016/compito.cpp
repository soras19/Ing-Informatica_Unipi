#include "compito.h"

#include <cstring>

/*
struct elem{
	char* id;
	bool isCheck;
	elem* pun;		
};

class NastroTrasportatore
{
	
	elem* head;
	
	public:
		NastroTrasportatore();
		void aggiungi(const char* id);
		void rimuovi();
		friend ostream& operator<<(ostream& os, const NastroTrasportatore& n);
		NastroTrasportatore(const NastroTrasportatore& n)
		// PARTE 2
		void controlla(int i);
		int operator int() const;
		//dtor
};
*/

ostream& operator<<(ostream& os, const NastroTrasportatore& n)
{
	if(!n.head)
	{
		os << "<vuoto>";
	}
	else
	{
		elem* p = n.head;
		while(p->pun !=NULL)
		{
			os << '(' << p->id << ")=";
		}
		os << '(' << p->id << ")";	
	}	
	return os;
}

NastroTrasportatore::NastroTrasportatore(const NastroTrasportatore& n)
{
	
		if(!n.head)
			head = NULL;
		else
		{
			head = new elem;
			head->pun = NULL;
			strcpy(head->id, n.head->id);
			head->isCheck = n.head->isCheck;
			elem* p = n.head->pun;
			elem* q = head;
			while(p != NULL)
			{
				q->pun = new elem;
				q = q->pun;
				strcpy(q->id, p->id);
				q->isCheck = p->isCheck;
				p = p->pun;
			}
		}	
	
}

NastroTrasportatore::NastroTrasportatore()
{
	head = NULL;
}

void NastroTrasportatore::push(char*  id)
{
	if(!head)
	{
		head = new elem;
		head->pun = NULL;
		head->id = id;
		head->isCheck = false;
	}	
	else
	{
		// Itero fino alla fine della lista
		elem* p = head;
		while(p->pun != NULL)
			p = p->pun;
		p->pun = new elem;
		p = p->pun;
		p->id = id;
		p->isCheck = false;
		p->pun = NULL;
	}
}

void NastroTrasportatore::aggiungi(const char* id)
{
	cout << id << endl;	
	if(!id || strlen(id) == 0)
		return;
	// Controlli sulla stringa
	for(int i = 0; i < strlen(id); i++)
	{
		if(i == 0 && (id[0] < 'A' || id[0] > 'Z'))
			return;
		else if(id != 0 && (id[i] < '0' || id[i] > '9'))
			return;
	}	
	// Se arrivo qua lo aggiungo al nastro trasportatore
	char* new_id = new char[strlen(id)+1];
	strcpy(new_id, id);
	push(new_id);
}

void NastroTrasportatore::rimuovi()
{
	if(!head)
		return;
	if(head->pun == NULL)
		delete head;
	else
	{
		elem* p = head;
		elem* q;
		while(p != NULL){
			q = p;
			p = p->pun;
		}
		delete p;
		q->pun = NULL;
	}
}
