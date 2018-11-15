/*
Es. 5.2 – Annullamento puntatore
Scrivere una funzione inizializzaP() che ha come argomento un puntatore a 
intero e come valore di ritorno void. La funzione assegna il valore NULL al 
puntatore.
Scrivere un programma che inizializza un intero e un puntatore ad esso, stampa il 
valore del puntatore, chiama la funzione, e stampa nuovamente il valore del 
puntatore.
Output di esempio:
Puntatore prima della chiamata: 0x7ffee6e7651c
Puntatore dopo la chiamata: 0
*/

#include <iostream>
using namespace std;

/*
*	Per chiamare questa funzione bisogna passare
* 	come argomento l'indirizzo di memoria del puntatore del main
* 	quindi la chiamata, dato int* p è: inizializzaP(&p)
*/
void inializzaP(int** p); 
/*
*	Per chiamare questa funzione invece viene passato 
*	il puntatore per riferimento perciò, dato int* p
*	basta chiamare:
*	inizializzaP(p);
*/
void inializzaP(int*& p);

int main(){
	int i = 0;
	int* p = &i;
	cout << "Puntatore prima della chiamata: " << p << endl;
	inializzaP(p); // Passaggio del puntatore per riferimento
	cout << "Puntatore dopo la chiamata: " << p << endl;
	return 0;
}

void inializzaP(int** p){
	*p = NULL;	 
}
void inializzaP(int*& p){
	p = NULL;
}