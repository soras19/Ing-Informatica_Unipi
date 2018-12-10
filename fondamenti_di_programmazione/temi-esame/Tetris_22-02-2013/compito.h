#ifndef COMPITO_H
#define COMPITO_H

#include <iostream>;

using namespace std;

enum directions{RIGHT=0, LEFT, DOWN, SPACE};
enum block_type{I, O};

struct blocco{
	block_type t;
	int x,y;	
}

class Tetris{
	static int r,c;
	// Matrice che rappresenta il campo di tetris 
	static char** field; 
	// array per i movimenti in 
	static bool queue[3];
	// coordinate forma attuale
	static int x, y;
	// 
	static void rotate();
	// In base all'input dell'utente modifica il campo di tetris
	static void move(directions d);
	// Funzioni per la gestione del movimento
	static void switch_on(directions d);
	static bool inserisci();
	
public:
	Tetris(int r_ = 10, int c_ = 10);
	// Funzione per inserire  una forma casuale
	static void display();
	static void input();
		
};



#endif