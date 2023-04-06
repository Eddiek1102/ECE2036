#include <iostream>
#include <cmath> 
#include <String> 
#include <iomanip>

using namespace std; 

int main(){
    int factorial1{1}; 
    long int factorial2{1};
    int num{25}; 
    int i = 1;
   

    cout << endl; 
    
    cout << "Factorial results using int" << endl; 
    for (i = 1; i <= num; i++){
        factorial1 = factorial1 * i; 
        cout << i << "!= " << factorial1 << endl;  
    }

    cout << endl; 

    cout << "Factorial results using long int" << endl; 
    for (i = 1; i <= num; i++){
        factorial2 = factorial2 * i; 
        cout << i << "!= " << factorial2 << endl; 
    }


    return 0;
}