#include <iostream>
//#include <cstdio>
#include "BazaTestu.hh"
#include "Statystyki.hh"

using namespace std;


int main(int argc, char **argv)
{
  if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }


  BazaTestu   BazaT = { nullptr, 0, 0 };

  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }


  
  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

  WyrazenieZesp   WyrZ_PytanieTestowe;
  LZespolona Odp, PrawOdp;
  Statystyka Odpowiedzi;
  Odpowiedzi.Inicjuj_Stat();

  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {
    cout << "Wyrazenie: " << endl;
    cout << WyrZ_PytanieTestowe << endl;
    cout << "Podaj wynik wyrazenia:";
    cin >> Odp;
    while (cin.fail()) {
      cin.clear();
      cout << "Podano liczbe w zlym formacie, sprobuj jeszcze raz." << endl;
      cin >> Odp;
    }
    PrawOdp = WyrZ_PytanieTestowe.Oblicz();
    if (Odp.re == PrawOdp.re && Odp.im == PrawOdp.im) {
      cout << "Prawidlowa odpowiedz." << endl;
      Odpowiedzi.Dobre++;
    }
    else {
    cout << "Nierawidlowa odpowiedz." << endl;
    Odpowiedzi.Zle++;
    }
  }

  
  cout << endl;
  Odpowiedzi.Wyswietl_Stat();
  cout << "Koniec testu" << endl;
  cout << endl;
}
