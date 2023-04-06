#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class Match{
    private: 
        int studyTime; 
        int targetMatrix[5][5]; 
    
    public: 
        Match(int sec); 
        void setStudyTime(int sec); 
        int getStudyTime(); 
        void setTargetMatrix(int matrix[5][5]); 
        int* getTargetMatrix(); 
        void playGame(); 
};
