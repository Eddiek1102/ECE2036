#include "match.h"
#include "addgame.h"
#include "sumtotal.h"

#include <cstdlib> 
#include <ctime> 

using namespace std; 


int main(){
  
  Match matchGame(20);
  QuickAdd addingGame(5); 
  SumTotal sumTotalGame(5, 5); 


  srand(time(0));


  matchGame.playGame(); 
  addingGame.playGame(); 
  sumTotalGame.playGame(); 


  return 0; 
}

