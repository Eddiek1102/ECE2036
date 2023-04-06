#include <iostream>  

using namespace std; 

int main(){

cout << "PART 1: OUT OF RANGE ERROR" << endl; 
 
int factorial1{1};
long int factorial2{1}; 
int num{25};
int i{1}; 


cout << endl; 

cout << "Factorial results using int up to 25!" << endl; 
for (i = 1; i <= num; i++){
	factorial1 = factorial1 * i; 
	cout << i << "!= " << factorial1 << endl; 
}
cout <<endl; 

cout << "Factorial results using long int up to 25!" <<endl; 
for (i =1; i <= num; i++){
	factorial2 = factorial2 * i; 
	cout << i << "!= " << factorial2 << endl; 
}

return 0; 

}
