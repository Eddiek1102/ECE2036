//Please note that you must transform this using a 
//polymorphic screen manage like we talked about
//in the lab.  This code is meant to be 'fixed'
//and has some BAD programming choices; however,
//it does  show examples of specific mbed
//functionality that you can use in your final GOOD program. :-)

#include "PlayOutro.h"
#include "mbed.h"
#include "TMP36.h"
#include "uLCD_4DGL.h"
#include "PinDetect.h"
#include "speaker.h"
#include "joystick.h"
#include "gameJingle.h"
#include "AIBot.h"
#include "BatteryChargers.h"
#include "ServerFarmers.h"
#include "CaringCapacitors.h"
#include "RebelResistors.h"
#include "AIPoisonPill.h"
#include "Kill.h"
#include <vector> 

//Put this as C++ constant inside
//your class that contains the AIBot!! 
#define SPRITE_HEIGHT 8
#define SPRITE_WIDTH 11


uLCD_4DGL uLCD(p9, p10, p11); // create a global lcd object
TMP36 myTMP36(p17);

DigitalIn pb1(p21); 
DigitalIn pb2(p22); 
DigitalIn pb3(p23); 

Speaker mySpeaker(p25);

Nav_Switch myNav(p16, p13, p14, p12, p15); //pin order on Sparkfun breakout

int main() {

    //Please have a startup and ending jingle.  I provided
    //a wimpy one note startup jingle
    GameJingle Jingle;
    Jingle.playIntro();
    PlayOutro outro; 

    uLCD.cls();
    srand(time(0));
    
    //if you are not getting random numbers after each reset try debugging with
    //uLCD.printf("Time(0)=%i\n",time(0));
    
    //setup push buttons
    pb1.mode(PullUp);
    pb2.mode(PullUp);
    pb3.mode(PullUp);
    wait(0.3);  //This can make the system more stable as it sets up the pins
    
    //If you don't have this your system will be really slow.
    //This sets the communication rate between the uLCD and the 
    //mbed system.
    uLCD.baudrate(300000);
    wait(0.3);  //Always good to wait as mbed system set itself up!

    
    //let's draw a border around the screen in a festive GREEN
    //NOTE: In your program make sure the AIBot is prevented from
    //going outside the bounds set by this boarder!!  
    uLCD.cls(); //This clears the screen
    uLCD.rectangle(0,0,120,110,RED);
    
    //In this sample program I have one square that randomly
    //changes position after it is captured up by the AI Bot! 
    //In your program you will have various choices for 
    //your AI Bot to capture! 
    int randXPos = (rand()%(118-SPRITE_WIDTH))+2;
    int randYPos = (rand()%(108-SPRITE_HEIGHT))+2;
    
    int points = 0; //this will keep track of the number of times the 
                    // AI Bot captures the square.
    
    //In your game you will have to keep track of points in
    //a more complex scoring scenario; however, this illustrates
    //a way that you can put text anywhere on the screen! In this
    //case it is the number of times the AI Bot captues the square.
    //NOTE: The locate function coordinates are not in units of pixels
    //but in units of the size of the character printed.
    
    uLCD.text_width(1); //You can change the size of your text if you want
    uLCD.text_height(1); //using these member functions for uLCD
    uLCD.locate(1,14); //units are not pixels but character sizes
    uLCD.printf("%i",points); //This will print out the points at bottom of screen
    
    bool GETOUT = false;
    int color = WHITE;

    AIBot mainCharacter; 
    BatteryChargers battery; 
    ServerFarmers farmer; 
    CaringCapacitors capacitor; 
    RebelResistors resistor; 
    AIPoisonPill poison;  
    Kill kill; 

    vector<ScreenObjects *> targetOrPoison;

    targetOrPoison.push_back(&mainCharacter); 
    targetOrPoison.push_back(&battery); 
    targetOrPoison.push_back(&farmer); 
    targetOrPoison.push_back(&capacitor); 
    targetOrPoison.push_back(&resistor); 
    targetOrPoison.push_back(&poison); 
    targetOrPoison.push_back(&kill); 

    
    while(!GETOUT) 
    {
        uLCD.rectangle(0,0,120,110,RED);
        //You can read about this in the lab. Allows quick printing of graphic sprites
       // uLCD.BLIT(buzz1.getXPos(), buzz1.getYPos(), SPRITE_WIDTH, SPRITE_HEIGHT, AIBot_sprite);  

       for(int i = 0; i < targetOrPoison.size(); i++){
           targetOrPoison[i] -> draw(); 
           targetOrPoison[i] -> move(); 
           targetOrPoison[i] -> erase(); 
           targetOrPoison[i] -> copyX(); 
           targetOrPoison[i] -> copyY(); 
       }


    
        if (!pb1){
            points = 0; 
            uLCD.locate(1,14); 
            uLCD.text_width(1); 
            uLCD.text_height(1); 
            uLCD.printf("%i", points); 
        }
        if (!pb2){
            points = 99999999; 
            uLCD.locate(1,14); 
            uLCD.text_width(1); 
            uLCD.text_height(1); 
            uLCD.printf("%i", points); 
        }
                     
        //Here is an example of the AI Bot 'capturing' the square       
        //IDEA: If the AI Bot sprite and the retangle sprite intersect
        //then delete the rectanglar "target" and randomly draw in another 
        //location. 
        if (mainCharacter.overlap(battery.getXPos(), battery.getYPos(), battery.getXPos()+SPRITE_WIDTH, battery.getYPos()+SPRITE_HEIGHT)){
            uLCD.filled_rectangle(battery.getXPos(), battery.getYPos(), battery.getXPos()+SPRITE_WIDTH, battery.getYPos()+SPRITE_HEIGHT, BLACK); 
            uLCD.locate(1,14);
            uLCD.text_width(1);
            uLCD.text_height(1);
            uLCD.printf("%i",++points);
        }
        if (mainCharacter.overlap(farmer.getXPos(), farmer.getYPos(), farmer.getXPos()+SPRITE_WIDTH, farmer.getYPos()+SPRITE_HEIGHT)){
            uLCD.filled_rectangle(farmer.getXPos(), farmer.getYPos(), farmer.getXPos()+SPRITE_WIDTH, farmer.getYPos()+SPRITE_HEIGHT, BLACK); 
            uLCD.locate(1,14); 
            uLCD.text_width(1); 
            uLCD.text_height(1); 
            uLCD.printf("%i",++points); 
        }
        if (mainCharacter.overlap(capacitor.getXPos(), capacitor.getYPos(), capacitor.getXPos()+SPRITE_WIDTH, capacitor.getYPos()+SPRITE_HEIGHT)){
            uLCD.filled_rectangle(capacitor.getXPos(), capacitor.getYPos(), capacitor.getXPos()+SPRITE_WIDTH, capacitor.getYPos()+SPRITE_HEIGHT, BLACK);
            uLCD.locate(1,14); 
            uLCD.text_width(1); 
            uLCD.text_height(1); 
            uLCD.printf("%i",++points); 
        }
        if (mainCharacter.overlap(resistor.getXPos(), resistor.getYPos(), resistor.getXPos()+SPRITE_WIDTH, resistor.getYPos()+SPRITE_HEIGHT)){
            uLCD.filled_rectangle(resistor.getXPos(), resistor.getYPos(), resistor.getXPos()+SPRITE_WIDTH, resistor.getYPos()+SPRITE_HEIGHT, BLACK);
            uLCD.locate(1,14); 
            uLCD.text_width(1); 
            uLCD.text_height(1); 
            uLCD.printf("%i", ++points); 
        }
        if (mainCharacter.overlap(poison.getXPos(), poison.getYPos(), poison.getXPos()+SPRITE_WIDTH, poison.getYPos()+SPRITE_HEIGHT)){
            uLCD.filled_rectangle(poison.getXPos(), poison.getYPos(), poison.getXPos()+SPRITE_WIDTH, poison.getYPos()+SPRITE_HEIGHT, BLACK);
            uLCD.locate(1,14); 
            uLCD.text_width(1); 
            uLCD.text_height(1); 
            uLCD.printf("%i", --points); 
        }
        if (mainCharacter.overlap(poison.getXPos(), poison.getYPos(), poison.getXPos()+SPRITE_WIDTH, poison.getYPos()+SPRITE_HEIGHT)){
            break;
        }


        /*
        if (mainCharacter.overlap(randXPos, randYPos, randXPos+SPRITE_WIDTH, randYPos+SPRITE_HEIGHT))
        //then you need to delete retangle and redraw in another place
        {
             //Note I had the target rectangle and the AI Bot sprite be the same
             //size, but you do not have to do this.
             uLCD.filled_rectangle(randXPos, randYPos,randXPos+SPRITE_WIDTH, randYPos+SPRITE_HEIGHT,BLACK);
             
             //See if you can make a better AI Bot capture sound than this!
             //mySpeaker.PlayNote(450.0,0.1,0.2);
             
             //Here I pick a new location of the target rectangle
             //randXPos = (rand()%(118-SPRITE_WIDTH))+2;
             //randYPos = (rand()%(108-SPRITE_HEIGHT))+2;
             
             //now update the score.  Looks like a cut and paste job...
             //make make it a function!! 
             uLCD.locate(1,14);
             uLCD.text_width(1);
             uLCD.text_height(1);
             uLCD.printf("%i",++points);
        }
        */
        wait(0.1); 

    }
        uLCD.cls();
        uLCD.printf("\n\n\n\n\n   YOU DIED  \n Jeff Killed You!");
        outro.playOutro(); 

}
