#include <iostream>
#include <ctime>
#include <cstdlib>

int main(void)
{
    srand(time(NULL));
    for (int i = 0; i < 5; i++)
    {
        std::cout << "Random number#" << i + 1 << " " << rand() % 100 << std::endl;
    }

    return 0;
}