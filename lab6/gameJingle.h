#ifndef STARTUPJINGLE_H
#define STARTUPJINGLE_H

#include "speaker.h"

extern Speaker mySpeaker;

class GameJingle
{
    public:
    
    //move this to its own implementation file!!
    void playIntro()
    {
        mySpeaker.PlayNote(440.0, 0.5, 0.2);
        mySpeaker.PlayNote(440.0, 0.5, 0.2);
        mySpeaker.PlayNote(494.0, 1.0, 0.4); 
        mySpeaker.PlayNote(440.0, 1.0, 0.4); 
        mySpeaker.PlayNote(587.0, 1.0, 0.4); 
        mySpeaker.PlayNote(523.0, 0.5, 0.2); 
        mySpeaker.PlayNote(440.0, 1.0, 0.4); 
        mySpeaker.PlayNote(440.0, 0.5, 0.2); 
        mySpeaker.PlayNote(494.0, 1.0, 0.4); 
        mySpeaker.PlayNote(440.0, 1.0, 0.4); 
        mySpeaker.PlayNote(659.0, 1.0, 0.4);
        mySpeaker.PlayNote(587.0, 0.5, 0.2); 
        mySpeaker.PlayNote(494.0, 1.0, 0.4); 
        mySpeaker.PlayNote(392.0, 1.0, 0.4);
        mySpeaker.PlayNote(523.0, 1.0, 0.4); 
    }
    
};


#endif
