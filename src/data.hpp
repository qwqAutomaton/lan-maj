#pragma once
#include <random>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
namespace Game
{
    namespace Random
    {
        std::random_device rd;
        std::mt19937 rng(rd());
    }
    using Random::rng;
    namespace CardGenerator
    {
        enum CardType
        {
            Special, // 1: east; 2: south; 3: west; 4: north; 5: middle; 6: blank; 7: rich
            T,
            W,
            S,
            none
        };
        struct Card
        {
            int index;
            CardType type;
            Card(int index = 0, CardType type = none)
                : index(index), type(type) {}
        };
        std::vector<Card> standardPile;
        void initStandardPile()
        {
            standardPile.clear();
            for (int i = 1; i <= 9; i++)
                for (int j = 1; j <= 4; j++)
                {
                    standardPile.emplace_back(i, T);
                    standardPile.emplace_back(i, W);
                    standardPile.emplace_back(i, S);
                }
            for (int i = 1; i <= 7; i++)
                for (int j = 1; j <= 4; j++)
                    standardPile.emplace_back(i, Special);
        }
        std::vector<Card> shuffle()
        {
            std::vector<Card> res(standardPile);
            std::shuffle(res.begin(), res.end(), rng);
            return res;
        }
        std::string toString(Card i)
        {
            std::string s = "";
            std::stringstream sout(s);
            sout << "[";
            switch (i.type)
            {
            case Game::CardGenerator::T:
                sout << "O-" << i.index;
                break;
            case Game::CardGenerator::W:
                sout << "W-" << i.index;
                break;
            case Game::CardGenerator::S:
                sout << "I-" << i.index;
                break;
            case Game::CardGenerator::Special:
                switch (i.index)
                {
                case 1:
                    sout << "Est";
                    break;
                case 2:
                    sout << "Sth";
                    break;
                case 3:
                    sout << "Wst";
                    break;
                case 4:
                    sout << "Nth";
                    break;
                case 5:
                    sout << "Mid";
                    break;
                case 6:
                    sout << "Blk";
                    break;
                case 7:
                    sout << "Fah";
                    break;
                }
                break;
            }
            sout << "] ";
            return sout;
        }
    }
}