#include <iostream> 
using namespace std; 

class Letter{
    private: 

    public: 
        Letter(); 
        void print();  
        char & operator++(); 
        char & operator--(); 
        char currentLetter;
        void print2(char x); 
        void encryptMode(); 
        void decryptMode(); 

}; 