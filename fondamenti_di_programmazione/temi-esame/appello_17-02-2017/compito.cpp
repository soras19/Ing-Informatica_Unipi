#include "compito.h"

#include <cstring>

ostream& operator<<(ostream& os, const Barriera& b){
	for(int i = 0; i < dim; i++){
		os << "[" << i+1 << "]" << " ";
		if(b.caselli[i].aperto){
			if(!b.caselli[i].testa)
				os << "(libero)" << endl;
			else{
				elem* q = b.caselli[i].testa;
				while(q->pun != NULL){
					os << q->targa << "=>";
					q = q->pun;
				}
				os << q->targa << endl;				 
			}
		}
		else 
			os << "(chiuso)" << endl;			
	}
	return os;
}

bool Barriera::isOkInput(const char* s){
	if(strlen(s) != 6)
		return false;
	for(int i = 0; i < 6; i++)
		if(s[i] < 'A' || s[i] > 'Z')
			return false;
	return true;
}

void Barriera::nuovoVeicolo(const char* s){
	// Controllo che la targa inserita sia valida
	if(!isOkInput(s))
		return;		
	// Prendo l'indice del casello con meno macchine accodate
	int min = -1;
	for(int i = 0; i < dim; i++){
		if(caselli[i].aperto){ // confronta
			if(min == -1)
				min = i;
			else if(caselli[min].n > caselli[i].n )
				min = i;
			
		}
	}
	if(min == -1)
		return;
	aggiungi(s, min);
}

Barriera::operator int() const{
	int somma = 0;
	for(int i = 0; i < dim; i++)
		if(caselli[i].aperto)
			somma += caselli[i].n;
	return somma;
}

int Barriera::apriOppureChiudi(double mediaIdeale){
	double media = 0; 
	int aperti = 0;
	for(int i = 0; i < dim; i++){
		if(caselli[i].aperto){
			media += caselli[i].n;
			aperti++;
		}
	}
	media = (double) media/aperti;
	if(media > mediaIdeale){
		int _i = -1;
		for(int i = 0; i < dim; i++)
			if(!caselli[i].aperto)
				_i = i;
		if(_i != -1){
			cout << "APRO IL CASELLO: " << _i << endl;
			caselli[_i].aperto = true;
			return 1;
		}
	}
	else if(media < mediaIdeale){
		for(int i = 0; i < dim; i++)
			if(caselli[i].aperto && caselli[i].n == 0){
				caselli[i].aperto = false;
				return -1;
			}
	}
	return 0;
}

Barriera::Barriera(){
	for(int i = 0; i < dim; i++){
		if(i<3)
			caselli[i].aperto = true;
		else
			caselli[i].aperto = false;
		caselli[i].n = 0;
		caselli[i].testa = NULL;
	}
}

Barriera::~Barriera(){
	elem* q;
	for(int i = 0; i < dim; i++){
		while(caselli[i].testa != NULL){
			q = caselli[i].testa;
			caselli[i].testa = caselli[i].testa->pun;
			delete q;
		}
	}
}

bool Barriera::serviVeicolo(int i){
	i--;
	if(i<0 || i>5)
		return false;
	if(!caselli[i].aperto || (caselli[i].testa == NULL))
		return false;
		
	elimina(i);
	return true;
}

void Barriera::elimina(int i){
	caselli[i].n--;
	elem* q = caselli[i].testa->pun;
	delete caselli[i].testa;
	caselli[i].testa=q;	
	return;
}

int Barriera::aggiungi(const char* nome, int min){
	caselli[min].n++;
	if(caselli[min].testa == NULL){
		//cout << "Testa vuota, inserisco " << nome << " in testa al casello " << min << endl;
		caselli[min].testa = new elem;
		caselli[min].testa->pun = NULL;
		strcpy(caselli[min].testa->targa, nome);
		return 1;
	}
	
	elem* q = caselli[min].testa;
	elem* p;
	int i = 0;
	while(q != NULL){
		i++;
		p = q;
		q = q->pun;
	}
	q = new elem;
	q->pun = NULL;
	strcpy(q->targa, nome);
	p->pun = q;
	//cout << "Testa non vuota, inserisco " << nome << " in posizione " << i << " del casello "<< min << endl;
	return 1;
}
