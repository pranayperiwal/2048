#include <iostream>
using namespace std;

//When left key (a) is pressed

void left(int grid[4][4]) {
  for (int i = 0; i < 4; i++) {
    for (int j = 1; j < 4; j++) {
      int count = 0;
      while(grid[i][j - 1 - count] == 0 && (j - 1 - count) >= 0){
        count++;
      }
      if (count>0) {
        grid[i][j - count] = grid[i][j];
        grid[i][j]=0;
      }
    }
  }

  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 4; j++) {
      if (j < 3) {
        if (grid[i][j] == grid[i][j + 1]) {
          grid[i][j] = grid[i][j] + grid[i][j + 1];
          grid[i][j + 1] = 0;
        }
      }
      if (j > 0) {
        if (grid[i][j - 1] == 0) {
          grid[i][j - 1] = grid[i][j];
          grid[i][j] = 0;
        }
      }
    }
  }
}
