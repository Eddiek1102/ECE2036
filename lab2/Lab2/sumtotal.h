#include <iostream> 
#include <iomanip> 
#include <cstdlib> 
#include <ctime> 

class SumTotal{
    public: 
        SumTotal(int, int); 
        void playGame(); 
        int getTimeElapsed(); 
        int getNumberCorrect();
    
    private: 
        int timeElapsed; 
        int numberCorrect; 
        int numProblems; 
        int numToTotal; 
};