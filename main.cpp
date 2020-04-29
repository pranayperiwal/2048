#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int grid[4][4];

//initializes the grid to all 0s
void newgame() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j ++) {
      grid[i][j] = 0;
    }
  }

  //generation of 2 random coordinates on the map and filling it in with 2 or 4 
  srand(time(NULL));
  int count=0;
  //we are checking to make sure only 2 values are generated which are not in the same coordinate
  while(count!=2){
    int randi = rand()%4;
    int randj = rand()%4;
    //generating a random number between 0 and 9
    int probability = rand()%10;
    if(grid[randi][randj]==0){
      if(probability<8){ //this creates an 80% chance as the probablity of it being less than 8 is 80% and we assign 2 for 80% of the time
        grid[randi][randj]=2;
      }
      else
      {
        grid[randi][randj]=4; //for the remaining 20% we generate a 4 as a starting value
      }
      count++;
    }
  }
}

//prints the current board
void printboard() {
  cout << "n: start new game, w: up, a: left, s: down, d: right, q: quit" << endl;
  cout<<"- * - * - * - * -"<<endl;
  for (int i = 0; i < 4; i++) {
    cout<<"| ";
    for (int j = 0; j < 4; j ++) {
        
        if (grid[i][j] == 0) 
          cout<<"  | ";
        else
        {
          cout<<grid[i][j]<<" | ";
        }     
    }
    cout<<endl;
    cout<<"- * - * - * - * -"<<endl;
  }
}

int main() {


  while (true) {
    
    cout << "n: start new game, w: up, a: left, s: down, d: right, q: quit" << endl;
    char inputletter;
    cin >> inputletter;
    if (inputletter == 'n') {
      newgame();
      printboard();
    } else if (inputletter == 'q') {
      break;
    }
  }

  //Added a new line to check
  //Second Line to check

  return 0;
}
