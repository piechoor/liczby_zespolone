#include "LZespolona.hh"
#include <cassert>
#include <iostream>
#include <cmath>

using namespace std;

double LZespolona::Modul()
{
  return sqrt(pow(this->re, 2) + pow(this->im, 2)); // Oblicza modul liczby zespolonej i zwraca obliczona wartosc
}

LZespolona LZespolona::Sprzezenie()
{
  LZespolona Wynik;

  Wynik.re = this->re; // Czesc rzeczywista nie zmienia sie
  Wynik.im = -this->im; // Zamiana znaku urojonej części liczby rzeczywistej

  return Wynik;
}

/*!
 * Realizuje dodanie dwoch liczb zespolonych, jednej zawierajacej sie w polach
 * struktury i drugiej podanej jako parametr
 * Zwraca sume tych liczb
 */
LZespolona LZespolona::operator + (LZespolona Z2) const
{
  Z2.re += this->re; // Dodanie czesci rzeczywistych
  Z2.im += this->im; // Dodanie czesci urojonych

  return Z2;
}

/*!
 * Realizuje odejmowanie dwoch liczb zespolonych, jednej zawierajacej sie w polach
 * struktury i drugiej podanej jako parametr
 * Zwraca roznice tych liczb
 */
LZespolona LZespolona::operator - (LZespolona Z2) const
{
  Z2.re = this->re - Z2.re; // Odjecie czesci rzeczywistych
  Z2.im = this->im - Z2.im; // Odjecie czesci urojonych

  return Z2;
}

/*!
 * Realizuje mnozenie dwoch liczb zespolonych, jednej zawierajacej sie w polach
 * struktury i drugiej podanej jako parametr
 * Zwraca iloczyn tych liczb
 */
LZespolona LZespolona::operator * (LZespolona Z2) const
{
  LZespolona Wynik;

  Wynik.re = this->re * Z2.re - this->im * Z2.im; // Obliczenie czesci rzeczywistej wyniku
  Wynik.im = this->re * Z2.im + Z2.re * this->im; // Obliczenie czesci urojonej wyniku

  return Wynik;
}

/*!
 * Realizuje dzielenie liczby zespolonej i podanego jako parametr dzielnika
 * bedacego liczba rzeczywista
 * Zwraca iloraz liczby zespolonej i dzielnika
 */
LZespolona LZespolona::operator / (double Dzielnik) const
{
  LZespolona Wynik;

  if (Dzielnik == 0) // Jezeli operacja jest nieprawidlowa wyswietlenie bledu
    cerr << "Proba podzielenia liczby zespolonej przez 0! Program zostal wstrzymany." << endl;
  assert(Dzielnik != 0); // Sprawdzenie czy dzielnik jest różny od zera

  Wynik.re = this->re / Dzielnik; // Obliczenie czesci rzeczywistej
  Wynik.im = this->im / Dzielnik; // Obliczenie czesci urojonej

  return Wynik;
}

/*!
 * Realizuje dzielenie dwoch liczb zespolonych, jednej zawierajacej sie w polach
 * struktury i drugiej podanej jako parametr
 * Zwraca iloraz podanych liczb zespolonych
 */ 
LZespolona LZespolona::operator / (LZespolona Dzielnik)
{
  LZespolona Wynik;
  double czynnik;

  if ((Dzielnik.re == 0) && (Dzielnik.im ==0))  // Jezeli operacja jest niepoprawna, wyswietlenie bledu
    cerr << "Proba podzielenia liczby zespolonej przez 0! Program zostal wstrzymany." << endl;
  assert((Dzielnik.re != 0) || (Dzielnik.im !=0)); // Sprawdzenie czy możliwe jest dzielenie

  czynnik = pow(Dzielnik.Modul(), 2); // Obliczenie mianownika
  Wynik = *this * Dzielnik.Sprzezenie(); // Obliczenie licznika
  Wynik = Wynik / czynnik; // Obliczenie wyniku

  return Wynik;
}

/*!
 * Porownuje dwie liczby zespolone i w zaleznosci od rownosci zwraca
 * prawde liub falsz
 */
bool LZespolona::operator == (LZespolona Z2)
{
  if (this->re == Z2.re && this->im == Z2.im) // Sprawdzenie rownosci liczb
    return true;
  else return false;
}


ostream& operator << (ostream &Str_wyj, LZespolona Z1)
{
  Str_wyj << "(" << Z1.re << showpos << Z1.im << noshowpos << "i)"; // Wyswietlenie l zespolonej w prawidlowym formacie
  return Str_wyj;
} 

istream& operator >> (istream &Str_wej, LZespolona &Z1)
{
    char nawias_L = 'x', nawias_P = 'x', Znak_i = 'x';

    Str_wej >> nawias_L >> Z1.re >> Z1.im >> Znak_i >> nawias_P; // Pobranie liczby w zadanym formacie

    if (nawias_L != '(' || nawias_P != ')' || Znak_i != 'i')
      Str_wej.setstate(ios::failbit); // Jezeli pobrano nieprawidlowy znak ustaw flage bledu

    return Str_wej;
}
