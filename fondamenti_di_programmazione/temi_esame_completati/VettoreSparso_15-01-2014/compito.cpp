#include "compito.h"

ostream& operator << (ostream& os, const VettoreSparso& v)
{
	elem* q = v.head;
	// [7]{}
	os << "[" << v.dim << "]{";
	while(q)
	{
		os << "(" << q->val << "," << q->i << ")";
		q = q->pun;
	}
	os << "}";
	return os;
}

void VettoreSparso::svuota()
{
	while(head)
	{
		elem* to_delete = head;
		head = head->pun;
		delete to_delete;
	}
}

VettoreSparso& VettoreSparso::operator *= (int k)
{
	if(k == 0)
		svuota();
	else
	{
		elem* q = head;
		while(q != NULL)
		{
			q->val *= k;
			q = q->pun;
		}
	}
}

VettoreSparso::VettoreSparso(int d)
{
	if(d <= 0)
		d = 1;
	head = NULL;
	dim = d;
}

VettoreSparso::~VettoreSparso()
{
	svuota();
}

void VettoreSparso::visualizzaComeDenso()
{
	// Caso vettore vuoto
	if(!head)
	{
		cout << "< ";
		for(int i = 0; i < dim; i++)
		{
			cout << "0 ";
		}
		cout << ">";
	}
	else
	{
		elem* q = head;
		int last_i = 0;
		cout << "< ";
		while(q != NULL)
		{	
			while(q->i - last_i > 0)
			{
				cout << "0 ";
				last_i++;
			}
			cout << q->val << " ";
			last_i++;
			if(q->pun == NULL && q->i != dim-1)
				cout << "0 ";
			q = q->pun;
		}
		cout << ">";
	}
}


void VettoreSparso::reset(int index)
{
	if(index >= dim || index < 0 || !head)
		return;
	// Caso delete della testa
	if(head->i == index)
	{
		elem* to_delete = head;
		head = head->pun;
		delete to_delete;
	}
	else
	{
		elem* q = head;
		elem* p = q;
		while(q != NULL)
		{
			if(q->i == index)
			{
				p->pun = q->pun;
				delete q;
				return;
			}	
			p = q;
			q = q->pun;
		}
	}
}

void VettoreSparso::set(int val, int index)
{
	if(val == 0 || index >= dim || index < 0)
		return;
	// Caso testa vuota
	if(!head)
	{
		head = new elem;
		head->val = val;
		head->i   = index;
		head->pun = NULL;
	}
	// Caso inserimento ordinato in testa
	else if(head->i >= index)
	{
		if(head->i == index)
			head->val = val;
		else
		{
			elem* old_head = head;
			head = new elem;
			head->val = val;
			head->i   = index;
			head->pun = old_head;
		}
	}
	// Caso inserimento in mezzo o in coda
	else 
	{
		elem* q = head;
		elem* p = q;
		while(q != NULL)
		{
			// Se i gia settato lo aggiorno
			if(q->i == index)
			{
				q->val = val;
				return;
			}
			// Inserimento ordinato
			else if(q->i > index)
			{
				p->pun = new elem;
				p = p->pun;
				p->val = val;
				p->i   = index;
				p->pun = q;
				return;
			}
			p = q;
			q = q->pun;
		}
		// Inserimento in coda
		q->pun = new elem;
		q->val = val;
		q->i   = index;
		q->pun = NULL;
	}
}
