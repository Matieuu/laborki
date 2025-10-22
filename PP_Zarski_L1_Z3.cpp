#include <iostream>
#include <cmath>

int main(void)
{
    int p, q;

loop:
    std::cout << "Wynik 1. rzutu kostką: ";
    std::cin >> p;

    std::cout << "Wynik 2. rzutu kostką: ";
    std::cin >> q;

    if (p == 0)
    {
        std::cout << "Kończenie wykonywania programu";
        return 0;
    }
    if (p < 0 || p > 6)
    {
        std::cout << "Nieprawidołowa wartość";
    }
    else if (p % 2)
    {
        switch (q)
        {
        case 1:
        case 3:
        case 6:
            if (p == q)
                std::cout << "Wygrana: " << 5 * p + 3;
            else
                std::cout << "Wygrana: " << 2 * q + 5;
            break;
        case 2:
        case 4:
        case 5:
            std::cout << "Wygrana: " << std::min(p, q) + 4;
            break;
        default:
            std::cout << "Nieprawidołowa wartość";
            break;
        }
    }
    else
    {
        switch (q)
        {
        case 1:
        case 3:
        case 6:
            std::cout << "Wygrana: " << 2 * q;
            break;
        case 2:
        case 4:
        case 5:
            std::cout << "Wygrana: " << p + 3 * q;
            break;
        default:
            std::cout << "Nieprawidołowa wartość";
            break;
        }
    }

    std::cout << "\n\n";
    goto loop;
}