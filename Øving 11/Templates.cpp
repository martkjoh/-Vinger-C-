#include "Templates.h"

template <typename T>
T maximum(T a, T b)
{
    if (b > a) {return b;}
    return a;
}

int randBetween(int a, int b)
{
    return (rand() + a) % b;
}

template <typename T>
void shuffle(T& vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        int index = randBetween(i, vec.size());
        auto a = vec[index];
        vec[index] = vec[i];
        vec[i] = a;
    }
}