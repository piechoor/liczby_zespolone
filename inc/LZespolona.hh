#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
};


/*
 * Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */

void Wyswietl(LZespolona Z1);

LZespolona WczytajLicz();

LZespolona Sprzezenie(LZespolona Z1);

float Modul(LZespolona Z1);

LZespolona operator + (LZespolona  Skl1,  LZespolona  Skl2);

LZespolona operator - (LZespolona Odjemna, LZespolona Odjemnik);

LZespolona operator * (LZespolona Czyn1, LZespolona Czyn2);

LZespolona operator / (LZespolona Z1, float Dzielnik);
LZespolona operator / (LZespolona Dzielna, LZespolona Dzielnik);

#endif
