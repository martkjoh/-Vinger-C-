#include "utilities.h"
#include "blackjack.h"

int main()
{
    seedRandom();

    Blackjack game{};
    
    cout << "The dealers first card is " << game.showCardDealer() << endl;

    // Skal vekk
    cout << "The dealers hand: " << game.dealer.showHand() << endl;

    char answ = 'Y';
    while (true)
    {   
        cout << "Your cards are " << game.showHandPlayer() << endl;
        cout << "Would you like to draw another card? [Y/N] ";
        cin >> answ;
        answ = toupper(answ);

        if (answ == 'Y')
        {
            game.playerDraw();
            if (game.getValuePlayer() > 21) break;
            else continue;
        }
        else if (answ == 'N') break;
        else cout << "Invalid input, try again" << endl;
    }

    cout << "Your cards are " << game.showHandPlayer() << endl;

    string winner = game.getWinner();
    int winningPoints;
    int loosingPoints;

    if (winner == "dealer") 
    {
        winningPoints = game.getValueDealer();
        loosingPoints = game.getValuePlayer();
    }
    else 
    {
        winningPoints = game.getValuePlayer();
        loosingPoints = game.getValueDealer();
    }

    if (winner == "draw")
    {
        cout << "The game is a draw, the player got" << game.getValuePlayer() << " points,"
        << " and the dealer got " << game.getValueDealer() << " points."; 

        if (game.resultOnRealBJ) cout << ", both player and dealer got a real Blackjack." << endl;
        else cout << "." << endl;
    }

    else
    {
        cout << "The winner is the " << winner << ", with " << winningPoints << " points";
        if (game.resultOnRealBJ) cout << ", and a real blackjack,";
        else ", ";

        cout << " versus " << loosingPoints << " points." << endl;   
    }

    return 0;
}
