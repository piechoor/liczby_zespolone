#include <iostream>
#include "BazaTestu.hh"
#include <cstdio>

using namespace std;


int main(int argc, char **argv)
{

  LZespolona Z1;
  WyrazenieZesp W1;
  cout << "Liczba:" << endl;
  cin >> Z1;
  W1.Arg1 = Z1;
  W1.Arg2 = Z1;
  W1.Op = Op_Dodaj;
  cout << "Wyrazenie:" << endl;
  cin >> W1;
  if (cin.fail()) cout << "Wczytanie liczby nie powiodlo sie" << endl;
    else {
      cout << "Wyswietlona liczba:" << endl;
      cout << Z1;
    }
  cout << endl << "Wyswietlone wyrazenie:" << endl;
  cout << W1;
  cout << endl;
  cout << "Obliczone wyrazenie:" << endl;
  cout << Oblicz(W1);
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
