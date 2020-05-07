#include "../header/movements.h"
#include "../header/checkMove.h"
#include "../header/finalMovements.h"


//When left key (a) is pressed
bool left(int currentGameState[4][4], int **previousGameState, int &score){
  
  //creating a temporary game state
  int tempGameState[4][4];

  //intializing temp to current game state
  for(int i =0;i<4;i++){
      for(int j =0;j<4;j++){
          tempGameState[i][j]= currentGameState[i][j];
      }
  }
  
  //removing empty space to the left each number in the tempGameState
  for (int i = 0; i < 4; i++) {
    for (int j = 1; j < 4; j++) {
      int count = 0; //calculates how many empty spaces above a number
      while(tempGameState[i][j - 1 - count] == 0 && (j - 1 - count) >= 0){
        count++;
      }
      //shifts the number to the leftmost position empty space possible
      if (count>0) {
        tempGameState[i][j - count] = tempGameState[i][j];
        tempGameState[i][j]=0;
      }
    }
  }

  //moving and combining the tempGameState numbers
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
      //combining the tempGameState numbers if they are the same
      if (j < 3) {
        if (tempGameState[i][j] == tempGameState[i][j + 1]) {
          tempGameState[i][j] = tempGameState[i][j] + tempGameState[i][j + 1];
          tempGameState[i][j + 1] = 0;
          score+=tempGameState[i][j] + tempGameState[i][j + 1];//increasing the score if a combination happens
        }
      }
     //to check again if there is a free space created on the left of the number and then moving the number there
      if (j > 0) {
        if (tempGameState[i][j - 1] == 0) {
          tempGameState[i][j - 1] = tempGameState[i][j];
          tempGameState[i][j] = 0;
        }
      }
    }
  }

  //checking if move made makes a change to the game status
  if(validMove(currentGameState, tempGameState)){
      //making changes to previous and current game state if a valid move is made
      for(int i =0;i<4;i++){
          for(int j =0;j<4;j++){
              previousGameState[i][j]=currentGameState[i][j];
              currentGameState[i][j]= tempGameState[i][j];
          }
      }

      return true;
  }
  else{
      return false;
  }
}

//function called when the board is full to check if the up move is possible
bool leftFinal(int currentGameState[4][4], int **previousGameState, int &score){
  
  //creating a temporary game state
  int tempGameState[4][4];

  //intializing temp to current game state
  for(int i =0;i<4;i++){
      for(int j =0;j<4;j++){
          tempGameState[i][j]= currentGameState[i][j];
      }
  }
  
  //removing empty space to the left each number in the tempGameState
  for (int i = 0; i < 4; i++) {
    for (int j = 1; j < 4; j++) {
      int count = 0; //calculates how many empty spaces above a number
      while(tempGameState[i][j - 1 - count] == 0 && (j - 1 - count) >= 0){
        count++;
      }
      //shifts the number to the leftmost position empty space possible
      if (count>0) {
        tempGameState[i][j - count] = tempGameState[i][j];
        tempGameState[i][j]=0;
      }
    }
  }

  //moving and combining the tempGameState numbers
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
      //combining the tempGameState numbers if they are the same
      if (j < 3) {
        if (tempGameState[i][j] == tempGameState[i][j + 1]) {
          tempGameState[i][j] = tempGameState[i][j] + tempGameState[i][j + 1];
          tempGameState[i][j + 1] = 0;
          score+=tempGameState[i][j] + tempGameState[i][j + 1];//increasing the score if a combination happens
        }
      }
     //to check again if there is a free space created on the left of the number and then moving the number there
      if (j > 0) {
        if (tempGameState[i][j - 1] == 0) {
          tempGameState[i][j - 1] = tempGameState[i][j];
          tempGameState[i][j] = 0;
        }
      }
    }
  }

  //checking if move made makes a change to the game status
  if(validMove(currentGameState, tempGameState)){
      return false;
  }
  else{
      return true;
  }

}
