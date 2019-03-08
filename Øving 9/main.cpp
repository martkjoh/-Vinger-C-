#include "Fib.h"
#include "Matrix.h"

int main()
{
    int a = 4;
    int b = 5;
    Matrix m{a, b};
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            m.set(i, j, i * i * j);
        }
    }

    cout << m;
    return 0;
}   