#ifndef SERVERFARMERS_H
#define SERVERFARMERS_H

#include "ScreenObjects.h"
#define _ BLACK
#define X LGREY
#define R DGREY
#define Y RED

#define X_DELTA 5
#define Y_DELTA 5


class ServerFarmers : public ScreenObjects{
    private: 
        int xpos; 
        int ypos; 
        int xOLDpos; 
        int yOLDpos; 
    public: 
        ServerFarmers(): xpos(70), ypos(70) { copyX();copyY();}
        inline void copyX(){ xOLDpos = xpos;}
        inline void copyY() {yOLDpos = ypos;}
        inline void increaseX() { xpos+=X_DELTA ;}
        inline void increaseY() { ypos+=Y_DELTA;}
        inline void decreaseX() { xpos-=X_DELTA; }
        inline void decreaseY() { ypos-=Y_DELTA; }
        int getXPos() { return xpos; }
        int getYPos() { return ypos; }
        int getOLDXPos() { return xOLDpos; }
        int getOLDYPos() {return yOLDpos; }

        void setOLDXpos(int x){xOLDpos = x;}
        void setOLDYpos(int y){yOLDpos = y;}

        bool overlap(int,int,int,int);

        void draw(); 
        void move(); 
        void erase(); 
};

#endif

