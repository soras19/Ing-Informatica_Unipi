#include <iostream>

using namespace std;

struct elem{
	char ch;
	elem* back;
};

void push(elem*& a, char const& i){
	if(a->back != NULL)
		push(a->back, i);
	else{
		cout << "AAAA\n";
		a->ch = i;
		a->back = new elem;
		a->back->back = NULL;
	}
}

int main(){
	elem* head = new elem;
	// Inserimento caratteri;
	for(char i = getchar(); i!='\n';i=getchar() ){
		push(head, i); 
	}
	elem* stampa = head;
	do{
		cout << stampa->ch;
		stampa = stampa->back;
	}while(stampa->back != NULL);
}