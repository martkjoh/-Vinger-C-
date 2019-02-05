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

struct CardStruct
{
    Suit s;
    Rank r;
};

string suitToString(Suit suit);

string rankToString(Rank rank);

string toString(CardStruct card);

string toStringShort(CardStruct card);