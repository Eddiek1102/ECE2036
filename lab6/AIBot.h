#ifndef AIBOT_H
#define AIBOT_H

//I am okay with keeping these
//as define statements for the colors
#include "ScreenObjects.h"
#define _ BLACK
#define X LGREY
#define R DGREY
#define Y RED

//Maybe these should be c++ constants
//defined in your GobbleBuzz class!!
#define X_DELTA 5
#define Y_DELTA 5

class AIBot : public ScreenObjects
{
    public:
        AIBot(): xpos(50), ypos(50) { copyX();copyY();}
        inline void copyX(){ xOLDpos = xpos;}
        inline void copyY() {yOLDpos = ypos;}
        inline void increaseX() { xpos+=X_DELTA ;}
        inline void increaseY() { ypos+=Y_DELTA;}
        inline void decreaseX() { xpos-=X_DELTA; }
        inline void decreaseY() { ypos-=Y_DELTA; }   
        
        bool overlap(int,int,int,int);
        
        int getXPos() { return xpos; }
        int getYPos() { return ypos; }
        int getOLDXPos() { return xOLDpos; }
        int getOLDYPos() {return yOLDpos; }

        void draw(); 
        void move(); 
        void erase(); 
         
    private:
        int xpos;
        int ypos; 
        int xOLDpos;
        int yOLDpos;   
    
};

#endif