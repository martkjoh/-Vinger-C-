#include "test.h"

void testCallByValue() 
{
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    int result = incrementByValueNumTimes(v0, increment, iterations);
    cout << "v0: " << v0
    << " increment: " << increment
    << " iterations: " << iterations
    << " result: " << result << endl;
}

void testByCallByRefrence()
{
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    cout << "v0: " << v0;
    incrementByCalueNumTimesRef(v0, increment, iterations);
    int result = v0;
    cout 
    << " increment: " << increment
    << " iterations: " << iterations
    << " result: " << result << endl;
}

void testVecotrSorting()
{
    vector<int> precentages (0);
}
