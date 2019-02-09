#include "BlackJack.h"

// Hand

Hand::Hand(CardDeck& deck): value{0}, trueBlackjack{0}
{
    drawCard(deck);
    drawCard(deck);
}

void Hand::setValue()
{
    value = 0;
    int acesCounted = 0;
    bool ace = 0;
    bool ten = 0;
    for (Card card: hand)
    {
        int r = static_cast<int>(card.rank());
        if (r == 14) 
        {
            value += 11;
            acesCounted++;
        }
        else if (r >= 10) 
        {
            value += 10;
            ten = true;
        }
        else value += r;
    }
    ace = acesCounted;
    while (acesCounted && value > 21)
    {
        value -= 10;
        acesCounted--;
    }

    trueBlackjack = (value == 21 && ten && ace);
}

void Hand::drawCard(CardDeck& deck)
 {
     hand.push_back(deck.drawCard());
 }

 int Hand::getValue()
 {
     setValue();
     return value;
 }

 bool Hand::getTrueBlackjack()
 {
     setValue();
     return trueBlackjack;
 }

 void Hand::printHand()
 {
    for(int i = 0; i < hand.size() - 1; i++) 
    {
        cout << hand[i].toString() << ", ";
    }
    cout << hand[hand.size() - 1].toString() << endl;
 }

 Card Hand::getCardByIndex(int a)
 {
     return hand[a];
 }

int Hand::size()
{
    return hand.size();
}


 //Blackjack

Blackjack::Blackjack(): deck{true}, result{"none"}, player{deck}, dealer{deck} {};

int Blackjack::getPlayerValue()
{
    return player.getValue();
}
void Blackjack::dealerDraw()
{
    dealer.getValue();
    while(dealer.getValue() < 17)
    {
        dealer.drawCard(deck);
    }

    cout << "The dealer drew " << dealer.size() << " cards. " 
    << "The first card is " << dealer.getCardByIndex(0).toString() << endl;
}

void Blackjack::drawCard()
{
    player.drawCard(deck);
    cout << "You drew a " << player.getCardByIndex(player.size() - 1).toString() << endl;
}

void Blackjack::setResult()
{    
    playerValue = player.getValue();
    dealerValue = dealer.getValue();
    playerTBJ = player.getTrueBlackjack();
    dealerTBJ = dealer.getTrueBlackjack();
    bool playerOverLimit = playerValue > 21;
    bool dealerOverLimit = dealerValue > 21;

    if (playerTBJ && !dealerTBJ) result = "player";
    else if (dealerOverLimit && !playerOverLimit) result = "player";
    else if (playerValue > dealerValue && !playerOverLimit) result = "player";

    
    else if (!playerTBJ && dealerTBJ) result = "dealer";
    else if (!dealerOverLimit && playerOverLimit) result = "dealer";
    else if (playerValue < dealerValue && !dealerOverLimit) result = "dealer";

    else result = "draw";
}

void Blackjack::printCards()
{
    player.printHand();
}

void Blackjack::getResult()
{
    setResult();

    cout << "Your cards:        "; player.printHand();
    cout << "The dealers cards: "; dealer.printHand();

    if (result == "player")
    {
        cout << "Congratulations, you won with " << playerValue << " points";
        if (playerTBJ) cout << ", and a true blackjack";
        cout << "." << endl;
    }

    else if (result == "dealer")
    {
        cout << "The dealer won, with " << dealerValue << " points";
        if (dealerTBJ) cout << ", and a true blackjack";
        cout << ". Bette luck next time." << endl;
    }
    else if (result == "draw") cout << "The game is a draw." << endl;
    else cout << "An error occured." << endl;
}