#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH
#include <iostream>

/*!
 *  Definicja struktury LZesplona, zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze oraz operacji potrzebnych do ich przeprowadzenia
 */
struct  LZespolona 
{
  double   re;    // Pole repezentuje czesc rzeczywista
  double   im;    // Pole repezentuje czesc urojona

  double Modul(); // Funkcja zwracajaca modul liczby zespolonej
  LZespolona Sprzezenie(); // Funckja zwracajaca liczbe bedaca sprezeniem zespolonej
  LZespolona operator + (LZespolona Z2) const; // Przeciazenie operatora dodawania dla liczb zespolonych
  LZespolona operator - (LZespolona Z2) const; // Przeciazenie operatora odejmowania dla liczb zespolonych
  LZespolona operator * (LZespolona Z2) const; // Przeciazenie operatora mnozenia dla liczb zespolonych
  LZespolona operator / (double Dzielnik) const; // Przeciazenie operatora dzielenia dla liczby zespolonej przez rzeczywista
  LZespolona operator / (LZespolona Dzielnik); // Przeciazenie operatora dzielenia dla liczb zespolonych
  bool operator == (LZespolona Z2); // Przeciazenie operatora porownania dla liczb zespolonych
};

/*
 *  Przeciazenie strumienia wyjsciowego dla wyswietlania liczby zespolonej
 */ 
std::ostream& operator << (std::ostream &Str_wyj, LZespolona Z1);

/*
 *  Przeciazenie strumienia wejsciowego dla wczytywania liczby zespolonej
 */ 
std::istream& operator >> (std::istream &Str_wej, LZespolona &Z1);

#endif
