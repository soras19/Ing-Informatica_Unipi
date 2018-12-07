/*
Si scriva un programma ricorsivo in C per giocare al gioco “indovina un numero”. Il
programma ha un menù testuale iniziale con due funzionalità (1 - gioco con due giocatori, 2 -
gioco con tre giocatori, 3 - esci). Un giocatore inserisce da tastiera un numero segreto (tra 1
e M) dove M è definita come una costante simbolica. Ad ogni tentativo gli altri giocatori a
turno tentano di indovinare il numero inserito, ed il programma può rispondere “esatto”,
“troppo alto” oppure “troppo basso”. Se nessuno dei giocatori indovina il numero entro
log2(M) passi, il programma stampa “Ha vinto il banco!” e torna al menù principale. Se, al
contrario, il numero è stato indovinato, il programma stampa “Ha vinto il giocatore n. 1”
oppure “Ha vinto il giocatore n. 2” a seconda che abbia indovinato il primo giocatore che
inizia i tentativi o il secondo; poi il programma torna al menù principale. Realizzare il menù
testuale con un array di puntatori a funzioni.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

double Log2( double n )  
{  
    // log(n)/log(2) is log2.  
    return log( n ) / log( 2 );  
}  

#define DIM 2
#define M 100
#define MAX floor(Log2(M))
#define buf_dim 3
/*
int (*option[DIM])(int) = {new_num, print_c2, print_opp, print_opp_c2, ext};
*/

void inserisci_tra(int a, int b, int* ris){
	int flag = 0;
	char buffer[buf_dim+1];	
	do{
		while(scanf("%d", ris) != 1)
			scanf("%*[^\n]%c*", ris);
		if(*ris < a || *ris > b)
			printf("Scelta inserita non valida, reinserisci un numero compreso tra %d e %d\n", a, b);
	}while(*ris < a || *ris > b);
}

int gioco(int num_giocatori, int iterazioni, int num){ //num = numero del banco
	if(iterazioni == 0){
		// Prima iterazione, definisco il num del banco
		printf("Hai selezionato %d giocatori\n", num_giocatori);
		printf("Inserisci un numero compreso tra 1 e %d\n", M);
		inserisci_tra(1, M, &num);
		return gioco(num_giocatori,iterazioni+1 ,num);
	}
	if(iterazioni == MAX){
		printf("Ha vinto il banco!\n");
		return 0;
	}
	// Ad ogni iterazione successiva faccio inserire un intero dal giocatore
	// iterazioni%num_giocatori ovvero 1 = 1giocatore 2 = 2giocatori 0 
	printf("Giocatore n. %d e' il tuo turno:\n", (iterazioni%num_giocatori)+1);
	int input;
	inserisci_tra(1,M,&input);
	
	if(input == num){
		printf("Esatto.\nHa vinto il giocatore n. %d\n", (iterazioni%num_giocatori)+1);
		return (iterazioni%num_giocatori)+1;
	}
	else{
		if(input < num)
			printf("Troppo basso\n");
		else
			printf("Troppo alto\n");
		return gioco(num_giocatori, iterazioni+1, num);
	}	
}

int esci(int,int,int);

int main(void){
	int ris = 0;
	int (*scelta[DIM])(int,int,int) = {gioco, esci};
	
	for(;;){
		printf("1) Gioco con due giocatori\n");
		printf("2) Gioco con tre giocatori\n");
		printf("3) Esci\n");
		printf("Scelta: ");
		inserisci_tra(1, 3, &ris);
		// Chiamata alla funzione inserita dall'utente
		if(ris <= 2)
			scelta[0](ris,0,0);	
		else
			scelta[1](ris,0,0);
		
	}
	
	return 0;
}

int esci(int a,int b,int c){
	exit(0);
}