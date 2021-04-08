#ifndef STATYSTYKI_HH
#define STATYSTYKI_HH

/*
 * Struktura zaiwrajaca pola z liczba dobrych i zlych odpowiedzi
 * oraz funkcji inicjacji i wyswietlenia statystyki
 */
struct Statystyka
{
    unsigned int Dobre, Zle; // Zemienne na liczbe dobrych i zlych odpowiedzi
    void Inicjuj_Stat(); // Funkcja inicjujaca pola struktury
    void Wyswietl_Stat(); // Funkcja wyswietlajaca statystyki testu
};

#endif