#include <iostream>
#include <cstdlib>
#include <array>
#include <ctime>

using namespace std;

/*
class oneTimePad {
    private:
    public:
        char cipherKeys[1000];
        char * ptrEncryptPos; 
        char * ptrDecryptPos; 
        
        oneTimePad(){
            srand(time(0)); 
            for(int i = 0; i < 1000; i++){
                cipherKeys[i] = rand() % 26 + 'A'; 
                cout << "'" << cipherKeys[i] << "',"; 
            }
        }
};
*/

void printArray(char array[], int size){
    srand(time(0)); 
    cout << "Array: {" << endl; 
    for(int i = 0; i < size; i++){
        array[i] = rand() % 26 + 'A'; 
        cout << "'" << array[i]; 
            if(i != 999){
                cout << "',"; 
            }
            else{
                break; 
            }
    }
    cout << "}";
}

int main(){
    int size = 1000; 
    char randomArray[size]; 
    printArray(randomArray, size); 

    return 0; 
}