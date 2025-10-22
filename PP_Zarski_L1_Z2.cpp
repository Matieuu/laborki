#include <iostream>
#include <cmath>

int main(void)
{
    double a0, a1, a2;

loop:
    std::cout << "Podaj współczynnik od wyrazu dominującego: ";
    std::cin >> a0;

    std::cout << "Podaj współczynnik od wyrazu środkowego: ";
    std::cin >> a1;

    std::cout << "Podaj współczynnik od wyrazu wolnego: ";
    std::cin >> a2;

    if (a0 == 0 && a1 == 0 && a2 == 0)
    {
        std::cout << "Kończenie wykonywania programu";
        return 0;
    }
    else if (a0 == 0 && a1 == 0)
        std::cout << "Funkcja nie ma miejsca zerowego";
    else if (a0 == 0)
        std::cout << "Jedyne miejsce zerowe funkcji jest w x = " << -a2 / a1;
    else
    {
        double delta = a1 * a1 - (4 * a0 * a2);
        if (delta < 0)
            std::cout << "Funkcja nie ma miejsc zerowych";
        else if (delta == 0)
            std::cout << "Funkcja jest styczna z osią 0x w " << -a1 / 2 * a0;
        else
        {
            double x1 = -a1 - std::sqrt(delta) / 2 * a0;
            double x2 = -a1 + std::sqrt(delta) / 2 * a0;
            std::cout << "Funkcja ma 2 miejsca zerowe w x = " << x1 << " oraz w x = " << x2;
        }
    }
    std::cout << "\n\n";
    goto loop;
}