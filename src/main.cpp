#include <iostream>
#include "BazaTestu.hh"
#include <cstdio>

using namespace std;


int main(int argc, char **argv)
{

  LZespolona Z1, Z2;
  WyrazenieZesp W1, W2;
  cout << "Pierwsza liczba:" << endl;
  Z1 = WczytajLicz();
  cout << "Druga liczba:" << endl;
  Z2 = WczytajLicz();
  W1.Arg1 = Z1;
  W1.Arg2 = Z2;
  W1.Op = Op_Dodaj;
  cout << "Wyrazenie:" << endl;
  W2 = WczytajWyr();
  cout << "Wyswietlona pierwsza liczba:" << endl;
  Wyswietl(Z1);
  cout << endl << "Wyswietlona druga liczba:" << endl;
  Wyswietl(Z2);
  cout << endl << "Wyswietlone pierwsze wyrazenie:" << endl;
  Wyswietl(W1);
  cout << endl << "Wyswietlone drugie wyrazenie:" << endl;
  Wyswietl(W2);
  cout << endl;
  cout << "Obliczone wyrazenie:" << endl;
  Wyswietl(Oblicz(W2));
  cout << endl;

/*
	 *
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
  
  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {
    cout << " Czesc rzeczywista pierwszego argumentu: ";
    cout << WyrZ_PytanieTestowe.Arg1.re << endl;
  }

  
  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;
*/
}
