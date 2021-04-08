#ifndef WYRAZENIEZESP_HH
#define WYRAZENIEZESP_HH

#include "LZespolona.hh"

/*!
 * Modeluje zbior operatorow arytmetycznych.
 */
enum Operator { Op_Dodaj, Op_Odejmij, Op_Mnoz, Op_Dziel };

/*
 * Struktura zawierajaca dwa argumenty wyrazenia zespolonego, jego operator
 * i funkcje pozwalajaca obliczyc jego wartosc
 */
struct WyrazenieZesp 
{
  LZespolona   Arg1;   // Pierwszy argument wyrazenia arytmetycznego
  Operator     Op;     // Opertor wyrazenia arytmetycznego
  LZespolona   Arg2;   // Drugi argument wyrazenia arytmetycznego

  LZespolona Oblicz();  // Funkcja zwracajaca wartosc wyrazenia zespolonego ze struktury
};

/*
* Funkcja pobiera znak ze standardowego wejścia i zwraca odpowiedni
* operator typu Operator
*/
Operator WczytajZnak();

/*
* Przeciazenie strumienia wyjsciowego dla wyswietlania typu Operator
*/
std::ostream& operator << (std::ostream &Str_wyj, Operator Op);

/*
* Przeciazenie strumienia wyjsciowego dla wyswietlania wyrazenia zespolonego
*/
std::ostream& operator << (std::ostream &Str_wyj, WyrazenieZesp W1);

/*
* Przeciazenie strumienia wejsciowego dla wczytywania wyrazenia zespolonego
*/
std::istream& operator >> (std::istream &Str_wej, WyrazenieZesp &W1);

#endif
