/*
Es. 6.3 – Moltiplicazione matrice-vettore
Scrivere una funzione mulMatVect(…) che prende in input una matrice 3x3 di interi e 
un vettore di 3 interi.
La funzione effettua la moltiplicazione matrice x vettore colonna. Il vettore risultante 
viene restituito al chiamante come argomento. La funzione restituisce un tipo void. 
Un esempio di moltiplicazione matrice x vettore colonna è il seguente:
Un esempio di moltiplicazione matrice x vettore colonna è il seguente:
	 1 2 3 			10
 M = 4 5 6 		v = 20
 	 7 8 9 			30
 		1*10 + 2*20 + 3*30 		140
 M*v = 	4*10 + 5*20 + 6*30 	=	320
 		7*10 + 8*20 + 9*30 		500
Scrivere un programma che:
• dichiara una matrice 3x3 di interi e un vettore di 3 interi;
• chiede all’utente di inserire da tastiera 9 interi e li inserisce nella matrice per righe;
• chiede all’utente di inserire da tastiera 3 interi e li inserisce nel vettore;
• invoca la funzione mulMatVect, passando come argomento la matrice e il vettore;
• stampa a video il risultato
*/
#include <iostream>

using namespace std;

// Dimensione matrice: n x n, vettore: n
const int n = 3;

void multMatVect(int matrice[][n], int v[]);

int main(){
	cout << "Inserisci i " << n*n << " interi per la matrice:\n";
	int matrice[n][n];
	// Inserimento interi nella Matrice usando 2 for annidati
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> matrice[i][j];
	cout << "Inserisci i " << n << " interi per il vettore colonna:\n";
	int v[n];
	// Inserimento interi nel vettore
	for(int i = 0; i < n; i++)
		cin >> v[i];
	// Il risultato della funzione verrà salvato in v
	multMatVect(matrice, v);
	cout << "Vettore risultante:\n";
	// Stampa dei risultati
	for(int i = 0; i < n; i++)
		cout << v[i] << endl;
	return 0;

	
}

void multMatVect(int matrice[][n], int v[]){
	int tmp[3];
	// Copio il vettore v in tmp 
	for(int i = 0; i < n; i++)
		tmp[i] = v[i];
	// Lo azzero perchè dovrò utilizzarlo per ritornare il risultato
	for(int i = 0; i < n; i++)
		v[i] = 0;
	// Eseguo il calcolo del nuovo vettore
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			v[i] += matrice[i][j]*tmp[j];
}