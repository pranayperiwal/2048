#include "checkMove.h"
#include "undo.h"

//checks if the move made generates a new tile or not
bool validMove(int currentGameState[4][4], int tempGameState[4][4]){
  bool check = false;
  for(int i =0;i<4;i++){
    for(int j =0;j<4;j++){
      if(currentGameState[i][j]!=tempGameState[i][j]){
        check = true;
        break;
      }
    }
  }
  return check;
}

void undo(int currentGameState[4][4], int **previousGameState){
    for(int i =0;i<4;i++){
        for(int j =0;j<4;j++){
            currentGameState[i][j]=previousGameState[i][j];
        }
    }
}