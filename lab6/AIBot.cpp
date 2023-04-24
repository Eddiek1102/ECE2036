#include "AIBot.h"
#include "joystick.h"
#include "uLCD_4DGL.h"


#define SPRITE_HEIGHT 8
#define SPRITE_WIDTH 11

extern uLCD_4DGL uLCD;
extern Nav_Switch myNav; 

#define _ BLACK
#define X LGREY
#define R DGREY
#define Y RED

int AIBot_sprite[SPRITE_HEIGHT * SPRITE_WIDTH] = {
    _,_,_,_,X,X,X,R,R,_,_,
    _,X,X,X,X,X,X,X,R,X,_,
    X,X,R,X,X,Y,Y,X,X,X,X,
    X,X,X,R,X,Y,Y,X,X,X,_,
    X,R,X,X,X,X,X,X,R,R,R,
    _,_,_,R,X,_,R,R,_,_,_,
    _,_,R,R,_,_,_,R,R,_,_,
    R,R,_,_,_,R,_,_,_,R,R
};

void AIBot::draw(){
    uLCD.BLIT(xpos, ypos, SPRITE_WIDTH, SPRITE_HEIGHT, AIBot_sprite);
}

void AIBot::move(){
    if(myNav.up()){
        if(ypos == 95){
            ypos = yOLDpos - 5; 
        }
        else if(ypos == 10){
            ypos = yOLDpos + 5; 
        }
        else{
            increaseY();
        }
    }
    if(myNav.down()){
        if(ypos == 95){
            ypos = yOLDpos - 5; 
        }
        else if(ypos == 10){
            ypos = yOLDpos + 5; 
        }
        else{
            decreaseY(); 
        }
    }
    if(myNav.left()){
        if(xpos == 105){
            xpos = xOLDpos - 5; 
        } 
        else if(xpos == 10){
            xpos = xOLDpos + 5; 
        }
        else{
            increaseX(); 
        }
    }
    if(myNav.right()){
        if(xpos == 105){
            xpos = xOLDpos - 5; 
        }
        else if(xpos == 10){
            xpos = xOLDpos + 5; 
        }
        else{
            decreaseX(); 
    }
}
}

void AIBot::erase(){
    if((getXPos() != getOLDXPos() || getYPos() != getOLDYPos())){
        uLCD.filled_rectangle(getOLDXPos(), getOLDYPos(), getOLDXPos() + SPRITE_WIDTH, getOLDYPos() + SPRITE_HEIGHT, BLACK);
    }
}

bool AIBot::overlap(int upperLX, int upperLY, int lowerRX, int lowerRY)
{
    
    int lrxpos = xpos+SPRITE_WIDTH;
    int lrypos = ypos+SPRITE_HEIGHT;

    //first check to see if in the upper left corner of turkey is in rectangle
    
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