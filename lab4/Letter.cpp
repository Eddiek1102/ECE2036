#include <iostream> 
#include "Letter.h"
#include "uLCD_4DGL.h"

extern uLCD_4DGL uLCD; 


Letter::Letter(){
    this -> currentLetter = 'A'; 
}

void Letter::print(){
    uLCD.text_width(5); 
    uLCD.text_height(5); 
    uLCD.locate(0,0);
    uLCD.color(RED);    
    uLCD.printf("%c", this -> currentLetter); 
}

char & Letter::operator++(){
    if(this -> currentLetter == 'Z'){
        this -> currentLetter = 'A'; 
    }
    else{
        this -> currentLetter++; 
    }
}

char & Letter::operator--(){
    if( this -> currentLetter == 'A'){
        currentLetter = 'Z'; 
    }
    else{
        this -> currentLetter--; 
    }
}

void Letter::print2(char x){
    uLCD.text_width(5); 
    uLCD.text_height(5); 
    uLCD.locate(0,2);
    uLCD.color(BLUE);    
    uLCD.printf("%c", x);
}

void Letter::encryptMode(){
    uLCD.text_width(1); 
    uLCD.text_height(1); 
    uLCD.locate(0, 7);
    uLCD.color(WHITE); 
    uLCD.printf("Encrypt Mode"); 
}

void Letter::decryptMode(){
    uLCD.text_width(1); 
    uLCD.text_height(1); 
    uLCD.locate(0, 7); 
    uLCD.color(WHITE); 
    uLCD.printf("Decrypt Mode");
}