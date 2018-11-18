/*
Es. 6.1 – Somma diagonali
Scrivere una funzione somma_diag(…) che prende in ingresso una matrice quadrata 
di interi, di dimensione nxn, e restituisce la somma degli elementi sulle diagonali
principale e secondaria. L’eventuale elemento centrale deve essere sommato solo 
una volta.
Scrivere un programma che:
• dichiara una matrice 3x3 di numeri interi;
• chiede all'utente di digitare da tastiera 9 numeri interi e li inserisce nella matrice 
per righe; 
• invoca la funzione somma_diag, passando la matrice come argomento;
• stampa a video il valore restituito dalla funzione.
*/

#include <iostream>

using namespace std;

int somma_diag(int** a, int n);

// Alloca una matrice r x c
int** alloca_matrice(int r, int c);

// Funzione valore assoluto di n <=> |n|
int abs(int n){
	return n>0 ? n : -n;
}

int main(){
	int n;
	cout << "Inserisci n (dimensione della matrice n x n): ";
	cin >> n;
	cout << "Inserisci " << n*n << " interi\n";
	int** matrice = alloca_matrice(n, n);
	// Riempimento della matrice con l'input da tastiera
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> matrice[i][j];
	cout << "La somma delle diagonali e': " << somma_diag(matrice, n) << endl;
	return 0;
}

int somma_diag(int** a, int n){
	int somma = 0;
	// Aggiunge in somma il valore dell'elemento a[i][j] se 
	// questo sta sulla diagonale primaria o su quella secondaria
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(i == j || abs(i-j)==(n-1) )
				somma += a[i][j];
	return somma;
}

int** alloca_matrice(int r, int c){
	int** matrice = new int*[r];
	for(int i = 0; i < r; i++)
		matrice[i] = new int[c];
	return matrice; 
}
