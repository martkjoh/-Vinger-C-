#include "stdexcept"
#include "iostream"
#include "string"
#include "iomanip"

using namespace::std;

class Matrix
{
    private:
        int nRows;
        int nCols;
        double* matrix;

        int index(int i, int j) const;

    public:
        Matrix();
        Matrix(int m, int n);
        explicit Matrix(int n);
        ~Matrix();

        void set(int i, int j, double value);
        double get(int i, int j) const;  // Mye raskere enn [m][n]
        int getRows() const;
        int getCols() const;
        bool isValid() const;

        class Vector
        {       
            public:
                Vector(int l, double* m);

                double operator[] (int j);

            private:
                int len;
                double* mat;
        };

        Matrix::Vector operator[] (int i);

    friend ostream& operator<<(ostream& os, Matrix m);
};  
