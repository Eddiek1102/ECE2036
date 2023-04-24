#include "Kill.h"
#include "joystick.h"
#include "uLCD_4DGL.h"

#define SPRITE_HEIGHT 8
#define SPRITE_WIDTH 11

extern uLCD_4DGL uLCD;

#define _ BLACK
#define X LGREY
#define R DGREY
#define Y RED
#define B BLUE
#define W WHITE
#define G GREEN
#define O ORANGE
#define P PURPLE


int Kill_sprite[SPRITE_HEIGHT * SPRITE_WIDTH] = {
    Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,
    Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,
    Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,
    Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,
    Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,
    Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,
    Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,
    Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y
};

void Kill::draw(){
    uLCD.BLIT(xpos, ypos, SPRITE_WIDTH, SPRITE_HEIGHT, Kill_sprite); 
}

void Kill::move(){
    if((ypos > 95) || (ypos < 10)){
        ypos = 80;
    }
    else if((xpos > 105) || (xpos < 10)){
        xpos = 90;
    }
    else{
        if((rand()%101) % 2 == 0){
            increaseX(); 
            increaseY(); 
        }
        else{
            decreaseX(); 
            decreaseY(); 
        }
    }
}

void Kill::erase(){
    if((getXPos() != getOLDXPos() || getYPos() != getOLDYPos())){
        uLCD.filled_rectangle(getOLDXPos(), getOLDYPos(), getOLDXPos() + SPRITE_WIDTH, getOLDYPos() + SPRITE_HEIGHT, BLACK);
    }
}

bool Kill::overlap(int upperLX, int upperLY, int lowerRX, int lowerRY){
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