#include <iostream> 
#include "matrix.h"

using namespace std; 

void Matrix::setRows(int rows){
    this -> rows = rows; 
}

void Matrix::setColumns(int columns){
    this -> columns = columns; 
}
void Matrix::setMatrixSize(int matrixSize){
    this -> matrixSize = matrixSize; 
}

int Matrix::getRows(){
    return rows; 
}

int Matrix::getColumns(){
    return columns; 
}

int Matrix::getMatrixSize(){
    return matrixSize; 
}

Matrix::Matrix(int rows, int columns){
    this -> rows = rows; 
    this -> columns = columns; 
    matrixSize = rows * columns; 
    complexPtr = nullptr; 
    complexPtr = new Complex[rows * columns]; 
}

Matrix::Matrix(Matrix & copyMatrix){
    rows = copyMatrix.rows; 
    columns = copyMatrix.columns; 
    matrixSize = copyMatrix.matrixSize; 
    complexPtr = nullptr; 
    if(matrixSize > 0){
        complexPtr = new Complex[matrixSize]; 
        for(int i = 0; i < matrixSize; i++){
            complexPtr[i] = copyMatrix.complexPtr[i]; 
        }
    }
}

Matrix::~Matrix(){
    delete[] complexPtr; 
}

void Matrix::printMatrix(){
    string str; 
    if(matrixSize == 0){
        cout << "Empty Matrix!" << endl; 
    }
    else{
        for(int i = 1; i <= rows; i++){
            for(int j = 1; j <= columns; j++){
                if((*this)(i, j).getReal() == 0 && (*this)(i, j).getImag() != 0){
                    str = to_string((*this)(i, j).getImag()) + "j"; 
                }
                else if((*this)(i, j).getImag() == 0 ){
                    str = to_string((*this)(i, j).getReal());
                }
                else{
                    str = to_string((*this)(i, j).getReal()) + " + "  + to_string((*this)(i, j).getImag()) + "j"; 
                }
                cout << left << setw(MATRIX_FIELD) << str; 
                if(j == (*this).columns){
                    cout << endl; 
                }
            }
        }
    }
}

Complex & Matrix::operator()(int r, int c) const{
    return complexPtr[c + (r - 1) * columns - 1];
}

Matrix & Matrix::transpose(){
    Matrix matrix(columns, rows); 
    for(int i = 1; i <= rows; i++){
        for(int j = 1; j <= columns; j++){
            matrix(j, i) = (*this)(i, j); 
        }
    }
    for(int i = 1; i <= columns; i++){
        for(int j = 1; j <= rows; j++){
            (*this)(i, j) = matrix(i, j); 
        }
    }
    return (*this); 
}

Matrix Matrix::operator+(const Matrix & RHS){
    if(rows != RHS.rows || columns != RHS.columns){
        Matrix matrix(0, 0); 
        return matrix;
    }
    else{
        Matrix matrix(rows, columns); 
        for(int i = 0; i < matrixSize; i++){
            matrix.complexPtr[i] = complexPtr[i] + RHS.complexPtr[i]; 
        }
        return matrix; 
    }
}

Matrix Matrix::operator-(const Matrix & RHS){
    if(rows != RHS.rows || columns != RHS.columns){
        Matrix matrix(0, 0); 
        return matrix; 
    }
    else{
        Matrix matrix(rows, columns); 
        for(int i = 0; i < matrixSize; i++){
            matrix.complexPtr[i] = complexPtr[i] - RHS.complexPtr[i];
        }
        return matrix; 
    }
}

Matrix Matrix::operator*(const Matrix & RHS){
    if(columns != RHS.rows){
        Matrix matrix(0, 0); 
        return matrix; 
    }
    else{
        Matrix matrix(rows, RHS.columns); 
        for(int i = 1; i <= rows; i++){
            for(int j = 1; j <= RHS.columns; j++){
                for(int k = 1; k <= columns; k++){
                    matrix(i, j) = matrix(i, j) + (*this)(i, k) * RHS(k, j); 
                }
            }
        }
        return matrix; 
    }
}

Matrix operator*(Complex c, Matrix & m){
    Matrix matrix(m.rows, m.columns); 
    for(int i = 1; i < m.matrixSize; i++){
        matrix.complexPtr[i] = m.complexPtr[i] * c; 
    }
    return matrix; 
}

Matrix operator*(Matrix & m, Complex c){
    Matrix matrix(m.rows, m.columns); 
    for(int i = 1; i < m.matrixSize; i++){
        matrix.complexPtr[i] = m.complexPtr[i] * c; 
    }
    return matrix; 
}

Matrix Matrix::operator~(){
    Matrix matrix(columns, rows); 
    for(int i = 1; i <= rows; i++){
        for(int j = 1; j <= columns; j++){
            matrix(j, i) = (*this)(i, j); 
        }
    }
    return matrix; 
}

Matrix Matrix::operator!(){
    Matrix matrix(columns, rows); 
    for(int i = 1; i <= rows; i++){
        for(int j = 1; j <= columns; j++){
            matrix(j, i) = (*this)(i, j).conjugate(); 
        }
    }
    return matrix; 
}

void Matrix::operator=(const Matrix & m){
    delete[] complexPtr; 
    if (m.complexPtr == nullptr){
        complexPtr = nullptr; 
    }
    else{
        rows = m.rows; 
        columns = m.columns; 
        matrixSize = m.matrixSize; 
        complexPtr = new Complex[matrixSize]; 
        for(int i = 0; i < matrixSize; i++){
            (*this).complexPtr[i].setComplex(m.complexPtr[i].getReal(), m.complexPtr[i].getImag()); 
        }
    }
}

ostream & operator<<(ostream & os, const Matrix & m){
    string str; 
    if(m.complexPtr == nullptr){
        os << "Matrix Mismatch Error!" << endl; 
        os << "This matrix has zero elements" << endl; 
    }
    else{
        for(int i = 1; i <= m.rows; i++){
            for(int j = 1; j <= m.columns; j++){
                if(m(i, j).getReal() == 0 && m(i, j).getImag() != 0){
                    str = to_string(m(i, j).getImag()) + "j"; 
                }
                else if(m(i, j).getImag() == 0){
                    str = to_string(m(i, j).getReal()); 
                }
                else{
                    str = to_string(m(i, j).getReal()) + " + " + to_string(m(i, j).getImag()) + "j";
                }
                os << left << setw(MATRIX_FIELD) << str; 
                if(j == m.columns){
                    os << endl; 
                }
            }
        }
    }
    return os; 
}