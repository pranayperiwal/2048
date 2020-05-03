#include "movements.h"

//When right key (d) is pressed
void right(int grid [4][4], int &score) {
  
  //removing empty space to the right each number in the grid
  for (int i = 0; i < 4; i++) {
    for (int j = 2; j >= 0; j--) {
      int count = 0; //calculates how many empty spaces above a number
      while (grid[i][j + 1 + count] == 0 && (j + 1 + count) <= 3) {
        count++;
      }
      //shifts the number to the rightmost position empty space possible
      if (count > 0){
          grid[i][j + count] = grid[i][j];
          grid[i][j] = 0;
      }
    }
  }
  
  //moving and combining the grid numbers
  for (int i = 0; i < 4; i++){
    for (int j = 3; j >= 0; j--){
      //combining the grid numbers if they are the same
      if (j > 0){
        if (grid[i][j] == grid[i][j - 1]) {
          grid[i][j] = grid[i][j] + grid[i][j - 1];
          grid[i][j - 1] = 0;
          score+=grid[i][j] + grid[i][j - 1];//increasing the score if a combination happens
        }
      }
      //to check again if there is a free space created on the right of the number and then moving the number there
      if (j < 3){
        if(grid[i][j + 1] == 0){
          grid[i][j + 1] = grid[i][j];
          grid[i][j] = 0;
        }
      }
    }
  }
}
