#include "mbed.h"
#include "uLCD_4DGL.h"
#include "PinDetect.h"
#include "Letter.h"
#include "OneTimePad.h"
#include <iostream> 

char randomArray[1000] = {
    'E','Y','O','M','E','B','S','D','X','P','A','P','X','Y','W','L','S','I','Y','N','U','J','M','V','S','Y','R','L','Q','P','T','Z','T',
    'K','A','E','U','K','G','F','J','Y','U','S','V','G','P','F','Z','O','V','A','U','C','D','U','Y','T','C','O','L','S','Q','M','E','H',
    'P','L','L','I','X','R','B','K','M','I','S','V','J','T','N','O','E','H','V','E','E','C','J','P','L','V','H','H','D','Y','X','B','E',
    'S','L','F','I','C','I','K','R','A','V','V','W','O','Q','A','V','J','C','S','S','Y','Y','U','C','P','W','O','D','C','J','N','E','V',
    'R','Z','B','Z','U','X','R','E','Z','A','N','Q','L','I','E','S','V','O','X','O','G','Z','C','Z','E','N','I','U','Z','T','B','P','C',
    'I','G','Z','G','J','G','I','M','M','G','V','N','U','W','R','J','C','J','P','F','H','K','C','R','Y','C','D','G','V','C','G','H','M',
    'H','R','H','Z','V','U','V','X','P','S','B','S','O','E','P','U','C','S','W','C','G','V','L','V','G','C','W','B','M','E','O','Z','M',
    'W','B','L','C','V','Z','H','Z','F','G','A','D','C','N','Q','N','Q','C','B','K','C','E','P','M','O','B','F','C','H','V','J','R','N',
    'X','W','Z','L','M','I','O','P','Q','Q','Z','D','K','B','F','W','P','M','Q','V','I','S','S','Y','G','W','A','S','D','M','E','Q','F',
    'Q','Z','M','Q','H','F','G','N','K','E','E','P','P','E','V','Z','R','F','L','A','X','L','Y','A','Q','X','D','B','N','A','W','C','U',
    'Q','Q','B','A','I','Q','K','X','K','S','A','P','K','U','Z','E','C','Q','B','I','X','H','U','S','T','N','Z','U','O','Q','H','H','G',
    'M','R','N','P','M','I','V','F','C','C','H','D','A','O','P','W','X','E','Q','R','N','C','L','S','I','O','L','J','T','O','T','E','M',
    'U','O','X','B','B','K','K','H','B','Q','P','W','L','S','M','R','F','V','X','W','U','V','P','F','D','M','D','K','S','J','Y','B','C',
    'Z','O','F','K','G','D','A','S','S','B','A','G','U','T','H','Y','X','J','F','M','E','M','D','S','H','W','U','L','V','T','V','V','G',
    'N','O','E','F','K','A','I','E','S','X','E','D','Q','G','Y','U','I','P','O','U','J','V','K','U','J','G','A','O','J','V','B','D','A',
    'V','B','N','V','N','J','O','K','S','K','Q','Q','A','Q','L','M','A','S','X','T','S','E','Z','P','L','U','K','U','W','U','J','X','K',
    'A','Q','P','Q','U','X','T','O','E','Y','G','M','X','I','X','O','T','B','G','H','K','T','P','C','R','N','H','T','Y','X','V','S','K',
    'J','O','S','R','J','M','C','L','D','Y','W','F','Q','M','S','S','M','W','J','P','I','J','R','C','H','U','R','Z','N','O','Y','V','J',
    'S','Y','V','X','T','H','J','F','I','I','E','Y','X','R','A','R','A','Q','R','O','D','Z','Y','M','J','P','O','M','Y','P','S','W','K',
    'V','H','X','U','M','Z','D','A','Z','I','Y','U','B','T','S','I','P','X','X','X','X','R','M','T','M','C','S','X','A','P','L','F','Q',
    'D','P','Y','L','T','K','N','W','V','C','A','T','K','B','H','S','O','V','R','S','O','X','A','U','Q','L','U','N','J','M','B','Q','E',
    'J','H','P','M','U','I','W','H','C','M','D','H','S','D','J','W','U','Y','T','S','U','Y','U','O','X','K','L','X','N','Y','P','D','R',
    'A','U','H','I','L','K','Y','S','W','Z','T','V','E','A','W','M','Z','S','T','R','M','T','Y','H','Z','E','J','Q','H','U','E','W','L',
    'I','Y','Y','W','O','A','F','Y','B','J','Y','L','D','A','H','J','I','W','O','Z','C','P','J','V','H','K','Q','S','M','C','X','G','S',
    'Q','K','N','S','D','E','G','D','D','D','O','R','F','N','P','B','Z','F','X','E','G','G','Z','Q','U','B','T','A','S','W','G','B','M',
    'O','D','F','O','Z','I','O','C','P','R','N','E','N','D','E','Z','G','U','E','R','S','R','K','Y','K','G','K','E','I','R','R','R','K',
    'X','V','Y','D','Y','W','E','Q','N','C','M','D','J','X','V','B','G','F','R','E','L','Y','H','F','G','G','Y','F','E','A','J','S','M',
    'P','E','E','Y','K','U','J','F','K','F','B','N','V','B','W','B','P','B','O','A','P','G','F','C','W','P','B','N','H','C','U','B','U',
    'Y','Y','M','N','X','L','R','O','H','J','M','J','A','Z','P','F','P','Q','M','C','H','E','K','O','Y','K','O','I','B','S','Z','F','W',
    'X','I','Z','H','W','V','J','O','R','L','W','G','W','G','T','M','Z','B','H','U','C','I','X','W','K','W','K','V','R','H','X','H','N',
    'U','A','X','W','D','K','M','J','C','V'
    }; 

uLCD_4DGL uLCD(p9, p10, p11); 

PinDetect pb1(p21); 
PinDetect pb2(p22); 
PinDetect pb3(p23); 
PinDetect pb4(p24); 

enum ResponseType {SCROLL_UP, SCROLL_DOWN, ENCRYPT, DECRYPT, NOT_PRESSED};
enum StateType {SCROLLUP_STATE, SCROLLDOWN_STATE, WAIT, ENCRYPT_STATE, DECRYPT_STATE};

ResponseType input = NOT_PRESSED; 
StateType state = WAIT; 

void pb1_hit_callback(void){
    input = SCROLL_UP; 
}

void pb2_hit_callback(void){
    input = SCROLL_DOWN; 
}

void pb3_hit_callback(void){
    input = ENCRYPT; 
}

void pb4_hit_callback(void){
    input = DECRYPT; 
}

int main(){

    pb1.mode(PullUp); 
    pb2.mode(PullUp); 
    pb3.mode(PullUp); 
    pb4.mode(PullUp); 

    wait(.01); 

    pb1.attach_deasserted(&pb1_hit_callback); 
    pb2.attach_deasserted(&pb2_hit_callback); 
    pb3.attach_deasserted(&pb3_hit_callback); 
    pb4.attach_deasserted(&pb4_hit_callback);

    pb1.setSampleFrequency(); 
    pb2.setSampleFrequency(); 
    pb3.setSampleFrequency(); 
    pb4.setSampleFrequency(); 

    OneTimePad myArray(randomArray); 
    Letter letter; 

    int count = 0; 

    while(true){
        switch(state){
            case(WAIT): 
            letter.print(); 
            if(input == SCROLL_UP){
                state = SCROLLUP_STATE; 
                input = NOT_PRESSED; 
                break; 
            }
            else if(input == SCROLL_DOWN){
                state = SCROLLDOWN_STATE; 
                input = NOT_PRESSED; 
                break; 
            }
            else if(input == ENCRYPT){
                state = ENCRYPT_STATE; 
                input = NOT_PRESSED; 
                break; 
            }
            else if(input == DECRYPT){
                state = DECRYPT_STATE; 
                input = NOT_PRESSED; 
                break; 
            }
            else{
                state = WAIT; 
                input = NOT_PRESSED; 
                break;
            }
            break; 

            case(SCROLLUP_STATE): 
                ++letter;
                ++myArray.encryptPtr; 
                count++; 
                state = WAIT; 
                break; 
            
            case(SCROLLDOWN_STATE): 
                --letter; 
                --myArray.encryptPtr; 
                state = WAIT; 
                break;  
            
            case(ENCRYPT_STATE): 
                myArray.encryptPtr = &(myArray[(letter.currentLetter - 65 + char(count) - 65) % 26 + 'A']);
                letter.print2(*myArray.encryptPtr); 
                char temp = letter.currentLetter; 
                letter.encryptMode(); 
                state = WAIT;
                break;

            case(DECRYPT_STATE): 
                letter.currentLetter = ((letter.currentLetter - 65 - (*(myArray.decryptPtr++) - 65)) + 26 + 'A');
                myArray.decryptPtr = &temp;
                letter.print2(char(*myArray.decryptPtr)); 
                letter.decryptMode();
                state = WAIT; 
                continue;       
        }   
    }
}