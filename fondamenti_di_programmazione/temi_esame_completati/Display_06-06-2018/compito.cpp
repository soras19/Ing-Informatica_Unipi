#include "compito.h"
#include <cstring>

inline void Display::incrementa_pos()
{
	cur_pos++;
	if(cur_pos >= l)
		cur_pos = 0;
}

ostream& operator << (ostream& os, const Display& d)
{
	for(int i = 0; i < d.l; i++)
	{
		if(d.cur_pos == i)
			os << "[" << i+1 << ">";
		else
			os << "[" << i+1 << "]";
		os << d.m[i] << endl; 
	}
	return os;
}

Display::Display(int L, int C)
{
	if(L <= 0)
		L = 1;
	if(C <= 0)
		C = 1;
	l = L; c = C;
	// Creo matrice di caratteri di l righe e c colonne
	m = new char*[l];
	for(int i = 0; i < l; i++){
		m[i] = new char[c+1];
		for(int j = 0; j < c; j++)
			m[i][j] = ' ';
		m[i][c] = '\0';
	}
	
	cur_pos = 0;
}

Display::Display(const Display& d)
{
	this->l = d.l;
	this->c = d.c;
	this->cur_pos = d.cur_pos;
	m = new char*[l];
	for(int i = 0; i < l; i++){
		// c+1 perchè preservo un'area di memoria dove andare
		// a scrivere il char di terminazione stringa '\0' per
		// poter trattare una riga come una stringa
		m[i] = new char[c+1]; 
		for(int j = 0; j < c; j++)
			m[i][j] = d.m[i][j];
		m[i][c] = '\0';
	}
}

void Display::writeT(const char* str)
{
	if(!str || strlen(str) == 0)
		return;	
	for(int i = 0; i < c; i++)
	{
		if(i < strlen(str))
			m[cur_pos][i] = str[i];
		else
			m[cur_pos][i] = ' ';
	}
	incrementa_pos();	
}

void Display::writeW(const char* str)
{
	if(!str || strlen(str) == 0)
		return;
	//int cicli = strlen(str) / this->c;
	int counter = 0, i_matrice = 0;
	for(int i_stringa = 0; i_stringa < strlen(str); i_stringa++)
	{		
		// Se sforo la riga attuale passo a quella successiva
		// E resetto l'iteratore della matrice del display
		if(i_matrice >= this->c)
		{
			incrementa_pos();
			// Setto la stringa con tutti spazi così da non avere 
			// concatenazioni con quello che era stato scritto 
			// predentemente
			memset(m[cur_pos], ' ', this->c); 
			i_matrice = 0;
		}
		m[cur_pos][i_matrice] = str[i_stringa];
		i_matrice++;
	}
	incrementa_pos();
}

Display& Display::operator = (const Display& d)
{
	if(this != &d)
	{
		// Se i display hanno misure diverse elimino
		// la vecchia matrice e ne creo una nuova
		if(l != d.l || c != d.c)
		{
			for(int i = 0; i < l; i++)
				delete m[i];
			delete m;
			l = d.l;
			c = d.c;
			// Alloco la nuova matrice
			m = new char*[l];
			for(int i = 0; i < l; i++){
				m[i] = new char[c+1];
				for(int j = 0; j < c; j++)
					m[i][j] = d.m[i][j];
				m[i][c] = '\0';
			}
		}
		cur_pos = d.cur_pos;
		for(int i = 0; i < l; i++)
			strcpy(m[i], d.m[i]);
	}
	return *this;
}

Display::~Display()
{
	for(int i = 0; i < l; i++)
		delete m[i];
	delete m;
}
