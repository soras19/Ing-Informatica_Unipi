#include <iostream>
#include <limits>
#include <bitset>
#include <cctype>

using namespace std;

struct PolReg{			// 16 byte
	int nLati;			// 4 byte
	double lungLato;	// 8 byte
};

struct p2{
	int a,b,c;
};

typedef PolReg* p_PolReg;
typedef bitset<32> byte;

template <typename T>
void print_byte (T bin) { 
	unsigned int size = sizeof(T);
	char* bytes = (char*)bin;
	cout << "PRINTING BYTES, size is:" << size << " The word is: " << bin << endl << "["; 
	for(unsigned int i = 0; i < size-1; i++)
		cout << "0x" << bytes[i]+0 << ",";
	cout << "0x" << bytes[size-1]+0 << "]" << endl;
}
#if 0
int main()
{
	PolReg* p = new PolReg;
	cout << "Inizializzo PolReg* p come new PolReg\n";
	cout << "Struttura di p: p->{int nLati, double lungLato}, sizeof(PolReg) = "<< sizeof (PolReg) \
		 << ", sizeof(p->nLati) = " << sizeof(p->nLati) << ", sizeof(p->lungLato) =" << sizeof(p->lungLato) \
		 << endl; 
	cout<<"Inserisci lungLato: [double]\n";
	cin >> p->lungLato;
	cout << "Inserisci nLati [int]\n";
	cin >> p->nLati;
	print_byte("CIAO");
	//p->lungLato = ~0;
	//p->nLati = ~0;
	cout << "p->nLati(int) = " << p->nLati << " - Notazione a BIT<32> - " << (bitset<32>) p->nLati << endl;	
	cout << "p->lungLato(double) = " << p->lungLato << " - Notazione a BIT<64> - " << (bitset<64>) p->lungLato << endl;
	cout << "Inizializzo unsigned int* pi come =(unsigned int*)p \n";
	unsigned int* pi = (unsigned int*)p;  		
	cout << "VALORI interi di pi[0]-[1]-[2]-[3] :" << pi[0]<<" - "<< pi[1] <<" - "<<pi[2] <<" - "<<pi[3]<< endl;
	cout << "INDIRIZZI di pi[0]-[1]-[2]" << pi<<" - "<<(pi+1)<<" - "<<(pi+2) << endl;
	cout << "Notazione a BIT<32> di pi[0]-[1]-[2]"<< (byte) pi[0]\
		 <<" - "<<(byte) pi[1]<<" - "<<(byte) pi[2] << endl;
	return 0;
}
#else
int main(){
	cout << "sizeof char is:";
	print_byte("AAA");
	
	return 0;
}
#endif