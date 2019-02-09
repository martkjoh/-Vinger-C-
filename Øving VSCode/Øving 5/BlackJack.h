#include "CardDeck.h"

// En hånd i blackjack. Value holder poengsummen til hånden. Initsialiseres alltid med 2 kort. 
// tru blackjack holder infomasjon om hånden er en true balckjack (21 + kort med verdi 10 + ess)
class Hand
{
    private:
        
        int value;
        int trueBlackjack;

        void setValue();

        vector<Card> hand;
        
    public:
        Hand(CardDeck& deck);

        void drawCard(CardDeck& deck);
        int getValue();
        bool getTrueBlackjack();
        void printHand();
        Card getCardByIndex(int a);
        int size();
};


// En instanse holder alle verdiene til en runde med blackjack. En dealer og en spiller.
class Blackjack
{
    private:
        CardDeck deck;
        Hand dealer;
        Hand player;
        string result;
        bool dealerTBJ;
        bool playerTBJ;
        int dealerValue;
        int playerValue;

        void setResult();

    public:
        Blackjack();

        int getPlayerValue();
        void dealerDraw();
        void drawCard();
        void printCards();
        void getResult();
};