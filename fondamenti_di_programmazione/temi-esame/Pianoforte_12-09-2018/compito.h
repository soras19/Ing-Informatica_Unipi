#include <iostream>

using namespace std;

class Pianoforte{
	char* m;
	int dim;
	int p_s, p_d;
public:
	Pianoforte(int ott);
	friend ostream& operator<<(ostream& os, const Pianoforte& p);
	void accordo(const char mano, int tasto);
	Pianoforte& operator-=(const char mano);
	// Seconda Parte
	void nota(const char mano, int tasto);
	Pianoforte& operator-=(int tasto);
	~Pianoforte();
};
