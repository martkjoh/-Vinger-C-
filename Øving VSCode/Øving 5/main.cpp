#include "Blackjack.h"
#include "utilities.h"

int main()
{

    // Spørsmål
    // Enum class: Forskjellen på å construct Rank{i} og Rank(i)
    seedRandom();

    Blackjack game{};
    
    game.dealerDraw();
    cout << "Your cards are ";
    game.printCards();
    
    char answ;
    while (true)
    {
        if  (game.getPlayerValue() > 21) break;
        cout << "Would you like to draw another card? [Y/N] ";
        cin >> answ;
        answ = toupper(answ);
        if (answ == 'Y') game.drawCard();
        else if (answ == 'N') break;
        else cout << "Invalid input, try again" << endl;
    }

    game.getResult();

    return 0;
}
