#include "addgame.h"
#include <cstdlib>
using namespace std; 

QuickAdd::QuickAdd(int num){
    numProblems = num; 
    timeElapsed = 0; 
    numberCorrect = 0; 
}   

void QuickAdd::playGame(){ 

    system("clear"); 
    
    int counter = time(0); 

    for(int i = 0; i < numProblems; i++){
        int num1 = rand() % 100 + 1; 
        int num2 = rand() % 100 + 1; 
        
        int result; 
        cout << "What's " << num1 << " + " << num2 << " = "; 
        cin >> result; 
        cout << endl; 

        if(result == num1 + num2){ 
            numberCorrect = numberCorrect + 1; 
        }
    }

    timeElapsed = time(0) - counter; 
    cout << "You got " << numberCorrect << " out of " << numProblems << " correct." << endl;
    cout << "Time elapsed: " << timeElapsed << " seconds." << endl; 

    cout << endl;
    cout << "Press enter to continue" << endl; 
    cin.ignore(1);
    string key3; 
    getline(cin, key3); 
}

int QuickAdd::getTimeElapsed(){
    return timeElapsed; 
}
