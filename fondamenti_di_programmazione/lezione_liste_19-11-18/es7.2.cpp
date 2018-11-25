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
*/
#include <iostream>
#include "stack.h"


int main(){
	Stack<int>* lista = new Stack<int>;
	lista -> push(50);
	lista -> push_back(60);
	lista -> push(70);
	lista -> stampa();
	return 0;	
}