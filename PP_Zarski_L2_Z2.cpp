#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <string>
#include <cctype>

bool g_Running = true;
int g_TryCount = 0;

char asciitolower(char in)
{
    if (in <= 'Z' && in >= 'A')
        return in - ('Z' - 'z');
    return in;
}

void player_guessing(void)
{
    int num = std::rand() % 20, user_guess, guesses_count = 0;
    do
    {
        guesses_count++;
        std::cout << "Dokonaj wyboru <0;20>: ";
        std::cin >> user_guess;

        if (user_guess == num)
        {
            std::cout << "Gratulacje. Przetrwałeś swoją próbę.\n\n";
            return;
        }
        else if (user_guess < num)
        {
            std::cout << "Liczba jest za mała.\n";
        }
        else
        {
            std::cout << "Liczba jest za duża.\n";
        }
    } while (guesses_count != 5);

    std::cout << "Twój czas minął.\n\n";
}

void computer_guessing(void)
{
    int min = 0, max = 20, guesses_count = 0;

    std::cout << "Pozwól, że przedstawię zasady\nLosuję liczbę, jeśli liczba jest za mała to odpisujesz \"m\", jeśli liczba jest za duża - \"d\", a jeśli trafiłem odpisujesz \"z\"\nNie musisz używać polskich znaków.\n\n";

    do
    {
        int range = max - min, guess;
        bool correct_ans = true;
        char ans;
        guesses_count++;

        if (range)
            guess = min + (std::rand() % range);
        else
            guess = min;

        std::cout << "Czy Twoja liczba to " << guess << std::endl;
        std::cin >> ans;

        do
        {
            correct_ans = true;
            switch (::tolower(ans))
            {
            case 'm':
                min = guess + 1;
                break;
            case 'd':
                max = guess - 1;
                break;
            case 'z':
                std::cout << "Udowodniłeś, że twoje zasady mają znaczenie.\n\n";
                return;
            default:
                std::cout << "Dokonaj wyboru\n";
                correct_ans = false;
                break;
            }
        } while (!correct_ans);

        if (min > max)
        {
            std::cout << "Miałeś dokonać wyboru.\n\n";
            return;
        }
    } while (guesses_count != 5);

    std::cout << "Zawiodłeś własną filozofię.\n\n";
}

int main(void)
{
    std::srand(std::time(0));
    while (g_Running)
    {
        int choice;
        std::cout << "I want to play a game\n1. Zgadujesz Ty\n2. Zgaduje komputer\n3. Wyjście\n";
        std::cin >> choice;
        std::cout << "\n";

        switch (choice)
        {
        case 1:
            std::cout << "Twoja gra właśnie się zaczyna.\n\n";
            g_TryCount++;
            player_guessing();
            break;
        case 2:
            std::cout << "Twoja gra właśnie się zaczyna.\n\n";
            g_TryCount++;
            computer_guessing();
            break;
        case 3:
            g_Running = false;
            break;
        default:
            std::cout << "Dokonałeś (złego) wyboru.\n\n";
            break;
        }
    }

    std::cout << "Game over\nIlość prób: " << g_TryCount;
}