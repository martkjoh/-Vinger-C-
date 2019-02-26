#pragma once
#include <iostream>
#include <string>

using namespace::std;

// Ranken til et spillkort

enum class Rank
{
    two = 2, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace
};  


// Typen til et spillkort

enum class Suit
{
    clubs, diamonds, hearts, spades
};


// Brukes ikke, for en oppgave

struct CardStruct
{
    Suit s;
    Rank r;
};


// Et spillkortmed rank og suit. Constructer uten argumenter returnerert et invalid kort

class Card
{
    private:
        Rank r;
        Suit s;
        bool valid;
    
    public:
        Card();
        Card(Rank r, Suit s);
        
        Rank rank();
        Suit suit();
        bool isValid();
        bool isPicutre();
        string toString();
        string toStringShort();
};


string suitToString(Suit suit);

string rankToString(Rank rank);

string toString(CardStruct card);

string toStringShort(CardStruct card);