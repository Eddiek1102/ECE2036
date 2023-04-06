#include <iostream>
#include <ctime>
#include <cstdlib>
#include "match.h"
using namespace std; 

Match::Match(int sec) {
    studyTime = sec; 
    srand(time(0)); 

    int nums[25]; 
    for(int i = 0; i < 25; i++){
        nums[i] = 0; 
    }

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            int value; 
            do{
                value = rand() % 25 + 1; 
            }while(nums[value - 1] == 1);
            
            targetMatrix[i][j] = value; 
            nums[value - 1] = 1; 
        }
    }
}

void Match::setStudyTime(int sec){
    studyTime = sec; 
}

int Match::getStudyTime(){
    return studyTime; 
}

void Match::setTargetMatrix(int matrix[5][5]){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            targetMatrix[i][j] = matrix[i][j];
        }
    }
}

int* Match::getTargetMatrix(){
    int* matrix = &targetMatrix[0][0]; 
    return matrix; 
}

void Match::playGame(){
    cout << "Memorize numbers inside this matrix: " << endl; 
    cout << "-----------------------------------" << endl; 

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cout << targetMatrix[i][j] << "\t"; 
        }
        cout << endl; 
    }
    cout << "-----------------------------------" << endl; 

    for(int i = getStudyTime(); i >= 0; i--){
        cout << "\rTime Remaining: " << i << " "; 
        int counter = time(0); 

        while(time(0) - counter < 1){
        }
    }

    cout << endl; 
    cout << "Time's up. Try your best to reproduce the matrix form memory!" << endl; 

    int yourGuess[5][5]; 

    for(int i = 0; i < 5; i++){
        cout << "Enter row " << (i + 1) << ": "; 

        for(int j = 0; j < 5; j++){
            cin >> yourGuess[i][j]; 
        }
    }

    int correct = 0; 
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(yourGuess[i][j] == targetMatrix[i][j]){
                correct = correct + 1;
            }

        }
    }
}