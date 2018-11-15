/*
Esercizio 5.4 – Rotazione di un vettore
Scrivere una funzione void traslaVettore(int vett[], int n) che 
trasla a destra di una posizione ciascun elemento dell'array di interi vett, lungo n
elementi. La traslazione è circolare, ovvero l’elemento in posizione n-1 viene 
copiato in posizione 0.
Scrivere un programma che:
a) richiede l'inserimento da tastiera di 6 interi da tastiera e li memorizza in un 
vettore;
b) richiede l'inserimento da tastiera di un numero di passi di traslazione k;
b) trasla a destra il vettore di k passi (circolarmente), sfruttando la funzione 
traslaVettore();
c) stampa a video il vettore risultante.
Output di esempio:
Inserire gli elementi del vettore: 
1 
2 
3 
4 
5 
6 
Inserire un numero di passi di traslazione: 
2 
Vettore risultante: 
5 6 1 2 3 4
*/

#include <iostream> 
using namespace std;

#define dim 6

void traslaVettore(int vett[], int n);

int main(){
	int v[dim];
	cout << "Inserisci " << dim << " interi  per riempire il vettore da traslare"  << endl; 
	// Riempie il vettore v con input da tastiera
	for(int i = 0; i < dim; i++)
		cin >> v[i];
	traslaVettore(v,dim);
	cout << "Vettore Risultante:" << endl;
	// Stampa il vettore v dopo avere effettuato la traslazione
	for(int i = 0; i < dim; i++)
		cout << v[i] << " ";
	cout << endl;
	return 0; 
}

void traslaVettore(int vett[], int n){
	/* 
	*	Poichè traslaVettore deve tornare vett[] traslato
	*	inizializzo il vettore copia della stessa dimensione di vett
	*	per usarlo nei calcoli del vettore traslato
	*/
	int copia[n];
	for(int i = 0; i < n; i++)
		copia[i] = vett[i];
	// k = numero di passi della traslazione
	int k;
	cout << "Inserisci un numero di passi di traslazione:" << endl;
	cin >> k;
	/*
	*	Traslare il vettore di n passi, dove n è la dimensione stessa del
	*	vettore equivale a non fare nulla, perciò a k tolgo tutti i passi
	*	non necessari, multipli di n; l'espressione sotto equivale a fare
	*	k = k - (k/n)
	*/
	k = k%n;
	// 	Traslo il vettore sfruttando il fatto che se i < k allora
	// 	n+i-k rappresenta l'indice della parte finale del vettore
	//	dalla sinistra all'estremo destro
	// 	Esempio: 
	//		Se k=2 ed n=6:
	//			(i<k) perciò -> (n+i-k) 
	//			i=0 -> 4; 
	//			i=1 -> 5; 
	//			i=2 non verifica piu' i<k ed in effetti
	//			se vett ha dimensione n=6, l'indice dell'estremo destro è 5
	//			quindi (i>=k)->(i-k) i=2 -> 0, i=3 -> 1, i=4 -> 2, i=5 -> 3
	//			ed il for finisce qua dopo aver iterato tutto vett e tutto copia   
	for(int i = 0; i < n; i++){
		if(i < k)
			vett[i] = copia[n+i-k];
		else
			vett[i] = copia[i-k];		
	}
}