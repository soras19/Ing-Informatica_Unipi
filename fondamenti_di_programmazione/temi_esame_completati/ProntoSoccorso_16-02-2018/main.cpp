#include <iostream>
#include "compito.h"
using namespace std;

int main()
{
    cout << "---PRIMA PARTE---" << endl;

    cout << "Test del costruttore di default:" << endl;
    ProntoSoccorso ps;
    cout << ps << endl;

    cout << "Test di ricovero:" << endl;
    ps.ricovero("Mario Rossi", ROSSO);
    ps.ricovero("Maria Neri", VERDE);
    ps.ricovero("Paolo Verdi", BIANCO);
    ps.ricovero("Giuseppe Gialli", ROSSO);

    cout << ps << endl;

    cout << "Test di prossimo:" << endl;

    char* prossimo;
    ps.prossimo(prossimo);
    cout << "Estratto " << prossimo << endl;

    ps.prossimo(prossimo);
    cout << "Estratto " << prossimo << endl;

    ps.prossimo(prossimo);
    cout << "Estratto " << prossimo << endl << endl;

    cout << ps << endl;

    cout << "---SECONDA PARTE---" << endl;
    cout << "Test dell'operatore =:" << endl;
    ProntoSoccorso ps1;
    ps1 = ps;
    cout << ps1 << endl;

    {
        ps1.ricovero("Carlo Bianchi", VERDE);
        ps1.ricovero("Paolino Paperino", BIANCO);

        cout << "Test del costruttore di copia:" << endl;
        ProntoSoccorso ps2(ps1);
        cout << ps2 << endl;

        cout << "Test del distruttore:" << endl;
    }
    cout << "(ps2 e' stato distrutto)" << endl;

    return 0;
}
