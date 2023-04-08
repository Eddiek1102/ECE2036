#include <iostream> 
#include <iomanip> 
#include <cmath> 
#include "complex.h"

#define PI 3.14

double Complex::getReal() const{
    return real; 
}
double Complex::getImag() const{
    return imag; 
}
bool Complex::getNaN() const{
    return NaN; 
}
double Complex::getTheta() const{
    return theta; 
}
double Complex::getMag() const{
    return mag; 
}

void Complex::setMag(){
    if(getReal() == 0 && getImag() == 0){
        mag = 0; 
    }
    else if(getReal() == 0){
        mag = getImag(); 
    }
    else if (getImag() == 0){
        mag = getReal(); 
    }
    else{
        mag = sqrt(pow(getReal(), 2) + pow(getImag(), 2));
    }
}

void Complex::setTheta(){
    if(getImag() == 0){
        theta == 0; 
    }
    else{
        theta = atan(getImag() / getReal()); 
    }
}

Complex::Complex(){
    real = 0; 
    imag = 0; 
    mag = 0; 
    theta = 0; 
    NaN = false; 
}

Complex::Complex(double real){
    this -> real = real;
    imag = 0; 
    NaN = false; 
    mag = real; 
    theta = 0; 
}

Complex::Complex(double real, double imag){
    this -> real = real; 
    this -> imag = imag; 
    setMag(); 
    setTheta(); 
}

void Complex::setComplex(double real, double imag){
    this -> real = real; 
    this -> imag = imag;  
    setMag(); 
    setTheta(); 
}

void Complex::displayPolar(){
    if(NaN == true){
        cout << "nan" << endl; 
    }
    else{
        cout << fixed << setprecision(6) << getMag() << " < " << getTheta() << "j" << endl; 
    }
}

void Complex::displayRect(){
    if (NaN == true){
        cout << "nan" << endl; 
    }
    else if(getReal() == 0){
        cout << fixed << setprecision(6) << getImag() << "j" << endl; 
    }
    else if(getImag() == 0){
        cout << fixed << setprecision(6) << getReal() << endl; 
    }
    else{
        cout << fixed << setprecision(6) << getReal() << " + " << getImag() << "j" << endl; 
    }
}

Complex Complex::conjugate(){
    Complex conj; 
    conj = (*this); 
    conj.imag = (-1) * imag; 
    return conj; 
}

Complex Complex::operator+(const Complex & RHS){
    double realSum; 
    double imagSum; 
    realSum = getReal() + RHS.getReal(); 
    imagSum = getImag() + RHS.getImag(); 
    Complex sum(realSum, imagSum);
    sum.NaN = false;  
    return sum; 
}

Complex Complex::operator-(const Complex & RHS){
    double realDifference; 
    double imagDifference; 
    realDifference = getReal() - RHS.getReal(); 
    imagDifference = getImag() - RHS.getImag(); 
    Complex difference(realDifference, imagDifference);
    difference.NaN = false;  
    return difference; 
}

Complex Complex::operator*(const Complex & RHS){
    Complex product; 
    if(RHS.mag == 0 || (*this).mag == 0){
        product.setComplex(0, 0); 
        return product; 
    }
    product.mag = (*this).mag * RHS.mag; 
    product.theta = (*this).theta + RHS.theta; 
    while(product.theta > PI){
        product.theta = product.theta - (2 * PI); 
    }
    while(product.theta < (-1) * PI){
        product.theta = product.theta + (2 * PI); 
    }
    product.real = (product.mag) * cos(product.theta); 
    product.imag = (product.mag) * sin(product.theta); 
    return product; 
}

Complex Complex::operator/(const Complex & RHS){
    Complex quotient; 
    if(RHS.mag == 0){
        quotient.NaN = true; 
        return quotient; 
    }
    quotient.mag = (*this).mag / RHS.mag; 
    quotient.theta = (*this).theta - RHS.theta; 
    while(quotient.theta > PI){
        quotient.theta = quotient.theta - (2 * PI); 
    }
    while(quotient.theta < (-1) * PI){
        quotient.theta = quotient.theta + (2 * PI); 
    }
    quotient.real = (quotient.mag) * cos(quotient.theta); 
    quotient.imag = (quotient.mag) * sin(quotient.theta); 
    return quotient; 
}

ostream & operator<<(ostream & os, Complex & c){
    if(c.getNaN() == true){
        os << "nan"; 
    }
    else if(c.getImag() == 0){
        os << fixed << setprecision(6) << c.getReal(); 
    }
    else if(c.getReal() == 0){
        os << fixed << setprecision(6) << c.getImag() << "j"; 
    }
    else{
        os << fixed << setprecision(6) << c.getReal() << " + " << c.getImag() << "j"; 
    }
    return os; 
}
