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

  int proba;
  WyrazenieZesp   WyrZ_PytanieTestowe;
  LZespolona Odp, PrawOdp;
  Statystyka Odpowiedzi;
  Odpowiedzi.Inicjuj_Stat();

  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {
    cout << "Podaj wynik operacji: " << WyrZ_PytanieTestowe << "=" << endl;
    cout << "Twoja odpowiedz: ";
    cin >> Odp;
    while (cin.fail()) {
      cin.clear();
      cout << "Blad zapisu liczby zespolonej. Sprobuj jeszcze raz." << endl << endl;
      cin.ignore(100, '\n');
      cout << "Twoja odpowiedz: ";
      cin >> Odp;
    }
    PrawOdp = WyrZ_PytanieTestowe.Oblicz();
    if (Odp.re == PrawOdp.re && Odp.im == PrawOdp.im) {
      cout << "Odpowiedz poprawna." << endl << endl;
      Odpowiedzi.Dobre++;
    }
    else {
      for (proba=0; proba<3; proba++) {
        cout << "Bledna odpowiedz. Sprobuj jeszcze raz: ";
        cin >> Odp;
        if (Odp.re == PrawOdp.re && Odp.im == PrawOdp.im) {
          cout << "Prawidlowa odpowiedz." << endl << endl;
          Odpowiedzi.Dobre++;
          break;
        }
      }
      if (proba==3) {
        cout << "Blad. Prawidlowym wynikiem jest: " << PrawOdp << endl << endl;
        Odpowiedzi.Zle++;
      }
    }
  }

  cout << "Koniec testu" << endl << endl;
  Odpowiedzi.Wyswietl_Stat();
  cout << endl;
}
