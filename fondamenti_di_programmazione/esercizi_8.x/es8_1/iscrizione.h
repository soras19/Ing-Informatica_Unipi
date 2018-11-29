#ifndef ISCRIZIONE_H_INCLUDED
#define ISCRIZIONE_H_INCLUDED

struct elem{
	char nome[31];
	int pettorale;
	elem* pun;
};

void init(elem*& l);
void visualizza(elem* l);
int aggiungi(elem*& l, const char* nome, int p);
int cerca(elem* l, const char* nome);
int elimina(elem*& l, const char* nome);

#endif //ISCRIZIONE_H_INCLUDED