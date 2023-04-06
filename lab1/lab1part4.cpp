#include <iostream>
#include <array>
#include <cmath> 
#include <iomanip> 

using namespace std; 


float factorial_float(int n){
    float n_float_factorial{1.0}; 
    for (int i = 1; i <= n; i++){
        n_float_factorial = n_float_factorial * i; 
    }
    return n_float_factorial; 
}

double factorial_double(int n){
    double n_double_factorial{1.0}; 
    for (int i = 1; i <= n; i++){
        n_double_factorial = n_double_factorial * i; 
    }
    return n_double_factorial;
}




int main() {
    long double e = 2.71828182845904523536028747135266249775724709369995; 

    array<float, 100> e_nums_float; 
    float e_float{0.0}; 
    float e_float_backward{0.0}; 
    for (int i = 0; i < 100; i++){
        e_nums_float[i] = 1.0 / factorial_float(i); 
        e_float = e_float + e_nums_float[i];
    }
    cout << "-----" << endl; 
    cout << "Forward Float Approx: " << setprecision(10) << e_float << endl; 
    cout << "Forward Float \%error: " << abs(((e_float - e) / e)) * (100) << endl; 

    for (int i = 99; i >= 0; i--){
        e_float_backward = e_float_backward + e_nums_float[i];
    }
    cout << "Backward Float Approx: " << setprecision(10) << e_float_backward << endl;
    cout << "Backward Float \%error = " << abs(((e_float_backward - e) / e)) * (100)<< endl; 
    cout << "-----" << endl; 


    array<double, 100> e_nums_double; 
    double e_double{0.0}; 
    double e_double_backward{0.0}; 
    for (int i = 0; i < 100; i++){
        e_nums_double[i] = 1.0 / factorial_double(i); 
        e_double = e_double + e_nums_double[i]; 
    }
    cout << "-----" << endl; 
    cout << "Forward Double Approx: " << setprecision(10) << e_double << endl; 
    cout << "Forward Double \%error: " << abs(((e_double - e) / e)) * (100) << endl; 

    for (int i = 99; i >= 0; i--){
        e_double_backward = e_double_backward + e_nums_double[i]; 
    } 
    cout << "Backward Double Approx: " << setprecision(10) << e_double_backward << endl; 
    cout << "Backward Double \%error: " << abs(((e_double_backward - e) / e)) * (100) << endl;
    cout << "-----" << endl;  

    return 0;
}
