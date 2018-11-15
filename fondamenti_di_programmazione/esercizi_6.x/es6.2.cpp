#include <iostream>

using namespace std;

int* serpente(int r, int c);

int main(){
	cout << "Inserisci il numero di righe e colonne: ";
	int r, c;
	cin >> r >> c;
	int* matrice = serpente(r, c);
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++)
			cout << *(matrice+i*c+j) << "\t";
		cout<<endl;		
	}
	return 0;
}

int* serpente(int r, int c){
	int* matrice = new int[r*c];
	for(int i = 0; i < r; i++)
		for(int j = 0; j < c; j++){
			if((i%2)==0)
				*(matrice+i*c+j) = c*i+j+1;
			else
				*(matrice+i*c+j) = c*(i+1)-j;
		} 
	return matrice;
}