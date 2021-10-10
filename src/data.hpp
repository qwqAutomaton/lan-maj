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
        extern std::random_device rd;
        extern std::mt19937 rng;
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
        extern std::vector<Card> standardPile;
        std::string toString(Card);
        std::vector<Card> shuffle();
        void initStandardPile();
        namespace Test
        {
            enum CardType
            {
                Speciel,
                T,
                W,
                S,
                none
            };
            class Card
            {
            private:
                int _index;
                CardType _type;

            public:
                Card(int index = 0, CardType type = none)
                    : _index(index), _type(type) {}
                std::string toString();
                inline const int index() const;
                inline const CardType type() const;
                inline void index(int);
                inline void type(CardType);
            };
            class CardPile
            {
            private:
                static std::vector<Card> standardPile;
                std::vector<Card> _pile;
            public:
                CardPile();
                void shuffle();
                
            };
        }
    }
}