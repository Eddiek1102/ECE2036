#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream> 
#include <string> 
#include <cmath> 

using namespace std; 

class Complex{
    private:
        double real; 
        double imag; 
        bool NaN; 
        double theta; 
        double mag; 
    public: 
        void setReal(double real); 
        void setImag(double imag);
        void setNaN(bool NaN);
        void setTheta(); 
        void setMag(); 

        double getReal() const; 
        double getImag() const; 
        bool getNaN() const; 
        double getTheta() const; 
        double getMag() const; 


        Complex(); 
        Complex(double); 
        Complex(double, double); 
        
        void setComplex(double, double); 
        void displayRect(); 
        void displayPolar();

        Complex conjugate(); 

        Complex operator+(const Complex & RHS); 
        Complex operator-(const Complex & RHS);
        Complex operator*(const Complex & RHS); 
        Complex operator/(const Complex & RHS); 

        friend ostream & operator<<(ostream & os, Complex & c); 
};

#endif