#include "Card.h"


// Card

Card::Card(): valid{true} {}

Card::Card(Rank r, Suit s): r{r}, s{s}, valid{true} {}

Rank Card::rank() 
{
    return r;
}

Suit Card::suit() 
{
    return s;
}

bool Card::isValid() 
{
    return valid;
}

bool Card::isPicutre()
{   
    int a = static_cast<int>(r);
    return bool{a > 10 && a < 14};
}

string Card::toString()
{
    return rankToString(r) + " of " + suitToString(s);
}

string Card::toStringShort()
{
    string rank = to_string(static_cast<int>(r));
    char suit = (suitToString(s))[0];
    return rank + suit;
}


// Funksjoner

string suitToString(Suit suit)
{
    switch(suit)
    {
        case Suit::clubs: return "Clubs";
        case Suit::diamonds: return "Daimonds";
        case Suit::hearts: return "Hearts";
        case Suit::spades: return "Spades";
        default: return "error";
    }
}


string rankToString(Rank rank)
{
    switch(rank)
    {
        case Rank::two: return "Two";
        case Rank::three: return "Three";
        case Rank::four: return "Four";
        case Rank::five: return "Five";
        case Rank::six: return "Six";
        case Rank::seven: return "Seven";
        case Rank::eight: return "Eight";
        case Rank::nine: return "Nine";
        case Rank::ten: return "Ten";           
        case Rank::jack: return "Jack";
        case Rank::queen: return "Queen";
        case Rank::king: return "King";
        case Rank::ace: return "Ace";
        default: return "error";
    }
}


string toString(CardStruct card)
{
    return rankToString(card.r) + " of " + suitToString(card.s);
}

string toStringShort(CardStruct card)
{
    string rank = to_string(static_cast<int>(card.r));
    char suit = (suitToString(card.s))[0];
    return rank + suit;
}