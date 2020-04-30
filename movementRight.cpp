#include <iostream>
using namespace std;

//When right key (d) is pressed

void right(int grid [4][4]) {
  for (int i = 0; i < 4; i++) {
    for (int j = 2; j >= 0; j--) {
      int count = 0;
      while (grid[i][j + 1 + count] == 0 && (j + 1 + count) <= 3) {
        count++;
      }
      if (count > 0){
          grid[i][j + count] = grid[i][j];
          grid[i][j] = 0;
      }
    }
  }

  for (int i = 0; i < 4; i++){
    for (int j = 3; j >= 0; j--){
      if (j > 0){
        if (grid[i][j] == grid[i][j - 1]) {
          grid[i][j] = grid[i][j] + grid[i][j - 1];
          grid[i][j - 1] = 0;
        }
      }
      if (j < 3){
        if(grid[i][j + 1] == 0){
          grid[i][j + 1] = grid[i][j];
          grid[i][j] = 0;
        }
      }
    }
  }
}
