#include <iostream>
#include "data.hpp"

int main()
{
    Game::CardGenerator::initStandardPile();
    auto pile = Game::CardGenerator::shuffle();
    std::cout << "Shuffled." << std::endl;
    std::cout << "Pile.len: " << pile.size() << std::endl;
    int cnt = 0;
    for (auto i : pile)
    {
        cnt++;
        if (cnt == 17)
        {
            std::cout << std::endl;
            cnt = 0;
        }
    }
    std::cout << std::endl;
    return 0;
}