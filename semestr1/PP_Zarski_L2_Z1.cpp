#include <iostream>

int main(void)
{
    int sum = 0, last, num;

    while (num != 99)
    {
        std::cout << "Podaj liczbę: ";
        std::cin >> num;

        if (-15 <= num && num <= 15)
        {
            last = num;
            sum += num;
        }
    }

    std::cout << "Suma wynosi: " << sum << std::endl;
}