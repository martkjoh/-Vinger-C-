#include "Fib.h"


void fillInFibNum(int result[], int length)
{
    result[0] = 0;
    if (length == 0) return;
    result[1] = 1;
    if (length == 1) return;
    for (int i = 2; i < length; i++)
    {
        result[i] = result[i - 1] + result[i - 2];
    }
}

void printArray(int arr[], int length)
{
    for (int i = 0; i < length; i++) 
    {
        cout << arr[i] << endl;
    }
}


void createFib()

{
    int length;
    cout << "Hvor mange fibonacci tall skal genreres? ";
    cin >> length;
    int* fib = new int[length];
    fillInFibNum(fib, length);
    printArray(fib, length);
    delete[] fib;

}