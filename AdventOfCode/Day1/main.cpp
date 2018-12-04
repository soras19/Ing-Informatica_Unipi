#include <iostream>
#include <fstream>
using namespace std;

// Prima parte
int getFrequency(fstream& input);

int main(int argc, char const *argv[]) {
    fstream input;
    input.open("input", ios::in);
    if(!input)
        cout << "Apertura fallita! Il file esiste?" << endl;
    else
        cout << getFrequency(input, v) << endl;
    input.close();
    return 0;
}

int getFrequency(fstream& input, vector<int>& v){
    int somma = 0, tmp = 0;
    while(input >> tmp)
        somma += tmp;
    return somma;
}
