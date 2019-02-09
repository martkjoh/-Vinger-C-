#include "Card.h"
#include <vector>
#include "utilities.h"

// En kortsokk med 52 kort. Trekker du et kort, inkrementeres indeksen. Trekkes hele bonken, stokkes den
// Når stokken stokkes, blir indeksen satt til 0

class CardDeck
{
    private:
        vector<Card> cards;
        int currentCardIndex;

    public:
        CardDeck();
        CardDeck(bool shuffeled);

        Card drawCard();
        void swap(int a, int b);
        void shuffle();
        void print();
        void printShort();        
};