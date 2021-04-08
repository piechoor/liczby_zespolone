#include "WyrazenieZesp.hh"
#include <iostream>
#include <cassert>

using namespace std;

LZespolona WyrazenieZesp::Oblicz()
{
    // W zaleznosci od zadanego operatora zwrócenie prawidłowego wyniku dzialania arytmetycznego
    switch (this->Op)
    {
        case Op_Dodaj: return this->Arg1 + this->Arg2;
        case Op_Odejmij: return this->Arg1 - this->Arg2;
        case Op_Mnoz: return this->Arg1 * this->Arg2;
        case Op_Dziel: return this->Arg1 / this->Arg2;
    }

    LZespolona Z1 = {0,0}; // Zapobiegniecie bledu kompilatora
    return Z1;
}

Operator WczytajZnak()
{
    char operacja; 
    cin >> operacja; // Wczytanie znaku operacji
    
    // Asercja sprawdzająca czy podano prawidłową opercję
    assert(operacja == '+' || operacja == '-' || operacja == '*' || operacja == '/');
    
    switch (operacja) // Zwrócenie odpowiedniego typu Operator
    {
        case '+': return Op_Dodaj;
        case '-': return Op_Odejmij;
        case '*': return Op_Mnoz;
        case '/': return Op_Dziel;
    }

    return Op_Dodaj; // Zapobiegniecie bledu kompilatora
}

ostream& operator << (ostream &Str_wyj, Operator Op)
{
    const char ZnakOp[] = "+-*/"; // Stworzenie tablicy mozliwych operatorow
    return Str_wyj << ZnakOp[Op]; // Wyswietlenie operatora korzystajac z typu wyliczeniowego
}

ostream& operator << (ostream &Str_wyj, WyrazenieZesp W1)
{
    Str_wyj << W1.Arg1 << W1.Op << W1.Arg2; // Wczytanie kolejnych skladnikow wyrazenia zespolonego
    return Str_wyj;
}

istream& operator >> (istream &Str_wej, WyrazenieZesp &W1)
{
    Str_wej >> W1.Arg1; // Wczytanie pierwszego argumentu wyrazenia
    W1.Op = WczytajZnak(); // Wczytanie znaku operacji
    Str_wej >> W1.Arg2; // Wczytanie drugiego argumentu
    return Str_wej;
}