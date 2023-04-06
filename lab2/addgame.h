#include <iostream> 
#include <ctime> 

class QuickAdd{
    private:
        int timeElapsed; 
        int numberCorrect; 
        int numProblems; 

    public: 
        QuickAdd(int num); 
        int getTimeElapsed(); 
        void playGame(); 
};