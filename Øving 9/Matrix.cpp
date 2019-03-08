#include "Matrix.h"


// Implementasjon av Matrix-klassen
//
// Konstruktører og destruktører

Matrix::Matrix(): nRows{0}, nCols{0}, matrix{nullptr} {}

Matrix::Matrix(int m, int n): nRows{m}, nCols{n}, matrix{new double[m * n]} {}

Matrix::Matrix(int n): Matrix{n, n}
{
    for (int i = 0; i < n; i++) {matrix[index(i, i)] = 1;}
}

Matrix::~Matrix() {delete [] matrix;}


// Medlemsfunksjoner

int Matrix::index(int i, int j) const
{
    if (i > nRows || j > nCols || 0 > i || 0 > j)
    {
        cout << "Invalid index" << endl;
    }
    return i * nCols + j;
}

double Matrix::get(int i, int j) const {return matrix[index(i, j)];}

void Matrix::set(int i, int j, double value) {matrix[index(i, j)] = value;}

int Matrix::getRows() const {return nRows;}

int Matrix::getCols() const {return nCols;}

bool Matrix::isValid() const {return matrix && nRows * nCols;}


// Operatorer

Matrix::Vector Matrix::operator[] (int i)
{
    return Matrix::Vector{nCols, &matrix[i * nCols]};
}

ostream& operator<<(ostream& os, Matrix m)
{
    if (!m.isValid()) 
    {
        os << "Ugyldig matrise" << endl;
        return os;    
    }
    for (int i = 0; i < m.getRows(); i++)
    {
        for (int j = 0; j < m.getCols(); j++)
        {
            cout << setw(5) << m.get(i, j) << ",";
        }
        cout << endl << endl;
    }
    return os;
}


// Implementasjon av Vektor-classen
// Vektor en en sub-klasse av Matrix
//
// Konstrøktører

Matrix::Vector::Vector(int l, double* m): len{l}, mat{m} {}


// Operatører

double Matrix::Vector::operator [] (int i)
{
    if (i > len)
        {
            cout << "Invalid index" << endl;
        }
    return mat[i];
}