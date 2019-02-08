#pragma once
#include <iostream>
#include <string>

using namespace::std;

enum class Rank
{
    two = 2, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace
};

enum class Suit
{
    clubs, diamonds, hearts, spades
};

struct CardStruct
{
    Suit s;
    Rank r;
};

class Card
{
    public:
        Card();
        Card(Rank r, Suit s);
        
        Rank rank();
        Suit suit();
        bool isValid();
        bool isPicutre();
        string toString();
        string toStringShort();

    private:
        Rank r;
        Suit s;
        bool valid;

        

        
};


string suitToString(Suit suit);

string rankToString(Rank rank);

string toString(CardStruct card);

string toStringShort(CardStruct card);