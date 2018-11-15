/*
Es. 5.1 – Puntatore
Scrivere una funzione f() che ha come argomento un puntatore a intero. Sia n il 
valore dell'oggetto puntato. La funzione restituisce come valore di ritorno 0 se 
l'input non è valido; il quadrato di n se n è multiplo di 2; il cubo di n se n è multiplo 
di 3; il numero n altrimenti. La funzione stampa anche il valore del puntatore e il 
valore dell'oggetto puntato.
Scrivere un programma che accetta un intero da tastiera, chiama la funzione e 
stampa a video il valore restituito dalla funzione.
*/
#include <iostream>

using namespace std;

int f(int *p_i);

int main(){
	cout << "Inserisci k:" << endl;
	int k;
	cin >> k;
	cout << f(&k) << endl;
}

int f(int *p_i)
{
	cout << "Indirizzo puntato da p->" << p_i << endl << "Valore puntato da p: " << *p_i << endl;
	if(p_i == NULL)
		return 3;
	else if(*p_i % 2 == 0)
		return (*p_i)*(*p_i);
	else if(*p_i % 3 == 0)
		return (*p_i)*(*p_i)*(*p_i);
	else 
		return *p_i;	
}