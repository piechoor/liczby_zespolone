#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH
#include <iostream>

/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona 
{
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */

  double Modul();
  LZespolona Sprzezenie();
  LZespolona operator + (LZespolona Z2) const;
  LZespolona operator - (LZespolona Z2) const;
  LZespolona operator * (LZespolona Z2) const;
  LZespolona operator / (double Dzielnik) const;
  LZespolona operator / (LZespolona Dzielnik);
};

std::ostream& operator << (std::ostream &Str_wyj, LZespolona Z1);

std::istream& operator >> (std::istream &Str_wej, LZespolona &Z1);

/*
* Funckja zwraca sprzężenie pobranej liczby zespolonej
*/

/*
* Funckja zwraca moduł pobranej liczby zespolonej
*/

/*
* Przeciążenie operatora dzielenia dla opercji dzielenia liczby 
* zespolonej przez liczbę rzeczywistą
*/

/*
* Przeciążenia operatorów operacji na dwóch liczbach zespolonych
*/
//LZespolona operator + (LZespolona  Skl1,  LZespolona  Skl2);
//LZespolona operator - (LZespolona Odjemna, LZespolona Odjemnik);
//LZespolona operator * (LZespolona Czyn1, LZespolona Czyn2);


#endif
