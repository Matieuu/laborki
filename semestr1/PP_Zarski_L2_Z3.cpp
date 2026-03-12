#include <iostream>
#include <unistd.h>

void draw(int step)
{
    for (int j = 0; j < (step) * 2; j++)
    {
        for (int i = 0; i < step; i++)
        {
            std::cout << "* * ";
        }
        std::cout << std::endl;
    }
}

int main(void)
{
    while (true)
    {
        for (int i = 0; i <= 4; i++)
        {
            system("clear");
            draw(i);
            sleep(1);
        }
    }
}
