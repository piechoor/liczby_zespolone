#include "WyrazenieZesp.hh"
#include <iostream>
#include <cassert>

using namespace std;

void Wyswietl(WyrazenieZesp WyrZ)
{
    Wyswietl(WyrZ.Arg1);

    switch(WyrZ.Op)
    {
        case Op_Dodaj:
            cout << "+";
            break;
        case Op_Odejmij:
            cout << "-";
            break;
        case Op_Mnoz:
            cout << "*";
            break;
        case Op_Dziel:
            cout << "/";
            break;
    }

    Wyswietl(WyrZ.Arg2);
}

Operator WczytajZnak()
{
    char operacja;
    cin >> operacja;
    
    assert(operacja == '+' || operacja == '-' || operacja == '*' || operacja == '/');
    
    switch (operacja)
    {
        case '+': return Op_Dodaj;
        case '-': return Op_Odejmij;
        case '*': return Op_Mnoz;
        case '/': return Op_Dziel;
    }

    return Op_Dodaj;
}

WyrazenieZesp WczytajWyr()
{
    WyrazenieZesp WyrZ;
    char nawiasy, im;

    cin >> nawiasy;
    WyrZ.Arg1 = WczytajLicz();
    cin >> im;
    cin >> nawiasy;
    WyrZ.Op = WczytajZnak();
    cin >> nawiasy;
    WyrZ.Arg2 = WczytajLicz();
    cin >> im;
    cin >> nawiasy;

    return WyrZ;
}


LZespolona Oblicz(WyrazenieZesp  WyrZ)
{
    switch (WyrZ.Op)
    {
        case Op_Dodaj: return WyrZ.Arg1 + WyrZ.Arg2;
        case Op_Odejmij: return WyrZ.Arg1 - WyrZ.Arg2;
        case Op_Mnoz: return WyrZ.Arg1 * WyrZ.Arg2;
        case Op_Dziel: return WyrZ.Arg1 / WyrZ.Arg2;
    }

    LZespolona Z1 = {0,0};
    return Z1;
}

