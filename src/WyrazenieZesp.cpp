#include "WyrazenieZesp.hh"
#include <iostream>

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

LZespolona Oblicz(WyrazenieZesp  WyrZ)
{
    switch (WyrZ.Op)
    {
        case Op_Dodaj: 
            return WyrZ.Arg1 + WyrZ.Arg2;
        case Op_Odejmij: 
            return WyrZ.Arg1 - WyrZ.Arg2;
        case Op_Mnoz: 
            return WyrZ.Arg1 * WyrZ.Arg2;
        case Op_Dziel: 
            return WyrZ.Arg1 / WyrZ.Arg2;
    }

    LZespolona Z1 = {0,0};
    return Z1;
}
