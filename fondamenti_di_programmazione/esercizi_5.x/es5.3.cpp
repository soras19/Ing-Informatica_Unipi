/*
Es. 5.3 – Copia di stringa
Scrivere una funzione string_copy() che prende in ingresso due stringhe dest
e src e copia src su dest. La funzione non fa nulla se uno dei due parametri di 
ingresso non è valido. La funzione restituisce void. Assumere che gli spazi di 
memoria a cui puntano le due stringhe siano stati allocati dal chiamante.
Scrivere un programma che inizializza le stringhe src e dest, le stampa, chiama la 
funzione, e stampa nuovamente le stringhe.
Nota: Non utilizzare la funzione di libreria strcpy().
Output di esempio:
dest = Prima stringa
src = Seconda stringa
Chiamo la funzione 
dest = Seconda stringa
src = Seconda stringa
*/

#include <iostream> 

using namespace std;

/*
*	Copia la stringa src in dest, non effettua
*	nessun controllo sulla dimensione della 
*	string di destinazione, attenzione a possibili 
*	buffer overflow 
*/
void string_copy(char dest[], char src[]);

/*
*	Inizializza l'array di char str con tutti
*	null character '\0'
*/
void string_clean(char  str[]);

int main()
{
	char src[] = "Ciao Mondo";
	char dest[]= "Hello World";
	cout << "dest = " << dest << endl;
	cout << "src = " <<  src << endl << "Chiamo la funzione" << endl;
	// Copia src in dest
	string_copy(dest, src);
	cout << "dest = " << dest << endl;
	cout << "src = " <<  src << endl;;

	return 0;
	
}

void string_copy(char dest[], char src[])
{
	// Inizializzo a 0 l'indice per iterare la stringa src
	int i = 0;
	// Controllo se i 2 puntatori sono diversi da NULL
	if(!dest || !src)
		return;
	// Inizializzo la stringa dest con tutti '\0'
	string_clean(dest);
	/* 
	*	Itero la stringa src fino a che non è diversa
	*	dal carattere di fine stringa '\0' e ne copio il contenuto
	*	in dest
	*/
	while(src[i++] != '\0')
		dest[i-1] = src[i-1];
}
void string_clean(char str[]){
	for(int i = 0; str[i]!='\0'; i++)
		str[i] = '\0';
}