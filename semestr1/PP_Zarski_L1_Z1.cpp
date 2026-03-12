#include <iostream>

int main(void)
{
    char op;
    double num1, num2;

loop:
    std::cout << "Podaj 1. liczbę: ";
    std::cin >> num1;

    std::cout << "Podaj 2. liczbę: ";
    std::cin >> num2;

    std::cout << "Podaj operator: ";
    std::cin >> op;

    switch (op)
    {
    case '+':
        std::cout << "Wynik dodawania: " << num1 + num2;
        break;
    case '-':
        std::cout << "Wynik odejmowania: " << num1 - num2;
        break;
    case '*':
        std::cout << "Wynik mnożenia: " << num1 * num2;
        break;
    case '/':
        if (num2 == 0)
            std::cout << "Nie można dzielić przez 0";
        else
            std::cout << "Wynik dzielenia: " << num1 / num2;
        break;
    case 's':
        std::cout << "Kończenie działania programu";
        return 0;
    default:
        std::cout << "Nieznany operator " << op;
        break;
    }
    std::cout << "\n\n";
    goto loop;
}
