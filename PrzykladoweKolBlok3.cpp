// PrzykladoweKolBlok3.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#include "zbior.h"
#include <iostream>
using namespace std;
int main()
{
    Zbior zbior1(10,1,5);
    zbior1.pokazZbior();
    std::cout << endl;
    zbior1.setRozmiar(15);
    zbior1.pokazZbior();

    std::cout << endl;
    std::cout << endl;
    Zbior zbior2(5, 1, 5);
    Zbior zbior3(5, 1, 5);
    cout << "Zbior 2:" << endl;
    zbior2.pokazZbior(); cout << endl;
    cout << "Zbior 3:" << endl;
    zbior3.pokazZbior(); cout << endl;
    if (zbior2 > zbior3) cout << "Zbior 2 jest wiekszy"; else cout << "Zbior 3 jest wiekszy";
    cout << " - ";
    if (zbior2 < zbior3) cout << "Zbior 2 jest mniejszy"; else cout <<  "Zbior 3 jest mniejszy";
    cout << endl;
    cout << "Double ze zbioru 3 = " << double(zbior3);

}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
