#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	if(argc == 1){
		printf("ERROR: program usage is %s [FILENAME]\n", argv[0]);
		return 0;
	}
	FILE* textf; 
	if(textf = fopen(argv[1], 'r') == NULL){
		printf("ERROR: couldn't open %s, does it exist?\n", argv[1]);
		return 0;
	}
	size_t len  = ftell(textf)); 
}