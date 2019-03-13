#include <stdexcept>
#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>

using namespace::std;

class Matrix
{
    private:
        int shape[2];
        double* matrix;

        int index(int i, int j) const;

    public:
        Matrix();
        Matrix(int m, int n);
        explicit Matrix(int n);
        Matrix(const Matrix& rhs);
        ~Matrix();

        void set(int i, int j, double value);
        double get(int i, int j) const;  // Mye raskere enn [m][n]
        int getRows() const;
        int getCols() const;
        string getShape() const;
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

        void operator= (Matrix rhs);
        void operator+= (Matrix rhs);
        Matrix::Vector operator[] (int i);
        
    friend Matrix operator+ (Matrix lhs, const Matrix& rhs);
    friend ostream& operator<< (ostream& os, Matrix m);
};  
