#include "compito.h"
#include <cstdlib>


bool Tetris::inserisci(){
	//int block = rand() % 3;
	for(int i = c/2-2; i<c/2+2; i++)
		field[0][i] = '#';
}

void Tetris::input(){
	char in;	
	for(;;){
		in = getchar();
		switch(in){
			case 'a':
				switch_on(LEFT);
				break;
			case 'd':
				switch_on(RIGHT);;
				break;
			case 's':
				switch_on(DOWN);
				break;	
		}
		if(in == ' '){
			// TODO
			//rotate();
		}	
	}
	
}

void Tetris::display(){
	for(int i = 0; i < r; i++)
		cout << field[i] << endl;
}

Tetris::Tetris(int r_, int c_){
	r = r_;
	c = c_+1;
	field = new char*[r];
	for(int i = 0; i < r; i++){
		field[i] = new char[c];
		for(int j = 0; j < c-1; j++)
			field[i][j] = ' ';
		field[i][c-1] = '\0';
	}
	inserisci();
}

void Tetris::switch_on(directions d){
	for(int i = 0; i < 3; i++){
		if(i == d)
			queue[i] = true;
		else
			queue[i] = false;
	}
}
