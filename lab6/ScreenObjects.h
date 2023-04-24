#ifndef SCREENOBJECTS_H
#define SCREENOBJECTS_H

#define X_DELTA 5
#define Y_DELTA 5

class ScreenObjects{
    private: 
        int xpos;
        int ypos; 
        int xOLDpos;
        int yOLDpos;
    public: 
        virtual inline void copyX() = 0; 
        virtual inline void copyY() = 0;
        virtual inline void increaseX() = 0;
        virtual inline void increaseY() = 0; 
        virtual inline void decreaseX() = 0; 
        virtual inline void decreaseY() = 0;  
        
        virtual bool overlap(int,int,int,int) = 0;
        
        virtual int getXPos() = 0;
        virtual int getYPos() = 0;
        virtual int getOLDXPos() = 0;
        virtual int getOLDYPos() = 0;

        virtual void draw() = 0; 
        virtual void move() = 0; 
        virtual void erase() = 0; 
}; 

#endif