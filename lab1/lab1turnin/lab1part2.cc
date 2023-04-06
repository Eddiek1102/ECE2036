#include <iostream> 
#include <cmath> 
using namespace std; 

void roots_float(float a, float b, float c){
	float x1{}; 
	float x2{}; 
	float disc1 = (b * b) - (4 * a * c); 
	
	x1 = ((-b + sqrt(disc1))) / (2 * a); 
	x2 = ((-b - sqrt(disc1))) / (2 * a); 

	float percent_error_x1 = 100 * abs(((x1 - (-0.001)) / (-0.001))); 
	float percent_error_x2 = 100 * abs(((x2 - (-3000)) / (-3000))); 

	cout << "x1= " << x1 << " \%error= " << percent_error_x1 << endl; 
	cout << "x2= " << x2 << " \%error= " << percent_error_x2 << endl; 
}

void roots_double(double d, double e, double f){
	double x11{}; 
	double x22{}; 
	double disc2 = (e * e) - (4 * d * f); 

	x11 = ((-e + sqrt(disc2))) / (2 * d); 
	x22 = ((-e - sqrt(disc2))) / (2 * d); 

	double percent_error_x11 = 100 * abs(((x11 - (-0.001)) / (-0.001))); 
	double percent_error_x22 = 100 * abs(((x22 - (-3000)) / (-3000))); 

	cout << "x1= " << x11 << " \%error= " << percent_error_x11 << endl; 
	cout << "x2= " << x22 << " \%error= " << percent_error_x22 << endl; 
}

int main(){
	cout << "Part 2: ROUND-OFF ERROR " << endl; 
	float a{1.0}; 
	float b{3000.001}; 
	float c{3.0}; 

	double d{1.0}; 
	double e{3000.001}; 
	double f{3.0}; 

	cout << "Using the float data type, the roots are: " << endl; 
	roots_float(a, b, c); 
	
	cout << endl; 
	
	cout << "Using the double data type, the roots are: " << endl;
	roots_double(d, e, f); 

return 0; 
}	


