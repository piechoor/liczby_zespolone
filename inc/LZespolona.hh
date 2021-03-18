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
* Funkcja wyswietla pobraną liczbę zespoloną w formacie (a+bi)
*/
void Wyswietl(LZespolona Z1);

/*
* Funkcja zwraca pobraną ze standardowego wejścia liczbe zespoloną
* Musi być ona postaci a+bi
*/
LZespolona WczytajLicz();

/*
* Funckja zwraca sprzężenie pobranej liczby zespolonej
*/
LZespolona Sprzezenie(LZespolona Z1);

/*
* Funckja zwraca moduł pobranej liczby zespolonej
*/
double Modul(LZespolona Z1);

/*
* Przeciążenie operatora dzielenia dla opercji dzielenia liczby 
* zespolonej przez liczbę rzeczywistą
*/
LZespolona operator / (LZespolona Z1, double Dzielnik);

/*
* Przeciążenia operatorów operacji na dwóch liczbach zespolonych
*/
LZespolona operator + (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona operator - (LZespolona Odjemna, LZespolona Odjemnik);
LZespolona operator * (LZespolona Czyn1, LZespolona Czyn2);
LZespolona operator / (LZespolona Dzielna, LZespolona Dzielnik);

#endif
