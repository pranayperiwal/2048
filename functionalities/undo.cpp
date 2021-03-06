#include "../header/checkMove.h"
#include "../header/undo.h"

//checks if the move made should generates a new tile or not
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
//undo the move
void undo(int currentGameState[4][4], int **previousGameState, int&score, int&prevScore){
    for(int i =0;i<4;i++){
        for(int j =0;j<4;j++){
            currentGameState[i][j]=previousGameState[i][j];
        }
    }
    score = prevScore;
}