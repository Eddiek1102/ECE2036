#include <iostream> 
#include <cmath> 
#include <string>
#include <iomanip> 
using namespace std; 


void roots_float(float a, float b, float c){
    float x1{}; 
    float x2{}; 
    float disc1 = (b * b) - (4 * a * c); 

    x1 = (-b + sqrt(disc1)) / (2 * a); 
    x2 = (-b - sqrt(disc1)) / (2 * a); 

    float percent_error_x1 = 100 * ((-0.001 - x1) / (-0.001));
    float percent_error_x2 = 100 * ((-3000 - x2 ) / (-3000));  

    cout << "x1= " << x1 << " \%error= " << percent_error_x1 << endl; 
    cout << "x2= " << x2 << " \%error= " << percent_error_x2 * -1<< endl; 


}

void roots_double(double d, double e, double f){
    double x11{};
    double x22{}; 
    double disc2 = (e * e) - (4 * d * f); 

    x11 = (-e + sqrt(disc2)) / (2 * d); 
    x22 = (-e - sqrt(disc2)) / (2 * d); 

    double percent_error_x11 = 100 * ((-0.001 - x11) / (-0.001)); 
    double percent_error_x22 = 100 * ((-3000 - x22) / (-3000)); 

    cout << "x1= " << x11 << " \%error= " << double(percent_error_x11) << endl; 
    cout << "x2= " << x22 << " \%error= " << percent_error_x22 * -1<< endl; 
}


int main(){
    cout << "Part 2: ROUND-OFF ERROR " << endl; 
     
    float a{1}; 
    float b{3000.001}; 
    float c{3}; 

    double d{1}; 
    double e{3000.001}; 
    double f{3}; 


    cout << "Using the float data type, the roots are: " << endl; 
    roots_float(a, b, c); 
    
    cout << endl; 

    cout << "Using the double data type, the roots are: " << endl; 
    roots_double(d, e, f); 
  

    return 0; 
}