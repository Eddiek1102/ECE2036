#include <iostream> 
#include <cstdlib> 
#include <iomanip> 
#include <ctime> 
#include "sumtotal.h"

using namespace std; 

SumTotal::SumTotal(int problems, int digits){
    numProblems = problems; 
    numToTotal = digits; 
    timeElapsed = 0; 
    numberCorrect = 0; 
}

void SumTotal::playGame(){
    int startTime; 
    int endTime; 
    int yourAnswer; 
    int actualAnswer; 

    srand(time(0)); 
    
    for(int i = 0; i < numProblems; i++){
        actualAnswer = 0; 
        cout << "Problem " << i + 1 << ": "; 

        for(int j = 0; j < numToTotal; j++){
            int num = rand() % 9 + 1; 
            cout << setw(2) << num << " "; 
            actualAnswer = actualAnswer + num; 
        }
        cout << endl; 
        cout << "Enter sum: "; 
        startTime = time(0); 
        cin >> yourAnswer; 
        endTime = time(0); 

        timeElapsed = timeElapsed + (endTime - startTime); 

        if(yourAnswer == actualAnswer){
            cout << "Correct" << endl; 
            numberCorrect = numberCorrect + 1; 
        }
        else{
            cout << "Incorrect. The correct answer is " << actualAnswer << endl;
        }
    }
}

int SumTotal::getTimeElapsed(){
    return timeElapsed; 
}

int SumTotal::getNumberCorrect(){
    return numberCorrect; 
}