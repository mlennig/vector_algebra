//
//  vectorAlgebra.cpp
//  COEN244Assign3
//  Student ID #21297899
//  Created by Miriam Lennig on 2016-02-26.
//  Copyright © 2016 Miriam Lennig. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
#include "vectorAlgebra.h"
using namespace std;

double Mvector::norm() const {
    // Returns the norm of the vector
    return sqrt(*this^*this);
}

void Mvector::scale(double value){
    // Scales the vector in place by value
    unsigned long int length =size();
    for(int i = 0; i < length; i++)
         at(i) *= value;
}

Mvector Mvector::operator+(const Mvector &vect2){
    // Vector addition
    error = 0;
    unsigned long int length1 = size();
    unsigned long int length2 = vect2.size();
    Mvector vectSum ((int)length1, 0.0);
    if (length1 == length2){
        // Vectors are of the same length so we can add them
        for(int i = 0; i < length1; i++)
            vectSum[i] = at(i) + vect2[i];
        return vectSum;
    }
    else {
        cout << "Vectors are different sizes. Cannot perform sum operation." << endl << endl;
        error = 1;  // Signal to the calling function that a vector operation failed
        return vectSum;
    }
}

double Mvector::operator^ (const Mvector &vect2) const{
    // Vector dot product
    error = 0;
    unsigned long int length1 = size();
    unsigned long int length2 = vect2.size();
    double DProd = 0;
    if (length1 == length2){
        // Vectors are of the same length so we can take the dot product
        for(int i = 0; i < length1; i++)
            DProd += at(i) * vect2[i];
            
        return DProd;
    }
    else {
        cout << "Vectors are different sizes. Cannot take dot product." << endl << endl;
        error = 1;  // Signal to the calling function that a vector operation failed
        return 0;
    }
}

Mvector Mvector::operator-(const Mvector &vect2){
    // Difference of vectors
    error = 0;
    unsigned long int length1 = size();
    unsigned long int length2 = vect2.size();
    Mvector vectDiff ((int)length1, 0.0);
    if (length1 == length2){
        // Vectors are of the same length so we can take the difference
        for(int i = 0; i < length1; i++)
            vectDiff[i] = at(i) - vect2[i];
        return vectDiff;
    }
    else {
        cout << "Vectors are different sizes. Cannot perform subtraction operation." << endl << endl;
        error = 1;  // Signal to the calling function that a vector operation failed
        return vectDiff;
    }
}

Mvector Mvector::operator*(const Mvector &vect){
    // Cross product of vectors
    error = 0;
    unsigned long int length1 = size();
    unsigned long int length2 = vect.size();
    Mvector crossProd (3, 0.0);
    if ((length1 == 3)&&(length2 ==3)){
        // Vectors are both of length 3
        crossProd[0] = vect[2]*at(1) - vect[1]*at(2);
        crossProd[1] =-(vect[2]*at(0) - vect[0]*at(2));
        crossProd[2] = vect[1]*at(0) - vect[0]*at(1);
        
        return crossProd;
    }
    
    else{
        cout << "The cross product is only defined in R3." << endl << endl;
        error = 1;  // Signal to the calling function that a vector operation failed
        return crossProd;
    }
}

Mvector::Mvector(int length, double value){
    // Constructor for Mvector
    for(int i = 0; i < length; i++)
        push_back(value);
}

double Mvector::getElement(int index){
    // Returns the element at index
    if (index < size())
        return at(index);
    else{
        cout << "Element index out of range." << endl << endl;
        error = 1;  // Signal to the calling function that a vector operation failed
        return 0;
    }
}

void Mvector::setElement(int index, double value){
    // Sets element at index to value
    error = 0;
    if (index < size())
        at(index) = value;
    else{
        error = 1;  // Signal to the calling function that a vector operation failed
        cout << "Element index out of range." << endl << endl;
    }
}

void Mvector::print(){
    if(!error){
        // Last arithmetic operation was successful
        unsigned long length = size();
        for(int i = 0; i < length; i++)
            cout << at(i)<< "\t\t";
        cout << endl << endl;
    }
    else
        // Last arithmetic operation failed
        cout << "No vector to print." << endl << endl;
}

Mvector Mmatrix::row(int index) const{
    // Returns the row at index
    return at(index);
}

Mvector Mmatrix::col(int iCol) const{
    // Returns the column at iCol
    Mvector column(nRow(), 0.0);
    
    if (iCol < nCol())
        for(int iRow = 0; iRow < nRow(); iRow++)
            column[iRow] = at(iRow)[iCol];
    else
        cout << "Index is out of range." << endl << endl;
    
    return column;
}

Mmatrix::Mmatrix(int nRow, int nCol, double value){
    // Constructor for Mmatrix
    for(int i = 0; i < nRow; i++)
        push_back(Mvector (nCol, value));
}

double Mmatrix::getElement(int i, int j){
    // Returns element at (i, j)
    return at(i)[j];
}

void Mmatrix::setElement(int i, int j, double value){
    // Sets element at (i, j) to value
    if((i < size()) && (j < at(0).size()))
       at(i)[j] = value;
    else
       cout << "One or both indices are out of scope." << endl << endl;
}

void Mmatrix::print(){
    // Prints Mmatrix
    if (!error){
        unsigned long nRow = size();
        for(int iRow = 0; iRow < nRow; iRow++){
            for(int jCol = 0; jCol < at(iRow).size(); jCol++)
                cout << at(iRow)[jCol] << "\t\t";
            cout << endl;
        }
        cout << endl;
    }
    else
        cout << "No matrix to print." << endl << endl;
}

Mmatrix Mmatrix::operator+(const Mmatrix &mat) {
    // Returns sum of two matrices
    Mmatrix matSum (nRow(), nCol(), 0.0);
    if ((nRow() == mat.nRow()) && (nCol() == mat.nCol())){
        // Matrices are of the same dimensions, therefore can be added
        for (int iRow = 0; iRow < nRow(); iRow++){
            for (int jCol = 0; jCol < nCol(); jCol ++)
                matSum[iRow][jCol] = at(iRow)[jCol] + mat[iRow][jCol];
        }
        error = 0;
        return matSum;
    }
    else{
        cout << "Matrices are not the same dimensions. Cannot perform addition." << endl << endl;
        error = 1;
        return matSum;
    }
}


Mmatrix Mmatrix::operator-(const Mmatrix &mat) {
    // Returns difference of two matrices
    unsigned long nRow = size();
    unsigned long nCol = at(0).size();
    unsigned long nRow2 = mat.size();
    unsigned long nCol2 = mat[0].size();
    Mmatrix matDiff ((int)nRow, (int)nCol, 0.0);
    if ((nRow == nRow2) && (nCol == nCol2)){
        // Matrices are of the same dimensions, therefore can be subtracted
        for (int iRow = 0; iRow < nRow; iRow++){
            for (int jCol = 0; jCol < nCol; jCol ++)
                matDiff[iRow][jCol] = at(iRow)[jCol] - mat[iRow][jCol];
        }
        error = 0;
        return matDiff;
    }
    else{
        cout << "Matrices are not the same dimensions. Cannot perform subtraction." << endl << endl;
        error = 1;
        return matDiff;
    }
}

Mmatrix Mmatrix::operator*(const Mmatrix &mat) {
    // Returns product of two matrices
    Mmatrix matProd (nRow(), mat.nCol(), 0.0);
    if (nCol() == mat.nRow()){
        // Inner dimensions are equal
        for(int iRow = 0 ; iRow < matProd.nRow(); iRow++)
            for (int iCol = 0; iCol < matProd.nCol(); iCol++)
                matProd.setElement(iRow, iCol, row(iRow) ^ mat.col(iCol));
        error = 0;
        return matProd;
    }
    else {
        cout << "Matrix dimensions incompatible for matrix multiplication." << endl << endl;
        error = 1;
        return matProd;
    }
}

void Mmatrix::scale(double value){
    // Scales matrix in place by value
    for(int k = 0; k < size(); k++){
        for(int m = 0; m < at(0).size(); m++)
            at(k)[m]*=value;
    }
}
    
int Mmatrix::nCol() const{
    // Returns number of columns in the matrix
    return (unsigned) at(0).size();
}

int Mmatrix::nRow() const{
    // Returns number of rows in the matrix
    return (unsigned) size();
}

int main() {
    
    int nTestCases;
    int maxDim;
    int includeIllCond;
    int emphasizeMult = 1;
    unsigned int seed;
    
    cout << "Welcome to the linear algebra test generater.\n";
    cout << "This program generates random test cases against classes Mvector and Mmatrix.\n\n";
    cout << "How many random test iterations do you want to run? For infinite, enter a negative number: ";
    cin >> nTestCases;
    
    cout << "What is the maximum dimension? ";
    cin >> maxDim;
    
    
    cout << "Do you want to include ill-conditioned cases? (1 = Yes, 0 = No.): ";
    cin >> includeIllCond;
    
    if (!includeIllCond){
        cout << "Emphasize testing of matrix multiplication (= 1) or addition/subraction (= 0): ";
        cin >> emphasizeMult;
    }

    cout << "Please enter a random seed: ";
    cin >> seed;
    srand(seed);
    
    while (nTestCases--){
        // Start testing Mvector
        cout << endl;
        cout << "*************************************" << endl;
        int lenVec1 = rand() % maxDim + 1;                                          // Choose a random length for vec1
        double valVec1 = double(rand() % 1000)/(rand() % 1000 + 1); // Choose a random value to insert into vec1
        
        cout << "Mvector vec1(" <<  lenVec1<< ", " <<  valVec1<< ");" << endl;
        Mvector vec1(lenVec1, valVec1);
        
        cout << "vec1.print();" << endl;
        vec1.print();
        
        int lenVec2;
        if(includeIllCond)
            // Include ill conditioned vectors
            lenVec2 = rand() % maxDim + 1;  // Dimension of vec2 is randomly assigned
        else
            // Force vectors to be compatible
            lenVec2 = lenVec1;
        
        double valVec2 = double(rand() % 1000)/(rand() % 100 + 1);  // Random data value for vec2
        
        cout << "Mvector vec2(" <<  lenVec2<< ", " <<  valVec2<< ");" << endl;
        Mvector vec2(lenVec2, valVec2);
        
        cout << "vec2.print();" << endl;
        vec2.print();
  
        unsigned long count = 1.6 * vec1.size();    // Select a random number of elements of vec1 to change
        while (count--){
            int i = rand() % vec1.size();   // Select a random index into vec1
            double x = double(rand() % 1000) / 10.;
            
            cout << "vec1.setElement(" << i << ", " << x << ");" << endl;
            vec1.setElement(i, x);
            cout << "vec1.print();"  << endl;
            vec1.print();
        }
        
        count = 1.6 * vec2.size();   // Select a random number of elements of vec2 to change
        while (count--){
            int i = rand() % vec2.size();   // Select a random index into vec1
            double x = double(rand() % 1000) / 10.;
            
            cout << "vec2.setElement(" << i << ", " << x << ");" << endl;
            vec2.setElement(i, x);
            cout << "vec2.print();"  << endl;
            vec2.print();
        }
        
        cout << "Mvector vec3 = vec1 + vec2;" << endl;
        Mvector vec3 = vec1 + vec2;
        
        cout << "vec3.print();" << endl;
        vec3.print();
        
        cout << "Mvector vec3 = vec1 - vec2;" << endl;
        vec3 = vec1 - vec2;
        
        cout << "vec3.print();" << endl;
        vec3.print();
        
        if (includeIllCond || (lenVec1 == 3 && lenVec2 == 3)){
            // Compute cross product
            cout << "Mvector vec3 = vec1 * vec2;" << endl;
            vec3 = vec1 * vec2;
        }

        cout << "vec3.print();" << endl;
        vec3.print();
        
        cout << "double dotproduct = vec1 ^ vec2;" << endl;
        double dotproduct = vec1 ^ vec2;
        if (!vec3.error) {
            // No error: Dot product exists, so print it
            cout << "cout << dotproduct << endl;" << endl;
            cout << dotproduct  << endl;
            cout << endl;
        }
        
        double scalar = double(rand() % 1000)/(rand() % 1000 + 1);  // Select random data value for scalar quantity
        
        vec1.error = 0;  // Clear error flag in case last Mvector operation failed
        cout << "vec1.print();" << endl;
        vec1.print();
        
        cout << "vec1.scale(" << scalar << " );" << endl;
        vec1.scale(scalar);
        
        cout << "vec1.print();" << endl;
        vec1.print();
        
        // Test Mmatrix ..........................
        
        // Select random dimensions for the matrix
        int nRow = rand() % maxDim + 1;
        int nCol = rand() % maxDim + 1;
        
        double x = double(rand()  % 1000)/10.;  // Select random data value
        
        cout << "Mmatrix mat1(" << nRow << ", " << nCol << ", " <<  x << ");" << endl;
        Mmatrix mat1(nRow, nCol, x);
        cout << "mat1.print();" << endl;
        mat1.print();
        
        if(includeIllCond){
            // Ill conditioned matrices are allowed, so we can choose random dimensions for mat2
            nRow = rand() % maxDim + 1;
            nCol = rand() % maxDim + 1;
        }
        else{
            if(emphasizeMult){
                // Matrices must be compatible for multiplication mat1 * mat2
                nRow = mat1.nCol(); // mat2 must have number of rows equal to number of columns of mat1
                nCol = rand() % maxDim +1;  // Select a random number of columns for mat2
            }
            else {
                // Matrices must be compatible for addition mat1 + mat2
                // Both dimensions must be equal
                nCol = mat1.nCol();
                nRow = mat1.nRow();
            }
        }
        
        x = double(rand()  % 1000)/10.; // Select a random data value
        
        cout << "Mmatrix mat2(" << nRow << ", " << nCol<< ", " <<  x << ");" << endl;
        Mmatrix mat2(nRow, nCol, x);
        cout << "mat2.print();" << endl;
        mat2.print();
        
        // Modify a random number of elements of mat1
        count = 1.6 * mat1.nRow() * mat1.nCol();    // Select a random number of elements to change
        while (count--){
            int iRow = rand() % mat1.nRow();
            int iCol = rand() % mat1.nCol();
            x = double(rand() % 1000)/10.;
            
            cout << "mat1.setElement(" << iRow << ", " <<  iCol << ",  " << x << ");" << endl;
            mat1.setElement(iRow, iCol, x);
            cout << "mat1.print();" << endl;
            mat1.print();
        }
        
        // Modify a random number of elements of mat2
        count = 1.6 * mat2.nRow() * mat2.nCol();    // Select a random number of elements to change
        while (count--){
            int iRow = rand() % mat2.nRow();
            int iCol = rand() % mat2.nCol();
            x = double(rand() % 1000)/10.;
            
            cout << "mat2.setElement(" << iRow << ", " <<  iCol << ",  " << x << ");" << endl;
            mat2.setElement(iRow, iCol, x);
            cout << "mat2.print();" << endl;
            mat2.print();
        }
        
        if(includeIllCond || ((mat1[0].size() == mat2[0].size()) && (mat2.size() == mat1.size()))){
            // Unless ill conditioned matrices are allowed, the dimensions must match
            mat1.error = 0;
            cout << "mat1.print();\n";
            mat1.print();
            
            cout << "Mmatrix mat3 = mat1 + mat2;" << endl;
            Mmatrix mat3 = mat1 + mat2;
            cout << "mat3.print();" << endl;
            mat3.print();
            
            cout << "Mmatrix mat3 = mat1 - mat2;" << endl;
            mat3 = mat1 - mat2;
            cout << "mat3.print();" << endl;
            mat3.print();
        }
        
        if(includeIllCond || (mat1.nCol() == mat2.nRow())){
            // Unless ill conditioned matrices are allowed, the inner dimensions must match
            mat1.error = 0;
            cout << "mat1.print();\n";
            mat1.print();
            cout << "Mmatrix mat3 = mat1 * mat2;" << endl;
            Mmatrix mat3 = mat1 * mat2;
            cout << "mat3.print();" << endl;
            mat3.print();
        }
        
        x = double(rand() % 1000)/10.;
        mat1.error = 0;
        
        cout << "mat1.scale(" << x << "); " << endl;
        mat1.scale(x);
        cout << "mat1.print(); " << endl;
        mat1.print();
    }
    
}
