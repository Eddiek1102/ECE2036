#include "addgame.h"
using namespace std; 

QuickAdd::QuickAdd(int num){
    numProblems = num; 
    timeElapsed = 0; 
    numberCorrect = 0; 
}   

void QuickAdd::playGame(){
    int counter = time(0); 

    for(int i = 0; i < numProblems; i++){
        int num1 = rand() % 100 + 1; 
        int num2 = rand() % 100 + 1; 
        int result; 

        cout << "What's " << num1 << " + " << num2 << " = "; 
        cin >> result; 

        if(result == num1 + num2){ 
            numberCorrect = numberCorrect + 1; 
        }
    }

    timeElapsed = time(0) - counter; 
    cout << "You got " << numberCorrect << " out of " << numProblems << " correct." << endl;
    cout << "Time elapsed: " << timeElapsed << " seconds." << endl; 
}

int QuickAdd::getTimeElapsed(){
    return timeElapsed; 
}