#include "compito.h"

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
}

void Tetris::switch_on(directions d){
	for(int i = 0; i < 3; i++){
		if(i == d)
			queue[i] = true;
		else
			queue[i] = false;
	}
}

bool Tetris::input(){
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
			rotate();
		}
		
	}
	
}