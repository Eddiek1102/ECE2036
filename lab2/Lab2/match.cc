#include <iostream>
#include <ctime>
#include <cstdlib>
#include "match.h"
using namespace std;

Match::Match(int sec){
    studyTime = sec;
    srand(time(0));

    int nums[25];
    for (int i = 0; i < 25; i++){
        nums[i] = 0;
    }
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            int value;
            do{
            value = rand() % 25 + 1;
            } while (nums[value - 1] == 1);

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
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            targetMatrix[i][j] = matrix[i][j];
        }
    }
}

int *Match::getTargetMatrix(){
    int *matrix = &targetMatrix[0][0];
    return matrix;
}


void Match::playGame(){
    cout << "Press Enter to Start " << endl; 
    string key; 
    getline(cin, key); 

    cout << "Memorize numbers inside this matrix: " << endl;
    cout << "-----------------------------------" << endl;

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            cout << targetMatrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "-----------------------------------" << endl;

    int start = time(0);
    int end = start + getStudyTime();

    while (time(0) <= end){
        int remaining = end - time(0);
        cout << "\rTime Remaining: " << remaining << " ";
        cout.flush();
        int counter = time(0);
        while (time(0) - counter <= 0){
        }
    }


    cout << "\nTime's up. Try your best to reproduce the matrix form memory!" << endl;
    system("clear"); 
    cout << endl;
    


    int yourGuess[5][5];

    for (int i = 0; i < 5; i++){
        cout << "\nEnter row " << (i + 1) << ": ";

        for (int j = 0; j < 5; j++){
            cin >> yourGuess[i][j];
        }
    }

    int correct = 0;
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            if (yourGuess[i][j] == targetMatrix[i][j]){
                correct = correct + 1;
            }
        }
    }
    cout << "You got " << correct << " out of 25 correct " << endl; 
    cout << endl; 
    cout << "Press enter to continue" << endl; 
    cin.ignore(1);
    string key2; 
    getline(cin, key2); 
}
