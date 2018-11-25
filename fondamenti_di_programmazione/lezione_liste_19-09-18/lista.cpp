#include <iostream>

using namespace std;
// LIFO


struct elem{
	char ch;
	elem* next;
};

//void push()

int main(){
	elem* testa = new elem;
	testa->ch = '\0';
	testa->next = NULL;
	//Inserimento elementi
	char buffer; 
	elem *tmp = testa;
	while((buffer = getchar()) != '\n' ){ // fino a che non premi invio prendi caratteri inseriti
		tmp->ch = buffer; // Metti i caratteri nella lista
		tmp->next = new elem;
		tmp = tmp->next;
		tmp->ch = '\0';
		tmp->next = NULL;
	}
	tmp = NULL;
	//Stampa
	for(elem* i = testa; i->ch != '\0'; i = i->next)
		std::cout << i->ch;
	cout << endl;
	return 0;
	
}

