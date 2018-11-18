/*
*	Es. 6.2 – Serpente di numeri
*	Scrivere una funzione che abbia come parametri formali due interi r e c. La funzione 
*	crea una matrice di dimensione r*c fatta nel seguente modo (es. r=5, c=6):
*	1 2 3 4 5 6
*	12 11 10 9 8 7
*	13 14 15 16 17 18
*	24 23 22 21 20 19
*	25 26 27 28 29 30
*	La matrice deve essere restituita al chiamante come valore di ritorno.
*	Scrivere un programma che:
*	• chiede all'utente di inserire da tastiera due interi N e M;
*	• invoca la funzione passandole N e M come argomenti;
*	• stampa a video il contenuto della matrice restituita dalla funzione.
*/

#include <iostream>

using namespace std;

/* 	@params: 
*		- r : numero righe
*		- c : numero colonne
*	@return: 
*		- matrice di dimensione r x c <=> matrice[r][c]
*/				

//int* serpente(int r, int c);
int** serpente(int r, int c);
void pretty_print(int** m, int r, int c);
void freccia_dx(int c);
void freccia_sx();

int main(){
	cout << "Inserisci il numero di righe e colonne: ";
	int r, c;
	// Inserimento della dimensione di righe e colonne
	cin >> r >> c;
	// La funzione serpente torna il puntatore al primo elemento della 
	// matrice di dimensione r x c 
	int** matrice = serpente(r, c);
	// Stampa della matrice
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++)
			cout << matrice[i][j] << "\t";
		cout<<endl;		
	}
	// Disalloco la memoria 
	for(int i = 0; i < r; i++)
		delete[] matrice[i];
	delete matrice;
	return 0;
}

int** serpente(int r, int c){
	// Inizializzo una matrice[r][c], quindi ho bisogno di
	// r*c blocchi di memoria
	int** matrice = new int*[r];
	for(int i = 0; i < r; i++)
		matrice[i] = new int[c];
	/* La riempio di numeri da 1 a r*c, nelle posizioni 
	*  da matrice[0][0] fino a => matrice[r-1][k-1]
	*  come un serpente arrotolato, quindi se r=3 e c=4:
	*  1	2	 3	 4
	*
	*  8	7 	 6	 5
	*
	*  9 	10	 11	 12
	*/
	for(int i = 0; i < r; i++)
		for(int j = 0; j < c; j++){
			if((i%2)==0)
				matrice[i][j] = c*i+j+1;
			else
				matrice[i][j] = c*(i+1)-j;
		} 
	// Ritorno il puntatore al primo elemento della matrice
	return matrice;
}
void pretty_print(int** m, int r, int c){
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++)
			cout << m[i][j] << " -> " << "\t";
		cout<<endl;
		if((i%2)==0){
			freccia_dx(c);
		}
		else{
			freccia_sx();
		}		
	}	
}
void freccia_dx(int c){
	// Freccia giu' a destra 
	for(int j = 0; j < c-1; j++){				
		if(j == c-2)
			cout << "\t|";
		cout << "\t";
	}
	cout << endl;
	for(int j = 0; j < c-1; j++){				
		if(j == c-2)
			cout << "\tV";
		cout << "\t";
	}
	cout <<endl;
}
void freccia_sx(){
	// Freccia giu' a sinistra
	cout << "|\nV\n";
}