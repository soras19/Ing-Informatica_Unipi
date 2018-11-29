#include "iscrizione.h"

#include <iostream>
#include <cstring>

using namespace std;

void init(elem*& l){
	l = NULL;
}

void visualizza(elem* l){
	cout << "Atleti iscritti:\n";
	if(!l){
		return;
	}
	elem* i = l;
	while(i != NULL){
		cout << i->nome << ", " << i->pettorale << endl;
		i = i->pun;
	}
	cout << endl;
}

int aggiungi(elem*& l, const char* nome, int pettorale){
	if(strlen(nome) > 30)
		return 0;
	if(l == NULL){
		l = new elem;
		l->pun = NULL;
		l->pettorale = pettorale;
		strcpy(l->nome, nome);
		return 1;
	}
	elem* q = l;
	elem* p;
	while(q != NULL){
		p = q;
		if(strcmp(q->nome, nome) == 0 || q->pettorale == pettorale){
			return 0;
		}
		q = q->pun;
	}
	q = new elem;
	q->pun = NULL;
	q->pettorale = pettorale; 
	strcpy(q->nome, nome);
	p->pun = q;
	return 1;
}

int cerca(elem* l, const char* nome){
	if(!l || strlen(nome) > 30)
		return 0;
	elem* q = l;
	while(q != NULL){
		if(strcmp(q->nome, nome) == 0){
			return 1;
		}
		q = q->pun;
	}
	return 0;	
}

int elimina(elem*& l, const char* nome){
	if(!l->pun){
		if(strcmp(l->nome, nome) == 0){
			delete l;
			return 1;
		}
		return 0;
	}
	if(!l || strlen(nome) > 30)
		return 0;
	elem* q = l;
	elem* p=q;
	while(q != NULL){
		if(strcmp(q->nome, nome) == 0){
			// caso: elimina elem dalla testa
			if(p==q){
				l=l->pun;
				delete p;
				return 1;
			}
			elem* tmp = q;
			p->pun = q->pun;
			delete tmp;
			return 1;
		}
		p=q;
		q = q->pun;
	}	
	return 0;
}