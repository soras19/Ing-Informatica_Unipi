#include "compito.h"
#include <cstring>
/*
enum tipo{BIANCO=0, VERDE, GIALLO, ROSSO};

const int dim = 4; // numero dei tipi di priorità

struct elem{
	char nome[21];
	elem* pun;
}; // Lista FIFO con push_back ed estrazione in testa

class ProntoSoccorso{

	elem* l[dim];

public:
	ProntoSoccorso();
	void ricovero(const char* nome, tipo liv);
	int prossimo(char* nome);
	friend ostream& operator<<(ostream& os, const ProntoSoccorso& ps);
	// Seconda parte
	ProntoSoccorso(const ProntoSoccorso& ps);
	friend ProntoSoccorso& operator=(ProntoSoccorso& ps2, const ProntoSoccorso& ps);
	~ProntoSoccorso();
};
*/

ostream& operator<<(ostream& os, const ProntoSoccorso& ps){
    os << "Numero pazienti: " << ps.pazienti << endl;
    for(int i = dim-1; i >= 0; i--){
        os <<"[CODICE ";
        switch(i){
            case BIANCO:
                os << "BIANCO]" << endl;
                break;
            case GIALLO:
                os << "GIALLO]" << endl;
                break;
            case VERDE:
                os << "VERDE]" << endl;
                break;
            case ROSSO:
                os << "ROSSO]" << endl;
                break;
        }
        if(ps.l[i] != NULL){
            // Se la testa non è vuota itero stampando fino a che il nodo non
            // diventa NULL
            elem* q = ps.l[i];
            while(q != NULL){
                os << "->" << q->nome << endl;
                q = q->pun;
            }
        }
    }

    return os;
}

ProntoSoccorso::ProntoSoccorso(){
    for(int i = 0; i < dim; i++)
        l[i] = NULL;
    pazienti = 0;
}

ProntoSoccorso::~ProntoSoccorso(){
    for(int i = 0; i < dim; i++){
        elem* q = l[i];
        while(l[i] != NULL){
            l[i] = l[i]->pun;
            delete q;
            q = l[i];
        }
    }
}

ProntoSoccorso& ProntoSoccorso::operator=(const ProntoSoccorso& ps){ //
    if(this == &ps)
        return *this;
    // Distruggo le code presenti
    for(int i = 0; i < dim; i++){
        elem* q = l[i];
        while(l[i] != NULL){
            l[i] = l[i]->pun;
            delete q;
            q = l[i];
        }
    }
    // Copio le code
    for(int i = 0; i < dim; i++){
        if(ps.l[i] != NULL){
            elem*& testa = l[i];
            elem* q = ps.l[i];
            elem* p = testa;
            while(q != NULL){
                if(!testa){
                    testa = new elem;
                    testa->pun = NULL;
                    strcpy(testa->nome, q->nome);
                    p = testa;
                }
                else{
                    p -> pun = new elem;
                    p = p->pun;
                    p->pun = NULL;
                    strcpy(p->nome, q->nome);
                }
                q = q->pun;
            }
        }
        else{
            l[i] = NULL;
        }
    }
    pazienti = ps.pazienti;
    return *this;
}

ProntoSoccorso::ProntoSoccorso(const ProntoSoccorso& ps){
    for(int i = 0; i < dim; i++)
        l[i] = NULL;
    for(int i = 0; i < dim; i++){
        if(ps.l[i] != NULL){
            elem*& testa = l[i];
            elem* q = ps.l[i];
            elem* p = testa;
            while(q != NULL){
                if(!testa){
                    testa = new elem;
                    testa->pun = NULL;
                    strcpy(testa->nome, q->nome);
                    p = testa;
                }
                else{
                    p -> pun = new elem;
                    p = p->pun;
                    p->pun = NULL;
                    strcpy(p->nome, q->nome);
                }
                q = q->pun;
            }
        }
        else{
            l[i] = NULL;
        }
    }
    pazienti = ps.pazienti;

}

void ProntoSoccorso::ricovero(const char* nome, tipo liv){
    // Se il nome ha più di 20 caratteri non faccio nulla
    if(strlen(nome) > 20)
        return;
    elem*& testa = l[liv];
    // Caso testa vuota
    if(!testa){
        testa = new elem;
        testa->pun = NULL;
        strcpy(testa->nome, nome);
    }
    // Altrimenti itero fino alla fine
    else{
        elem* q = testa;
        while(q->pun != NULL)
            q = q->pun;
        q->pun = new elem;
        q = q->pun;
        q->pun = NULL;
        strcpy(q->nome, nome);
    }
    pazienti++;
}

int ProntoSoccorso::prossimo(char*& nome){
    int liv;
    for(int i = dim-1; i >= 0; i--){
        if(l[i] != NULL){
            liv = i;
            break;
        }
        else if(i == 0)
            return 0;
    }
    elem*& testa = l[liv];
    nome = new char[21];
    strcpy(nome, testa->nome);
    elem* q = testa;
    testa = testa->pun;
    delete q;
    pazienti--;
    return 1;
}
