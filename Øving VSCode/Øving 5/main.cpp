#include "iostream"
#include "CardStruct.h"


using namespace::std;

int main()
{
    CardStruct cards;
    cards.s = Suit::clubs;
    cards.r = Rank::king;
    cout << toStringShort(cards) << endl;   
    return 0;
}   