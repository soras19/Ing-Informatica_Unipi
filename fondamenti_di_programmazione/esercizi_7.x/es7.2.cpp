/*
Es. 7.2 – Liste 1
PRIMA PARTE:
Scrivere un programma che:
 crea una lista di interi vuota;
 inserisce l’intero 50 nella lista;
 inserisce l’elemento 60 in fondo alla lista;
 inserisce l’elemento 70 in testa alla lista.
Debuggare le singole operazioni con il debugger visuale DDD.
SECONDA PARTE:
Scrivere la funzione stampa() che prende per argomento un lista di interi e ne
stampa a video gli elementi.
Estendere il programma per:
 invocare la funzione stampa() sulla lista appena creata;
 eliminare il secondo elemento dalla lista;
 invocare nuovamente la funzione stampa() sulla lista.
Output di esempio:
70 50 60
70 60
*/
#include <iostream>

using namespace std;

struct nodo{
    int data;
    nodo* next;
};
typedef nodo* Lista;

inline void inizialiazza(Lista& s){
    s = NULL;
}

void inserisci_in_fondo(Lista& testa, int data);
//Lista inserisci_in_testa2(Lista& testa, int data);
void inserisci_in_testa(Lista& testa, int data);

int main(int argc, char const *argv[]) {
    Lista head = NULL;
    inserisci_in_fondo(head, 50);
    inserisci_in_fondo(head, 60);
    inserisci_in_testa(head, 70);
    Lista i = head;
    cout << "[";
    while(i != NULL){
        cout << i->data << ", ";
        i = i->next;

    }
    cout << "]\n";
    //cout << "\n SONO QUA\n";
    return 0;
}

void inserisci_in_fondo(Lista& testa, int data){
    Lista& i = testa;
    while(i != NULL){
        //cout <<"LIST: " << i->data << "->";
        i = i->next;

    }

    i = new nodo;
    i->next = NULL;
    i->data = data;

    //cout <<"LIST: " << i->data << "->";
}

void inserisci_in_testa(Lista& testa, int data){
    nodo* tmp = new nodo;
    tmp->data = data;
    tmp->next = testa;
    testa = tmp;
}

/*Lista inserisci_in_testa2(Lista& testa, int data){
    Lista new_testa = new nodo;
    new_testa->next = testa;
    new_testa->data = data;
    return new_testa
}*/
