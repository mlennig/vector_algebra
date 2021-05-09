//
//  vectorAlgebra.h
//  Student ID #21297899
//  Miriam Lennig

#ifndef vectorAlgebra_h
#define vectorAlgebra_h

using namespace std;

class Mvector:public vector<double>{
// Class to represent a linear algebra vector
public:
    static int error;           // Set when vector operation fails
    Mvector(int, double);   // Constructor
    double getElement(int index);
    void setElement(int index, double value);
    void print();
    Mvector operator*(const Mvector &vect);     // Cross product
    Mvector operator+(const Mvector &vect);     // Vector sum
    Mvector operator-(const Mvector &vect);     // Vector difference
    double operator^ (const Mvector &vect) const;   // Dot product
    double norm() const;    // Vector norm
    void scale(double value);   // Scale the vector in place by a scalar
};

int Mvector::error = 0;

class Mmatrix:public vector<Mvector>{
// Class to represent a linear algebra matrix
private:
    Mvector row(int) const;     // Return the indicated row
    Mvector col(int) const;     // Return the indicated column
public:
    static int error;                   // Set when matrix operation fails
    Mmatrix(int, int, double);  // Constructor
    double getElement(int i, int j);
    void setElement(int i, int j, double value);
    void print();
    Mmatrix operator*(const Mmatrix &mat);  // Matrix multiplication
    Mmatrix operator+(const Mmatrix &mat);  // Matrix sum
    Mmatrix operator-(const Mmatrix &mat);  // Matrix difference
    void scale(double value);   // Scale the matrix in place by a scalar
    int nCol() const;             // Return the number of columns
    int nRow() const;           // Return the number of rows
};

int Mmatrix::error = 0;

#endif /* vectorAlgebra_h */
