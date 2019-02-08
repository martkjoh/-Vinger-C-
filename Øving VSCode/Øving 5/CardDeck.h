#include "Card.h"
#include <vector>

class CardDeck
{
    private:
        vector<Card> cards;
        int CurrentCardIndex;

    public:
        CardDeck()

        Card drawCard();
        void shuffle();
}