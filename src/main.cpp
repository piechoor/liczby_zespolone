#include <iostream>

#include "BazaTestu.hh"
#include "Statystyki.hh"

using namespace std;

int main(int argc, char **argv)
{
  // Sprawdzenie czy zostal podny argument ustalajacy rodzaj testu
  if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1; // Zakonczenie programu z bledem
  }

  BazaTestu   BazaT = { nullptr, 0, 0 }; // Stworzenie bazy testu

  if (InicjalizujTest(&BazaT,argv[1]) == false) // Proba inicjalizacji bazy testu
  {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1; // Zakonczenoe programu z bledem
  }

  int proba; // Zemienna pomocnicza do zliczania prob rozwiazania wyrazenia
  WyrazenieZesp   WyrZ_PytanieTestowe;
  LZespolona Odp, PrawOdp;
  Statystyka Odpowiedzi;

  Odpowiedzi.Inicjuj_Stat(); // Inicjacja statystyk

  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {
    cout << "Podaj wynik operacji: " << WyrZ_PytanieTestowe << "=" << endl;
    cout << "Twoja odpowiedz: ";
    cin >> Odp; // Pobranie odpowiedzi od uzytkownika

    while (cin.fail()) // Jezeli nastapil blad odczytu wyczysc flage bledu i popros o ponowne wpisanie wyniku
    { 
      cin.clear();
      cout << "Blad zapisu liczby zespolonej. Sprobuj jeszcze raz." << endl << endl;
      cin.ignore(1000, '\n');
      cout << "Twoja odpowiedz: ";
      cin >> Odp;
    }

    PrawOdp = WyrZ_PytanieTestowe.Oblicz(); // Obliczenie prawidlowej odpowiedzi

    if (Odp == PrawOdp) // Jezeli podano prawidlowa odpowiedz dodaj punkty i przejd do nastepnego pytania
    {
      cout << "Odpowiedz poprawna." << endl << endl;
      Odpowiedzi.Dobre++;
    }
    else 
    {
      for (proba=0; proba<3; proba++) // Petla dla trzech prob rozwiaznia wyrazenia
      {
        cout << "Bledna odpowiedz. Sprobuj jeszcze raz: ";
        cin >> Odp;
        if (Odp == PrawOdp) // Jezeli podano dobra odpowiedz zakoncz petle
        {
          cout << "Prawidlowa odpowiedz." << endl << endl;
          Odpowiedzi.Dobre++;
          break;
        }
      }
      if (proba==3) // Jezeli po trzech probach nie udalo sie rozwiazac wyrazenie wyswietl prawidlowa odpowiedz
      {
        cout << "Blad. Prawidlowym wynikiem jest: " << PrawOdp << endl << endl;
        Odpowiedzi.Zle++;
      }
    }
  }

  // Zakonczenie testu i wyswietlenie statystyki
  cout << "Koniec testu" << endl << endl;
  Odpowiedzi.Wyswietl_Stat();
  cout << endl;
  
  return 0;
}
