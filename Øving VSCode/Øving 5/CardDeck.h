#include "Card.h"
#include <vector>
#include "utilities.h"

class CardDeck
{
    private:
        vector<Card> cards;
        int currentCardIndex;

    public:
        CardDeck();

        Card drawCard();
        void swap(int a, int b);
        void shuffle();
        void print();
        void printShort();        
};