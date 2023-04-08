#ifndef MATRIX_H
#define MATRIX_H

#include <iostream> 
#include <iomanip> 
#include "complex.h"
#define MATRIX_FIELD 30

using namespace std; 

class Matrix{
    friend ostream& operator<<(ostream &, const Matrix &); 
    friend Matrix operator*(Complex, Matrix &); 
    friend Matrix operator*(Matrix &, Complex);
    private:
        int rows; 
        int columns; 
        int matrixSize; 
        Complex * complexPtr; 
    public: 
        void setRows(int rows); 
        void setColumns(int columns); 
        void setMatrixSize(int matrixSize); 
        int getRows(); 
        int getColumns(); 
        int getMatrixSize(); 

        Matrix(int, int); 
        Matrix(Matrix &);
        ~Matrix(); 

        Complex & operator()(int, int) const; 

        void printMatrix(); 

        Matrix & transpose(); 

        Matrix operator+(const Matrix&); 
        Matrix operator-(const Matrix&); 
        Matrix operator*(const Matrix&); 
        Matrix operator~(); 
        Matrix operator!(); 

        void operator=(const Matrix&); 

};

#endif