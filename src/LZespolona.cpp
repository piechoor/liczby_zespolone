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

double LZespolona::Modul()
{
  return sqrt(pow(this->re, 2) + pow(this->im, 2)); // Oblicza modul liczby zespolonej
}

LZespolona LZespolona::Sprzezenie()
{
  LZespolona Wynik;
  Wynik.re = this->re;
  Wynik.im = -this->im; // Zamiana znaku urojonej części liczby rzeczywistej
  return Wynik;
}

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */

LZespolona LZespolona::operator + (LZespolona Z2) const
{
  Z2.re += this->re;
  Z2.im += this->im;
  return Z2;
}

LZespolona LZespolona::operator - (LZespolona Z2) const
{
  Z2.re = this->re - Z2.re;
  Z2.im = this->im - Z2.im;
  return Z2;
}

LZespolona LZespolona::operator * (LZespolona Z2) const
{
  LZespolona Wynik;

  Wynik.re = this->re * Z2.re - this->im * Z2.im;
  Wynik.im = this->re * Z2.im + Z2.re * this->im;
  return Wynik;
}

/*
 * Realizuje odejmowanie dwoch liczb zespolonych.
 * Argumenty:
 *    Odjemna - pierwszy skladnik odejmowania,
 *    Odjemnik - drugi skladnik odejmowania.
 * Zwraca:
 *    Różnicę dwoch skladnikow przekazanych jako parametry.
 */
/*

/*!
 * Realizuje mnożenie dwoch liczb zespolonych.
 * Argumenty:
 *    Czyn1 - pierwszy skladnik mnożenia,
 *    Czyn2 - drugi skladnik mnożenia.
 * Zwraca:
 *    Iloczyn dwoch skladnikow przekazanych jako parametry.
 */
/*!
 * Realizuje dzielenie liczby zespolonej przez liczbę rzeczywistą różną od zera
 * Argumenty:
 *    Z1 - liczba zespolona,
 *    Dzielnik - liczba rzeczywista.
 * Zwraca:
 *    Iloraz liczby zespolonej i rzeczywistej.
 */

LZespolona LZespolona::operator / (double Dzielnik) const
{
  LZespolona Wynik;

  if (Dzielnik == 0) 
    cerr << "Proba podzielenia liczby zespolonej przez 0! Program zostal wstrzymany." << endl;
  assert(Dzielnik != 0); // Sprawdzenie czy dzielnik jest różny od zera

  Wynik.re = this->re / Dzielnik;
  Wynik.im = this->im / Dzielnik;
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
LZespolona LZespolona::operator / (LZespolona Dzielnik)
{
  LZespolona Wynik;
  double czynnik;

  if ((Dzielnik.re == 0) && (Dzielnik.im ==0)) 
    cerr << "Proba podzielenia liczby zespolonej przez 0! Program zostal wstrzymany." << endl;
  assert((Dzielnik.re != 0) || (Dzielnik.im !=0)); // Sprawdzenie czy możliwe jest dzielenie

  czynnik = pow(Dzielnik.Modul(), 2);
  Wynik = *this * Dzielnik.Sprzezenie();
  Wynik = Wynik / czynnik;
  return Wynik;
}

