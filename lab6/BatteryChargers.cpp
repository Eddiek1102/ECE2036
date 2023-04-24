#include "BatteryChargers.h"
#include "joystick.h"
#include "uLCD_4DGL.h"

#define SPRITE_HEIGHT 8
#define SPRITE_WIDTH 11

extern uLCD_4DGL uLCD;

#define _ BLACK
#define X LGREY
#define R DGREY
#define Y RED

int BatteryChargers_sprite[SPRITE_HEIGHT * SPRITE_WIDTH] = {
    _,_,_,_,_,_,_,_,_,_,_,
    X,X,X,X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,X,X,X,
    X,X,X,X,X,X,X,X,X,X,X,
    _,_,_,_,_,_,_,_,_,_,_
};

void BatteryChargers::draw(){
    uLCD.BLIT(xpos, ypos, SPRITE_WIDTH, SPRITE_HEIGHT, BatteryChargers_sprite); 
}

void BatteryChargers::move(){
    if((ypos == 95) || (ypos == 10)){
        ypos = 25;
    }
    else if((xpos == 105) || (xpos == 10)){
        xpos = 30;
    }
    else{
        if((rand()%101) % 2 == 0){
            increaseX();
            decreaseY();  
        }
        else{
            decreaseX(); 
            increaseY(); 
        }
    }
}

void BatteryChargers::erase(){
    if((getXPos() != getOLDXPos() || getYPos() != getOLDYPos())){
        uLCD.filled_rectangle(getOLDXPos(), getOLDYPos(), getOLDXPos() + SPRITE_WIDTH, getOLDYPos() + SPRITE_HEIGHT, BLACK);
    }
}

bool BatteryChargers::overlap(int upperLX, int upperLY, int lowerRX, int lowerRY){
    int lrxpos = xpos + SPRITE_WIDTH; 
    int lrypos = ypos + SPRITE_HEIGHT; 

    if (((xpos >= upperLX) && (xpos <= lowerRX)) //then x pos satisfied
       && ((ypos >= upperLY) && (ypos <=lowerRY)))
        return true;
    //now check to see if the lower right corner of the turkey is in the rectangle
    else if ( ((lrxpos >= upperLX) && (lrxpos <= lowerRX)) //then x pos satisfied
       && ((lrypos >= upperLY) && (lrypos <= lowerRY)) )
        return true;
    //now check to see if the upper right corner of turkey is in rectangle
    else if ( ((lrxpos >= upperLX) && (lrxpos <= lowerRX)) //then x pos satisfied
       && ((ypos >= upperLY) && (ypos <= lowerRY)) )
        return true;
    //now check to see if the lower left corner of the turkey is in rectangle
    else if ( ((xpos >= upperLX) && (xpos <= lowerRX)) //then x pos satisfied
       && ((lrypos >= upperLY) && (lrypos <= lowerRY)) )
        return true;
    else
        return false; 
}