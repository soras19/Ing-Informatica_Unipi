#include "mycompito.h"
#include <cstring>

/*
enum Importanza{ bianco=0, verde, giallo, rosso};

struct Paziente{
	char[21] nome;
	Importanza importanza;
	nodo* next;
};

*/

ProntoSoccorso::ProntoSoccorso(){
	head = NULL;
	numero_pazienti = 0;
}	
/* 	Funzione che ritorna la dimensione della stringa str, 
	Utilizzata per gestire eventuali errori causati da un
	nome in input di dimensione maggiore di 21
*/
unsigned int check_size(const char*& str){
	unsigned int size = 0;	
	while(str[size] != '\0'){
		size++;	
	}
	return size
}

// Ricovera il paziente di nome [nome] con importanza [liv]
void ProntoSoccorso::ricovero(const char*& nome, const Importanza& liv){
	unsigned int dim_nome = check_size(nome);
	if(dim_nome == 0){
		cerr << "\nErrore: nome inserito non valido, il nome non puo' essere vuoto\n";
		return;
	}
	// Itero la lista FIFO fino in fondo 
	for(Paziente* i = root; i != NULL; i = i->next){
		// Se il puntatore è nullo inizializzo un nuovo paziente
		if(!i){
			i = new Paziente;
			i->next = NULL;
			i->importanza = liv;
			// Se la dimensione della stringa [nome] è maggiore di 20 
			// copio solo i primi 20 caratteri e alla fine dell'array
			// nome inserisco il carattere di terminazione stringa
			if(dim_nome > 20){
				strncpy(i->nome, nome, 20);
				i->nome[20] = '\0';
			} 
			else{
				strcpy(i->nome, nome);			
			}
		}
	}
	numero_pazienti++;
}

// Ritorna 0 se non ci sono pazienti in attesa, altrimenti 1
int ProntoSoccorso::prossimo(char*& nome){
	if(!root)
		return 0;
	// Inizializzo il puntatore al paziente più urgente	
	Paziente* paz = root;
	Paziente* precedente = root;
	for(Paziente* i = root->next; i != NULL; i = i->next){
		// Se il paziente attuale è in codice rosso non 
		// c'è bisogno di controllare i successivi
		if(paz->importanza == rosso){
			strcpy(nome, paz->nome);
			elimina(precedente, paz);
			return 1;
		}
		// Se il paziente i è più urgente di tmp_paz allora 
		// i diventa il nuovo paziente più urgente
		if(i->importanza > paz->importanza)
			paz = i; 
		precedente = precedente->next;
	}
	strcpy(nome, paz->nome);
	elimina(precedente, paz);
	return 1;
}

friend ostream& operator<<(ostream& stream, const ProntoSoccorso& p){
	char[][21]
	stream << "\nNumero pazienti: " << numero_pazienti << 
}

void ProntoSoccorso::elimina(Paziente*& precedente, Paziente*& a){
	/* 
	* Elimina il paziente [a] dalla lista e a precedente->next
	* gli associa a->next, se precedente è NULL a root viene associato
	* a->next, se a è nullo non fa nulla
	*/
	if(!a)
		return;
	if(!precedente){
		root = a->next;	
	}
	else{
		precedente->next = a->next	
	}
	numero_pazienti--;
	delete a;
}
