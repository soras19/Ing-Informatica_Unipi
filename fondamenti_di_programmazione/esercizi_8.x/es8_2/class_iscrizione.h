#ifndef ISCRIZIONE_H_INCLUDED
#define ISCRIZIONE_H_INCLUDED

struct elem{
	char nome[31];
	int pettorale;
	elem* pun;
};

class Iscrizione{
	elem* l;
public:
	Iscrizione();
	void visualizza();
	int aggiungi(const char* nome, int p);
	int cerca(const char* nome);
	int elimina(const char* nome);		
	
};


#endif //ISCRIZIONE_H_INCLUDED