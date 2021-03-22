#include "LZespolona.hh"
#include <cassert>
#include <iostream>
#include <cmath>

using namespace std;

ostream& operator << (ostream &Str_wyj, LZespolona Z1)
{
  Str_wyj << "(" << Z1.re << showpos << Z1.im << noshowpos << "i)";
  return Str_wyj;
} 

istream& operator >> (istream &Str_wej, LZespolona &Z1)
{
    char nawias_L = 'x', nawias_P = 'x', Znak_i = 'x';

    Str_wej >> nawias_L >> Z1.re >> Z1.im >> Znak_i >> nawias_P;

    if (nawias_L != '(' || nawias_P != ')' || Znak_i != 'i')
      Str_wej.setstate(ios::failbit);

    return Str_wej;
}

LZespolona WczytajLicz()
{
  LZespolona Wynik;
  char im; // Bufor na znak 'i'
  double Rzecz, Uroj;
  cin >> Rzecz >> Uroj >> im; // Wczytanie liczby zespolonej
  
  Wynik.re = Rzecz;
  Wynik.im = Uroj;

  return Wynik;
}

LZespolona Sprzezenie(LZespolona Z1)
{
  Z1.im *= (-1); // Zamiana znaku urojonej części liczby rzeczywistej
  return Z1;
}

double Modul(LZespolona Z1)
{
  double modul;
  modul = sqrt(pow(Z1.re, 2) + pow(Z1.im, 2)); // Oblicza modul liczby zespolonej
  return modul;
}

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;
  
  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}

/*!
 * Realizuje odejmowanie dwoch liczb zespolonych.
 * Argumenty:
 *    Odjemna - pierwszy skladnik odejmowania,
 *    Odjemnik - drugi skladnik odejmowania.
 * Zwraca:
 *    Różnicę dwoch skladnikow przekazanych jako parametry.
 */
LZespolona operator - (LZespolona Odjemna, LZespolona Odjemnik)
{
  LZespolona Wynik;

  Wynik.re = Odjemna.re - Odjemnik.re;
  Wynik.im = Odjemna.im - Odjemnik.im;
  return Wynik;
}

/*!
 * Realizuje mnożenie dwoch liczb zespolonych.
 * Argumenty:
 *    Czyn1 - pierwszy skladnik mnożenia,
 *    Czyn2 - drugi skladnik mnożenia.
 * Zwraca:
 *    Iloczyn dwoch skladnikow przekazanych jako parametry.
 */
LZespolona operator * (LZespolona Czyn1, LZespolona Czyn2)
{
  LZespolona Wynik;

  Wynik.re = Czyn1.re * Czyn2.re - Czyn1.im * Czyn2.im;
  Wynik.im = Czyn1.re * Czyn2.im + Czyn2.re * Czyn1.im;
  return Wynik;
}

/*!
 * Realizuje dzielenie liczby zespolonej przez liczbę rzeczywistą różną od zera
 * Argumenty:
 *    Z1 - liczba zespolona,
 *    Dzielnik - liczba rzeczywista.
 * Zwraca:
 *    Iloraz liczby zespolonej i rzeczywistej.
 */
LZespolona operator / (LZespolona Z1, double Dzielnik)
{
  LZespolona Wynik;

  assert(Dzielnik != 0); // Sprawdzenie czy dzielnik jest różny od zera

  Wynik.re = Z1.re / Dzielnik;
  Wynik.im = Z1.im / Dzielnik;

  return Wynik;
}

/*!
 * Realizuje dzielenie dwoch liczb zespolonych.
 * Argumenty:
 *    Dzielna - pierwszy skladnik dzielenia,
 *    Dzielnik - drugi skladnik dzielenia.
 * Zwraca:
 *    Iloraz dwoch skladnikow przekazanych jako parametry.
 */
LZespolona operator / (LZespolona Dzielna, LZespolona Dzielnik)
{
  LZespolona Wynik;
  double czynnik;

  assert((Dzielna.re != 0) && (Dzielnik.im !=0)); // Sprawdzenie czy możliwe jest dzielenie

  czynnik = pow(Modul(Dzielnik), 2);
  Wynik = Dzielna * Sprzezenie(Dzielnik);

  Wynik = Wynik / czynnik;

  return Wynik;
}

