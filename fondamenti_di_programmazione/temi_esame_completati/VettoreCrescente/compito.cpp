#include "compito.hpp"
/*
class VettoreCrescente{

	int* v;
	int n;
	
public:
	VettoreCrescente(int dim);
	void set(int ind, int val);
	friend ostream& operator << (ostream& os, const VettoreCrescente& vettore);
	// PARTE 2
	operator int();
	void azzera();
};
*/

VettoreCrescente::operator int() const
{
	int counter = 0;
	// Trovo i minimi
	for(int i = 1; i < n-1; i++)
		if(v[i] <  v[i-1] && v[i] < v[i+1])
			counter++;
	return counter;
}

ostream& operator << (ostream& os, const VettoreCrescente& vettore)
{
	os << '<';
	for(int i = 0; i < vettore.n; i++)
	{
		os << vettore.v[i] << ' ';
	}
	os << '>';
	return  os;
}

VettoreCrescente::VettoreCrescente(int dim)
{
	if(dim <= 0)
		dim = 1;
	n = dim;
	v = new int[n];
	for(int i = 0; i < n; i++)
		v[i] = 0;	
}

void VettoreCrescente::realloca(int nuova_dim)
{
	int* new_array = new int[nuova_dim];
	for(int i = 0; i < n; i++)
		new_array[i] = v[i];
	delete[] v;
	for(int i = n; i < nuova_dim; i++)
		new_array[i] = 0;
	v = new_array;
	n = nuova_dim;
}

VettoreCrescente::~VettoreCrescente()
{
	delete[] v;
}

void VettoreCrescente::set(int ind, int val)
{
	if(ind < 0)
		ind = -ind;
	if(ind >= n)
		realloca(ind+1);
	v[ind] = val;	
}

void VettoreCrescente::azzera(){
	int max1 , max2, i1=-1, i2=-1;

	// Trovo il primo massimo relativo
	for(int i = 1; i < n-1; i++)
		if(v[i] >  v[i-1] && v[i] > v[i+1]){
			max1 = v[i];
			i1 = i;
			break;
		}
	if(i1 == -1)
		return;
	// Trovo il secondo se il primo è stato trovato 
	for(int i = i1+1; i < n; i++){
		if(v[i] == max1){
			max2 = v[i];
			i2 = i;
		}
	}
	// Se ho trovato il secondo azzero
	if(i2 != -1){
		for(int i = i1+1; i < i2; i++)
			v[i] = 0;
	}
}

VettoreCrescente& VettoreCrescente::operator = (const VettoreCrescente& v2)
{
	if(this != &v2){
		if(v2.n != n){
			n = v2.n;
			delete[] v;
			v = new int[n];
		}
		for(int i = 0; i < n; i++)
			v[i] = v2.v[i];
	}
	return *this;
}
