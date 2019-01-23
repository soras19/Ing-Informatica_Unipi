#include "compito.h"
#include <cmath>
#include <cstring>
ostream& operator << (ostream& os, const Display& d)
{
	for(int i = 0; i < d.N; i++)
		os << d.m[i] << endl;
	return os;
}

Display::Display(int n)
{
	if(n % 2 == 0 || n <= 4)
		n = 5;
	N = n;
	m = new char*[N];
	for(int i = 0; i < N; i++)
	{
		m[i] = new char[N+1];
		for(int j = 0; j < N; j++)
			m[i][j] = '0';
		m[i][N] = '\0';
	}
	for(int i = 0; i < 3; i++)
		flag[i] = 0;
}

Display::Display(const Display& d2)
{
	N = d2.N;
	m = new char*[N];
	for(int i = 0; i < N; i++)
	{
		m[i] = new char[N+1];
		for(int j = 0; j < N+1; j++)
			m[i][j] = d2.m[i][j];
	}
	for(int i = 0; i < 3; i++)
		flag[i] = d2.flag[i];
}

Display::~Display()
{
	for(int i = 0; i < N; i++)
	{
		delete[] m[i];
	}
	delete[] m;
}

void Display::set(char ch)
{
	if(ch != '-' && ch != '|' && ch != '/')
		return;
	else
	{
		if(ch == '-')
		{
		// Accendo i led nella riga centrale
			for(int j = 0; j < N; j++)
				m[(int)floor(N/2)][j] = '1';
			flag[0] = 1;
		}
		else if(ch == '|')
		{
		// Accendo i led nella colonna centrale
			for(int j = 0; j < N; j++)
				m[j][(int)floor(N/2)] = '1';
			flag[1] = 1;
		}
		else
		{
		// Accendo i led nella diagonale minore
			for(int i = 0; i < N; i++)
				m[i][N-1-i] = '1';
			flag[2] = 1;
		}	
	}
}

Display& Display::operator |= (const Display& d2)
{
	if(this != &d2)
	{
		for(int i = 0; i < 3; i++)
		{
			if(d2.flag[i] && !flag[i])
			{
				switch(i)
				{
					case 0:
						set('-');
						break;
					case 1:
						set('|');
						break;
					case 2:
						set('/');
						break;
				}
			}
		}
	}
	return *this;
}

void Display::specchia()
{
	if(flag[2] == 1)
	{
		/*	Spengo i led nella diagonale MINORE,  
		 *	li accendo in quella MAGGIORE e setto
		 *	la flag di stato a 2
		*/
		for(int i = 0; i < N; i++)
			m[i][N-1-i] = '0';
		for(int i = 0; i < N; i++)
			m[i][i] = '1';
		flag[2] = 2;
	}
	else if(flag[2] == 2)
	{
		/*	Spengo i led nella diagonale MAGGIORE,  
		 *	li accendo in quella MINORE e setto
		 *	la flag di stato a 1
		*/
		for(int i = 0; i < N; i++)
			m[i][i] = '0';
		for(int i = 0; i < N; i++)
			m[i][N-1-i] = '1';
		flag[2] = 1;
	}
}

Display& Display::operator = (const Display& d2)
{
	if(this != &d2)
	{
		for(int i = 0; i < N; i++)
		{
			strcpy(m[i], d2.m[i]);
		}
		for(int i = 0; i < 3; i++)
		{
			flag[i] = d2.flag[i];
		}
	}
	return *this;
}
