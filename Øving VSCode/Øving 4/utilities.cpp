#include "utilities.h"

int incrementByValueNumTimes(int startValue, int increment, int numTimes) 
{
    for (int i = 0; i < numTimes; i++) 
    {
        startValue += increment;
    }
    return startValue;
}

void incrementByCalueNumTimesRef(int& startValue, int increment, int numTimes)
{
    for (int i = 0; i < numTimes; i++)
    {
        startValue += increment;
    }
}

void swapNumbers(int& a, int& b)
{
    // Ja, fordi det blir mer kompakt, og man slipper å ærklere flere variabler
    int c = a;
    int a = b;
    int b = c;
}


void randomizeVector(vector<int>& vec, int n)
{
    
}