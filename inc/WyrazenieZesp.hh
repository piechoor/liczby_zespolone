#ifndef WYRAZENIEZESP_HH
#define WYRAZENIEZESP_HH



#include "LZespolona.hh"


/*!
 * Modeluje zbior operatorow arytmetycznych.
 */
enum Operator { Op_Dodaj, Op_Odejmij, Op_Mnoz, Op_Dziel };



/*
 * Modeluje pojecie dwuargumentowego wyrazenia zespolonego
 */
struct WyrazenieZesp {
  LZespolona   Arg1;   // Pierwszy argument wyrazenia arytmetycznego
  Operator     Op;     // Opertor wyrazenia arytmetycznego
  LZespolona   Arg2;   // Drugi argument wyrazenia arytmetycznego
};

/*
* Funkcja wyswietla pobrane wyrazenie zespolone w formacie (a+bi)'operator'(c+di)
*/
void Wyswietl(WyrazenieZesp WyrZ);

/*
* Funkcja pobiera znak ze standardowego wejścia i zwraca odpowiedni
* operator typu Operator
*/
Operator WczytajZnak();

/*
* Funkcja zwraca pobrane ze standardowego wejścia wyrażenie zespolone
* Musi być ono postaci (a+bi)'operator'(c+di)
*/
WyrazenieZesp WczytajWyr();

/*
* Funkcja interpretuje podane wyrazenie zespolone, oblicz je oraz
* zwraca jego wartość
*/
LZespolona Oblicz(WyrazenieZesp WyrZ);

#endif
