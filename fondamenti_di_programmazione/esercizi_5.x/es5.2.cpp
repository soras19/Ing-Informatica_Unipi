#include <iostream>
using namespace std;

void inializzaP(int** p);
void inializzaP(int*& p);
int main(){
	int i = 0;
	int* p = &i;
	cout << "Puntatore prima della chiamata: " << p << endl;
	inializzaP(p); //Versione 2
	cout << "Puntatore dopo la chiamata: " << p << endl;
	return 0;
}

void inializzaP(int** p){
	*p = NULL;	 
}
void inializzaP(int*& p){
	p = NULL;
}