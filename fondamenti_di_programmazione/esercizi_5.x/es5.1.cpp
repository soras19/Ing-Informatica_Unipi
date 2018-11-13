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
	cout << "puntatore p: " << p_i << endl << "Valore puntato da p: " << *p_i << endl;
	if(p_i == NULL)
		return 3;
	else if(*p_i % 2 == 0)
		return (*p_i)*(*p_i);
	else if(*p_i % 3 == 0)
		return (*p_i)*(*p_i)*(*p_i);
	else 
		return *p_i;	
}