#ifndef COMPITO_H
#define COMPITO_H

#include <iostream>

enum directions{RIGHT=0, LEFT, DOWN, SPACE};

using namespace std;

class Tetris{
	int r,c;
	// Matrice che rappresenta il campo di tetris 
	char** field;
	// array per i movimenti in 
	bool queue[3];
	// coordinate forma attuale
	int x, y;
	// 
	void rotate();
	// In base all'input dell'utente modifica il campo di tetris
	void move(directions d);
	// Funzioni per la gestione del movimento
	void switch_on(directions d);
	void switch_off(directions d);	
	
public:
	Tetris(int r_ = 10, int c_ = 10);
	bool inserisci(int j);
	void display();
	void input();
	int vuote();
	void run();
		
};



#endif