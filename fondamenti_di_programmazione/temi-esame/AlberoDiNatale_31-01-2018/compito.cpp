#include "compito.h"

ostream& operator << (ostream& os, const AlberoDiNatale& a)
{
	for(int i = a.piani-1; i >= 0; i--)
	{
		// Stampa degli spazi
		for(int spazio = 0; spazio < i; spazio++)
			os << ' ';
		// Stampa dei colori
		for(int ramo = 0; ramo < a.piani - i; ramo++)
			os << a.m[i][ramo] << ' ';
		// Stampa degli spazi
		for(int spazio = 0; spazio < i; spazio++)
			os << ' ';
		os << endl;
	}
	// Stampa degli spazi per centrare il tronco
	for(int spazio = 0; spazio < a.piani-1; spazio++)
			os << ' ';
	os << '|';
	for(int spazio = 0; spazio < a.piani-1; spazio++)
			os << ' ';
	os << endl;
	return os;
}

AlberoDiNatale::AlberoDiNatale(int N)
{
	if(N <= 0)
		N = 0;
	this->piani = N;
	// Alloco un nuovo albero vuoto
	m = new char*[piani];
	for(int i = 0; i < piani; i++)
	{
		m[i] = new char[piani - i];
		for(int j = 0; j < piani - i; j++)
			m[i][j] = '-';
	}
}

void AlberoDiNatale::aggiungiPallina(const char c, int p, int r)
{
	// Controllo che il colore in input sia R V o B
	if(c != 'R' && c != 'V' && c != 'B')
		return;
	// Se 0 < p < piani e 0 < r < piani-p allora continuo
	if(p >= piani || r >= piani - p || p < 0 || r < 0)
		return;
	// Aggiungo la pallina
	if(r == piani-p-1) // caso estremo destro
	{
		if(m[p][r] != '-' || m[p][r-1] == c)
			return;
		else
			m[p][r] = c;
	} else if (r == 0) // caso estremo sinistro
	{
		if(m[p][r] != '-' || m[p][r+1] == c)
			return;
		else
			m[p][r] = c;

	} else
	{
		if(m[p][r] != '-' || m[p][r-1] == c || m[p][r+1] == c)
			return;
		else
			m[p][r] = c;
	}

}

AlberoDiNatale& AlberoDiNatale::operator += (int k)
{
	if(k > 0)
	{
		int old_piani = piani;
		piani += k;
		// Creo un nuovo albero Vuoto
		char** new_m = new char*[piani];
		for(int i = 0; i < piani; i++)
		{
			new_m[i] = new char[piani - i];
			for(int j = 0; j < piani - i; j++)
				new_m[i][j] = '-';
		}
		// Ricopio il vecchio albero
		for(int i = 0; i < old_piani; i++)
			for(int j = 0; j < old_piani-i; j++)
				new_m[i+k][j] = m[i][j];
		// Libero la memoria allocata dal vecchio albero
		for(int i = 0; i < old_piani; i++)
			delete m[i];
		delete m;

		m = new_m;
	}
	return *this;
}

const char AlberoDiNatale::coloreMassimo() const
{
	// ordine di importanza R V B, che saranno gestiti rispettivamente da
	// R->counter[0], V->counter[1], B->counter[2]
	int counter[3] = {0, 0, 0};
	for(int i = 0; i < piani; i++){
		for(int j = 0; j < piani-i; j++){
			switch(m[i][j]){
				case 'R':
					counter[0]++;
					break;
				case 'V':
					counter[1]++;
					break;
				case 'B':
					counter[2]++;
					break;
				default:
					break;
			}
		}
	}
	int i_max = 0; // Indice del primo valore massimo di counter
	for(int i = 1; i < 3; i++)
		if(counter[i] > counter[i_max])
			i_max = i;
	if(i_max == 0)
		return 'R';
	else if(i_max == 1)
		return 'V';
	else
		return 'B';
}

AlberoDiNatale::~AlberoDiNatale()
{
	for(int i = 0; i < piani; i++)
		delete m[i];
	delete m;
}
