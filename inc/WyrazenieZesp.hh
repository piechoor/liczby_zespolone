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
* Funkcja pobiera znak ze standardowego wejścia i zwraca odpowiedni
* operator typu Operator
*/
Operator WczytajZnak();

std::ostream& operator << (std::ostream &Str_wyj, Operator Op);

std::ostream& operator << (std::ostream &Str_wyj, WyrazenieZesp W1);

std::istream& operator >> (std::istream &Str_wej, WyrazenieZesp &W1);

/*
* Funkcja interpretuje podane wyrazenie zespolone, oblicz je oraz
* zwraca jego wartość
*/
LZespolona Oblicz(WyrazenieZesp WyrZ);

#endif
