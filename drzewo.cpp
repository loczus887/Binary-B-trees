#include <iostream>
#include <iomanip>
#include <cmath>

//Struktura węzła drzewa
struct Wezel {
    int klucz;
    Wezel* lewy;
    Wezel* prawy;

    Wezel(int k) : klucz(k), lewy(nullptr), prawy(nullptr) {}
};

//Klasa reprezentująca binarne drzewo poszukiwań
class BinarneDrzewo {
private:
    Wezel* korzen;

    //Pomocnicza funkcja do wstawiania
    Wezel* wstawPomocniczo(Wezel* wezel, int klucz) {
        if (wezel == nullptr) {
            return new Wezel(klucz);
        }
        if (klucz < wezel->klucz) {
            wezel->lewy = wstawPomocniczo(wezel->lewy, klucz);
        } else if (klucz > wezel->klucz) {
            wezel->prawy = wstawPomocniczo(wezel->prawy, klucz);
        }
        return wezel;
    }

    //Pomocnicza funkcja do szukania
    Wezel* szukajPomocniczo(Wezel* wezel, int klucz, int& poziom, Wezel*& ojciec, bool& jestLewySyn) {
        while (wezel != nullptr && wezel->klucz != klucz) {
            ojciec = wezel;
            poziom++;
            if (klucz < wezel->klucz) {
                jestLewySyn = true;
                wezel = wezel->lewy;
            } else {
                jestLewySyn = false;
                wezel = wezel->prawy;
            }
        }
        return wezel;
    }

    //Pomocnicza funkcja do znajdowania minimalnego węzła
    Wezel* znajdzMinimum(Wezel* wezel) {
        while (wezel->lewy != nullptr) {
            wezel = wezel->lewy;
        }
        return wezel;
    }

    //Pomocnicza funkcja do usuwania
    Wezel* usunPomocniczo(Wezel* wezel, int klucz) {
        if (wezel == nullptr) {
            return wezel;
        }
        if (klucz < wezel->klucz) {
            wezel->lewy = usunPomocniczo(wezel->lewy, klucz);
        } else if (klucz > wezel->klucz) {
            wezel->prawy = usunPomocniczo(wezel->prawy, klucz);
        } else {
            if (wezel->lewy == nullptr) {
                Wezel* temp = wezel->prawy;
                delete wezel;
                return temp;
            } else if (wezel->prawy == nullptr) {
                Wezel* temp = wezel->lewy;
                delete wezel;
                return temp;
            }
            Wezel* temp = znajdzMinimum(wezel->prawy);
            wezel->klucz = temp->klucz;
            wezel->prawy = usunPomocniczo(wezel->prawy, temp->klucz);
        }
        return wezel;
    }

    //Pomocnicza funkcja do wyświetlania drzewa
    void wyswietlPomocniczo(Wezel* wezel, int poziom) {
        if (wezel != nullptr) {
            wyswietlPomocniczo(wezel->prawy, poziom + 1);
            std::cout << std::setw(poziom * 5) << wezel->klucz << "\n";
            wyswietlPomocniczo(wezel->lewy, poziom + 1);
        }
    }

    //Funkcja pomocnicza do drukowania drzewa w dół
    void drukujDrzewo(Wezel* korzen, int spacja) {
        if (korzen == nullptr)
            return;

        spacja += 10;

        drukujDrzewo(korzen->prawy, spacja);

        std::cout << std::endl;
        for (int i = 10; i < spacja; i++)
            std::cout << " ";
        std::cout << korzen->klucz << "\n";

        drukujDrzewo(korzen->lewy, spacja);
    }

public:
    BinarneDrzewo() : korzen(nullptr) {}

    //Funkcja wstawiania
    void wstaw(int klucz) {
        korzen = wstawPomocniczo(korzen, klucz);
    }

    //Funkcja szukania
    bool szukaj(int klucz) {
        int poziom = 0;
        Wezel* ojciec = nullptr;
        bool jestLewySyn = false;
        Wezel* wynik = szukajPomocniczo(korzen, klucz, poziom, ojciec, jestLewySyn);
        if (wynik != nullptr) {
            std::cout << "Klucz " << klucz << " znaleziono na poziomie " << poziom;
            if (ojciec != nullptr) {
                if (jestLewySyn) {
                    std::cout << " jako lewy syn węzła o kluczu " << ojciec->klucz << ".\n";
                } else {
                    std::cout << " jako prawy syn węzła o kluczu " << ojciec->klucz << ".\n";
                }
            } else {
                std::cout << " (jest to korzeń drzewa).\n";
            }
            return true;
        } else {
            std::cout << "Klucz " << klucz << " nie znaleziono w drzewie.\n";
            return false;
        }
    }

    //Funkcja usuwania
    void usun(int klucz) {
        korzen = usunPomocniczo(korzen, klucz);
    }

    //Funkcja do wyświetlania drzewa
    void wyswietl() {
        drukujDrzewo(korzen, 0);
    }
};

int main() {
    BinarneDrzewo drzewo;
    int wybor, klucz;

    while (true) {
        std::cout << "1. Wstaw\n2. Szukaj\n3. Usuń\n4. Wyświetl\n5. Wyjście\n";
        std::cout << "Wybierz opcję: ";
        std::cin >> wybor;

        switch (wybor) {
            case 1:
                std::cout << "Podaj klucz do wstawienia: ";
                std::cin >> klucz;
                drzewo.wstaw(klucz);
                break;
            case 2:
                std::cout << "Podaj klucz do szukania: ";
                std::cin >> klucz;
                drzewo.szukaj(klucz);
                break;
            case 3:
                std::cout << "Podaj klucz do usunięcia: ";
                std::cin >> klucz;
                drzewo.usun(klucz);
                break;
            case 4:
                std::cout << "Drzewo: \n";
                drzewo.wyswietl();
                break;
            case 5:
                return 0;
            default:
                std::cout << "Niepoprawna opcja. Spróbuj ponownie.\n";
        }
    }

    return 0;
}
