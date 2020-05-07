#include <iostream>
#include "../header/finalMovements.h"
#include "../header/endConditions.h"

using namespace std;

void winningCondition(int currentGameState[4][4], int score){
    for(int i =0;i<4;i++){
      for(int j =0;j<4;j++){
        if(currentGameState[i][j]==2048){
          cout<<"You win the game!! :)"<<endl;
          cout<<"Your final score was: "<<score<<endl;
          break;
        }
      }
    }
}

//checking for final game state conditions in case of loss
bool losingCondition(int currentGameState[4][4], int **previousGameState, int &score){
  if(upFinal(currentGameState, previousGameState, score) && downFinal(currentGameState, previousGameState, score)
  && rightFinal(currentGameState, previousGameState, score) && leftFinal(currentGameState, previousGameState, score)){
    return true;
  }
  else return false;
}
