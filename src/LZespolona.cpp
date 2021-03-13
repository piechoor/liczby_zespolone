#include "LZespolona.hh"
#include <cassert>
#include <iostream>
#include <cmath>

using namespace std;

void Wyswietl(LZespolona Z1)
{
	cout << "(" << Z1.re << showpos << Z1.im << "i)";
}

LZespolona Wczytaj()
{
  LZespolona Wynik;
  float Rzecz, Uroj;
  cin >> Rzecz >> Uroj;
  
  Wynik.re = Rzecz;
  Wynik.im = Uroj;

  return Wynik;
}

LZespolona Sprzezenie(LZespolona Z1)
{
  Z1.im *= (-1);
  return Z1;
}

float Modul(LZespolona Z1)
{
  float modul;
  modul = sqrt(pow(Z1.re, 2) + pow(Z1.im, 2));
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

LZespolona operator - (LZespolona Skl1, LZespolona Skl2)
{
  LZespolona Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}

LZespolona operator * (LZespolona Skl1, LZespolona Skl2)
{
  LZespolona Wynik;

  Wynik.re = Skl1.re * Skl2.re - Skl1.im * Skl2.im;
  Wynik.im = Skl1.re * Skl2.im + Skl2.re * Skl1.im;
  return Wynik;
}

LZespolona operator / (LZespolona Z1, float Dzielnik)
{
  LZespolona Wynik;

  assert(Dzielnik != 0);

  Wynik.re = Z1.re / Dzielnik;
  Wynik.im = Z1.im / Dzielnik;

  return Wynik;
}

LZespolona operator / (LZespolona Skl1, LZespolona Skl2)
{
  LZespolona Wynik;
  float dzielnik;

  assert((Skl1.re != 0) && (Skl2.im !=0));
  dzielnik = pow(Modul(Skl2), 2);
  Wynik = Skl1 * Sprzezenie(Skl2);

  Wynik = Wynik / dzielnik;

  return Wynik;
}