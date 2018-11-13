#include <iostream> 

using namespace std;

int main()
{
	const int dim = 10;
	int v[dim];
	cout << "Inserisci i 10 interi:" << endl;
	int s = 0;
	for(int i=0; i<dim; i++){ 
		cin >> v[i];
		s += v[i];
	}
	int max = 0;
	for(int i=1; i<dim; i++)
		max = v[max]>v[i] ? max : i;
	if(s%2)
		cout << "La somma e' DISPARI" << endl;
	else
		cout << "La somma e' PARI" << endl;

	cout << "L'indice dell'elemento massimo e': " << max << endl; 
	return 0;
}