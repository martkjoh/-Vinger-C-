#include "CardDeck.h"

CardDeck::CardDeck(): currentCardIndex{0}
{

    for(int i = 0; i < 4; i++)
    {
        for(int j = 2; j <= 14; j++)
        cards.push_back(Card::Card(Rank(j), Suit(i)));
    }
}

Card CardDeck::drawCard()
{
    currentCardIndex++;
    if (currentCardIndex == cards.size()) shuffle();
    return cards[currentCardIndex];
}

void CardDeck::swap(int a, int b)
{
    Card c = cards[a];
    cards[a] = cards[b];
    cards[b] = c; 
}

void CardDeck::shuffle()
{
    currentCardIndex++;
    for (int i = 0; i < cards.size(); i++) swap(i, randomWithLimits(i));
}

void CardDeck::print()
{
    for(Card card: cards) cout << card.toString() << endl;
}


void CardDeck::printShort()
{
    for(Card card: cards) cout << card.toStringShort() << endl;
}