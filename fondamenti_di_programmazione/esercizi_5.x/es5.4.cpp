#include <iostream> 
using namespace std;

#define dim 6

void traslaVettore(int vett[], int n);

int main(){
	int v[dim];
	for(int i = 0; i < dim; i++)
	{
		cout << "Inserisci l'elemento "<< i << ":" << endl;
		cin >> v[i];
	}
	traslaVettore(v,dim);
	cout << "Vettore Risultante:" << endl;
	for(int i : v)
		cout << i << " ";
	cout << endl;
	return 0; 
}

void traslaVettore(int vett[], int n){
	int copia[n];
	int k;
	cout << "Inserisci un numero di passi di traslazione:" << endl;
	cin >> k;	
	for(int i = 0; i < n; i++)
		copia[i] = vett[i];
	if(k > n){ 
		k = k%n;
	}
	for(int i = 0; i < n; i++){
		if(i <k)
			vett[i] = copia[n+i-k];
		else
			vett[i] = copia[i-k];		
	}
}