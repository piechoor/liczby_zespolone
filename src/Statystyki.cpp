#include "Statystyki.hh"
#include <iostream>

using namespace std;

void Statystyka::Inicjuj_Stat()
{
    this->Dobre = 0;
    this->Zle = 0;
}

void Statystyka::Wyswietl_Stat()
{
    cout << "\tStatystyka rozgrywki: " << endl;
    cout << "Poprawnych odpowiedzi: " << this->Dobre << endl;
    cout << "Blednych odpowiedzi: " << this->Zle << endl;
    cout << "Procent prawidlowych odpowiedzi: " 
         << (100*this->Dobre)/(this->Dobre+this->Zle) << "%" << endl;
}