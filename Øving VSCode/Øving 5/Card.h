#pragma once
#include <iostream>
#include <string>

using namespace::std;

enum class Suit
{
    clubs, diamonds, hearts, spades
};

enum class Rank
{
    two = 2, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace
};



class Card
{
    private:
        Suit s;
        Rank r;
        bool valid;
    public:
        Card(Suit suit, Rank rank)
        {
            s = suit;
            r = rank;
        }
};

class CardDeck
{

};