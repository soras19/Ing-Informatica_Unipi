#include <iostream>

using namespace std;

const int n = 3; // Dimensione righe e colonne della Matrice n x n, 

int somma_diag(int a[][n]);
int abs(int n){
	return n>0?n:-n;
}
int main(){
	//cout << "Inserisci i valori della Matrice\n";
	cout << "Inserisci " << n*n << " interi\n";
	int matrice[n][n];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++){
			//cout << i << "->" << j << ": ";
			cin >> matrice[i][j]; 
		}
	//cout << "----Fine Input Matrice----\n";		
	cout << "La somma delle diagonali e': " << somma_diag(matrice) << endl;
	return 0;
}

int somma_diag(int a[][n]){
	// cout << "Somma diagonali Matrice quadrata:";
	int somma = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(i == j || abs(i-j)==(n-1) )
				somma += a[i][j];
	return somma;
}