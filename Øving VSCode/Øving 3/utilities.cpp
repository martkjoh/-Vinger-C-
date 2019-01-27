#include "utilities.h"

void seedRandom()
{
    srand(static_cast<unsigned int>(time(nullptr)));
}

double randomWithLimits()
{
    return rand() % 900 + 100;
}
