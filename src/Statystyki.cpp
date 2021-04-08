#include "Statystyki.hh"
#include <iostream>

using namespace std;

void Statystyka::Inicjuj_Stat()
{
    // Inicjacja pol struktury
    this->Dobre = 0;
    this->Zle = 0;
}

void Statystyka::Wyswietl_Stat()
{
    // Wyswietlenie statystyk
    cout << "Ilosc dobrych odpowiedzi: " << this->Dobre << endl;
    cout << "Ilosc blednych odpowiedzi: " << this->Zle << endl;
    cout << "Wynik procentowy poprawnych odpowiedzi: " 
         << (100*this->Dobre)/(this->Dobre+this->Zle) << "%" << endl;
}