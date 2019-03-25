#include "Matrix.h"


// Implementasjon av Matrix-klassen
//
// Konstruktører og destruktører

Matrix::Matrix(): shape{0, 0}, matrix{nullptr} {}

Matrix::Matrix(int m, int n): shape{m, n}, matrix{new double[m * n]} {}

Matrix::Matrix(int n): Matrix{n, n}
{
    for (int i = 0; i < n; i++) {matrix[index(i, i)] = 1;}
}

Matrix::Matrix(const Matrix& rhs): Matrix(rhs.getRows(), rhs.getCols())
{
    for(int i = 0; i < shape[0]; i++)
    {
        for (int j = 0; j < shape[1]; j++)
        {
            set(i, j, rhs.get(i, j));
        }
    }
}

Matrix::~Matrix() {delete[] matrix;}


// Medlemsfunksjoner

int Matrix::index(int i, int j) const
{
    if (i > shape[0] || j > shape[1] || 0 > i || 0 > j)
    {
        cout << "Invalid index" << endl;
    }
    return i * shape[1] + j;
}

double Matrix::get(int i, int j) const {return matrix[index(i, j)];}

void Matrix::set(int i, int j, double value) {matrix[index(i, j)] = value;}

int Matrix::getRows() const {return shape[0];}

int Matrix::getCols() const {return shape[1];}

string Matrix::getShape() const
{
    return '(' + to_string(shape[0]) + ',' + to_string(shape[1]) + ')'; 
}

bool Matrix::isValid() const {return matrix && shape[0] * shape[1];}


// Operatorer

void Matrix::operator= (Matrix rhs)
{
    shape[1] = rhs.getCols();
    shape[0] = rhs.getRows();
    swap(matrix, rhs.matrix);
}

void Matrix::operator+= (Matrix rhs)
{
    if (not (getShape() == rhs.getShape()))
        {
            cout << "Can't add shapes " << getShape() << " and " << rhs.getShape() << endl;
        } 
    for(int i = 0; i < shape[0]; i++)
    {
        for (int j = 0; j < shape[1]; j++)
        {
            set(i, j, get(i, j) + rhs.get(i, j));
        }
    }    
}

Matrix::Vector Matrix::operator[] (int i)
{
    return Matrix::Vector{shape[1], &matrix[i * shape[1]]};
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
            printf("%-8.3f", m.get(i, j));
        }
        cout << endl << endl;
    }
    return os;
}

Matrix operator+ (Matrix lhs, const Matrix& rhs)
{
    if (not (lhs.getShape() == rhs.getShape()))
    {
        return Matrix{};
    }
    lhs += rhs;
    return lhs;
}


// Implementasjon av Vektor-classen
// Vektor en en sub-klasse av Matrix
//
// Konstrøktører

Matrix::Vector::Vector(int l, double* m): len{l}, mat{m} {}


// Operatorer

double Matrix::Vector::operator [] (int i)
{
    if (i > len)
        {
            cout << "Invalid index" << endl;
        }
    return mat[i];
}