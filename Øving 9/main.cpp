// #include "Fib.h"
#include "Matrix.h"
#include "Dummy.h"

int main()
{

    // createFib();
    // dummyTest();

    int a = 4;
    int b = 5;
    Matrix k{a, b};
    Matrix m{a, b};
    Matrix n{a};
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            m.set(i, j, i * i * j);
        }
    }

    cout << m.getShape() << endl;
    cout << n.getShape() << endl;
    cout << (k.getShape() == m.getShape()) << endl;
    cout << (k.getShape() == n.getShape()) << endl;

    cout << k << endl;
    cout << m << endl;
    cout << n << endl;

    cout << m[7][7] << endl;
    k.set(1, 1, 15.3);
    cout << k << endl;
    cout << m + n << endl;
    m += m + k;
    cout << m << endl;

    return 0;
}   