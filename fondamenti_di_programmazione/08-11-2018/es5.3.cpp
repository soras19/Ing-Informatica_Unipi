#include <iostream> 
using namespace std;

void string_copy(char dest[], char src[]);
void string_clean(char  str[]);

int main()
{
	char src[] = "Ciao Mondo";
	char dest[]= "Hello World";
	cout << "dest = " << dest << endl;
	cout << "src = " <<  src << endl << "Chiamo la funzione" << endl;
	string_copy(dest, src);
	cout << "dest = " << dest << endl;
	cout << "src = " <<  src << endl;;

	return 0;
	
}

void string_copy(char dest[], char src[])
{
	int i = 0;
	if(!dest || !src)
		return;
	string_clean(dest);
	while(src[i++] != '\0')
		dest[i-1] = src[i-1];
}
void string_clean(char str[]){
	for(int i = 0; str[i]!='\0'; i++)
		str[i] = '\0';
}