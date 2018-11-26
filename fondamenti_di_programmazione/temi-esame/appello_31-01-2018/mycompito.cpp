#include "mycompito.hpp"

/*
enum COLORE{ROSSO = 0, VERDE, BLU};

class AlberoDiNatale{

	int* piani;
	friend ostream& operator<<(ostream& out, const AlberoDiNatale& a);

public:
	AlberoDiNatale(int N);
	// Fallisce se il ramo è occupato da un'altra pallina
	// oppure se una pallina dello stesso colore è già presente
	// in un ramo adiacente dello stesso piano
	void aggiungiPallina(COLORE c, int ramo, int piano);
	
*/

ostream& operator<<(ostream& os, const AlberoDiNatale& a){
	char arr[]={'-', 'R', 'V', 'B'};
	
	for(int p=a.n_piani-1; p>=0; p--){
    // stampo spazi bianchi
        for (int i=0; i<p; i++)
            os << ' ';
     // stampo stato dei rami del piano corrente
        for (int r=0; r<a.n_piani-p; r++)
            os <<arr[ a.piani[p][r] ] << ' ';
        os << endl;
	// stampo tronco dell'albero   
	}
	for (int i=0; i<a.n_piani-1; i++)
	    os << ' ';
	os << '|' << endl;	
	return os;
}



AlberoDiNatale::AlberoDiNatale(int N){
	// Inizializzo gli N piani a cui saranno puntati i Rami
	piani = new int*[N];
	for(int i = 0; i < N; i++){
		// Inizializzo i rami, il piano piu basso ha N rami
		// quello piu alto ne ha 1.
		piani[i] = new int[N-i];
		// Gli do il valore di 0 che corrisponde a nessuna pallina
		for(int j=0; j<N-i; j++)
			piani[i][j] = 0;
	}
	n_piani = N;
}
void AlberoDiNatale::aggiungiPallina(const char ci, int ramo, int i_piano){
	COLORE c;
	switch(ci){
		case 'R':
			c = ROSSO;
			break;

		case 'V':
			c = VERDE;
			break;

		case 'B':
			c = BLU;
			break;
		default:
			cout << "ERRORE: colore inserito non valido: "<<ci<<endl;
			return;			
	}
	if(i_piano > n_piani || i_piano < 0){
		cout << "Errore, piano inserito invalido, piano specificato: " << i_piano;
		cout << "Piano massimo: " << n_piani-1 << endl;	
		return;
	}
	// se piano = 0 r = N {0...N-1}
	if(ramo > (n_piani-i_piano)){
		cout << "Errore, ramo inserito invalido, ramo specificato: " << ramo;
		cout << "ramo massimo: " << n_piani-i_piano << endl;
		return;
	}
	// Se l'input è valido inserisco la pallina
	for(int r = 0; r < n_piani-i_piano; r++){}
	if(this->piani[i_piano][ramo] != 0){
		cout << "Errore il ramo contiene gia' una pallina\n";
		return;		
	}
	// Se 1 solo ramo
	if(i_piano == n_piani-1){
		// Se è vuoto:
		if(piani[i_piano][0] == 0)
			piani[i_piano][0] = c;
	}
	// Se estremo destro non controllo il ramo successivo
	else if(ramo == n_piani-i_piano-1){
		if(piani[i_piano][ramo-1] == c){
			cout << "Errore: ramo adiacente dello stesso colore in input 11111\n";
			return;
		}else{
			piani[i_piano][ramo] = c;
		}
	}
	else if(ramo == 0){
		if(piani[i_piano][ramo+1] == c){
			cout << "Errore: ramo adiacente dello stesso colore in input 22222\n";
			return;
		}else{
			piani[i_piano][ramo] = c;
		}		
	}
	else{
		if(piani[i_piano][ramo-1] == c || piani[i_piano][ramo+1] == c){
			cout << "Errore: ramo adiacente dello stesso colore in input 33333\n";
			return;
		}else{
			piani[i_piano][ramo] = c;
		}		
	}
}

