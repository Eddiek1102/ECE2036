#define arraySize 1000 
class OneTimePad{
    private:  
        char randomArray[arraySize]; 

    public: 
        OneTimePad(char []);
        char& operator[](int index);
        char * encryptPtr; 
        char * decryptPtr; 
}; 
