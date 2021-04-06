#include "WyrazenieZesp.hh"
#include <iostream>
#include <cassert>

using namespace std;

Operator WczytajZnak()
{
    char operacja; 
    cin >> operacja; // Wczytanie znaku operacji
    
    // Asercja sprawdzająca czy podano prawidłową opercję
    assert(operacja == '+' || operacja == '-' || operacja == '*' || operacja == '/');
    
    switch (operacja) // Zwrócenie odpowiedniego typu
    {
        case '+': return Op_Dodaj;
        case '-': return Op_Odejmij;
        case '*': return Op_Mnoz;
        case '/': return Op_Dziel;
    }

    return Op_Dodaj;
}

ostream& operator << (ostream &Str_wyj, Operator Op)
{
    const char ZnakOp[] = "+-*/";
    return Str_wyj << ZnakOp[Op];
}

ostream& operator << (ostream &Str_wyj, WyrazenieZesp W1)
{
    Str_wyj << W1.Arg1 << W1.Op << W1.Arg2;
    return Str_wyj;
}

istream& operator >> (istream &Str_wej, WyrazenieZesp &W1)
{
    Str_wej >> W1.Arg1;
    W1.Op = WczytajZnak();
    Str_wej >> W1.Arg2;
    return Str_wej;
}

LZespolona WyrazenieZesp::Oblicz()
{
    // W zaleznosci od zadanego operatora zwrócenie prawidłowego wyniku dzialania
    switch (this->Op)
    {
        case Op_Dodaj: return this->Arg1 + this->Arg2;
        case Op_Odejmij: return this->Arg1 - this->Arg2;
        case Op_Mnoz: return this->Arg1 * this->Arg2;
        case Op_Dziel: return this->Arg1 / this->Arg2;
    }

    LZespolona Z1 = {0,0};
    return Z1;
}

