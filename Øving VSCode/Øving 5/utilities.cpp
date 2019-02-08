#include "utilities.h"


void seedRandom()
{
    srand(static_cast<unsigned int>(time(nullptr)));
}

double randomWithLimits(int limit)
{
    return rand() % (limit + 1);
}