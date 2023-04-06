#include <iostream> 
#include <iomanip> 
#include <cmath> 
using namespace std; 

float float_factorial(float n){ 
    float n_float_factorial{1.0}; 
    for (float i = 1; i <= n; i++){ 
        n_float_factorial = n_float_factorial * i; 
    }
    return n_float_factorial; 
}

double double_factorial(double n){
    double n_double_factorial{1}; 
    for (double i = 1; i <= n; i++){
        n_double_factorial = n_double_factorial * i; 
    }   
    return n_double_factorial; 
}

float calc_float(int n){ 
    float approx_float{1.0}; 
    float previous_float{1.0}; 
    float i{1.0f}; 
    long double e = 2.71828182845904523536028747135266249775724709369995; 
        cout << "#terms = " << i << endl; 
        cout << "approx = " << setprecision(10) << approx_float << endl; 
        cout << "\%error = " << setprecision(10) <<abs(((approx_float - e)) / e) * (100) << endl; 
        cout << "--------" << endl; 

    for (i = 1; i < n; i++){ 
        previous_float = approx_float; 
        approx_float = approx_float + (1.0 / float_factorial(i));
        cout << "#terms = " << i + 1 << endl; 
        cout << "approx = " << setprecision(10) << approx_float << endl;  
        cout << "\%error = " << abs(((approx_float - e)) / e) * (100) << endl; 
        cout << "--------" << endl; 
    }
    return approx_float;
}

double calc_double(int n){
    double approx_double{1}; 
    double previous_double{1}; 
    double i{1}; 
    long double e = 2.71828182845904523536028747135266249775724709369995;
        cout << "#terms = " << i << endl; 
        cout << "approx = " << setprecision(10) << approx_double << endl; 
        cout << "\%error = " << abs(((approx_double - e) / e)) * (100) << endl; 
        cout << "--------" << endl; 
    
    for (i = 1; i < n; i++){
        previous_double = approx_double; 
        approx_double = approx_double + (1 / double_factorial(i)); 
        cout << "#terms = " << i + 1 << endl; 
        cout << "approx = " << setprecision(10) << approx_double << endl; 
        cout << "\%error = " << abs(((approx_double - e) / e)) * (100) << endl; 
        cout << "--------" << endl; 
    }
    return approx_double; 
}

int main(){
    int n; 

    cout << "Input the number of terms in the power series using FLOATS: "; 
    cin >> n; 
    calc_float(n);
    
    cout << "Input the number of terms in the power series using DOUBLES: "; 
    cin >> n; 
    calc_double(n); 

    return 0; 
}
