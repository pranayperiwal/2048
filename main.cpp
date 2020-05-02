#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include <iomanip>
#include "movementUp.cpp"
#include "movementDown.cpp"
#include "movementRight.cpp"
#include "movementLeft.cpp"
using namespace std;

int grid[4][4];
int score=0;

//generates how many ever random numbers on the grid as the parameter "number"
void randomNum(int number){
  //generation of random coordinates on the map and filling it in with 2 or 4
  srand(time(NULL));
  int count=0;
  //we are checking to make sure only the number of values are generated as "number" which are not in the same coordinate
  while(count!=number){
    int randi = rand()%4;
    int randj = rand()%4;
    //generating a random number between 0 and 9
    int probability = rand()%10;
    if(grid[randi][randj]==0){
      if(probability<9){ //this creates a 90% chance as the probablity of it being less than 9 is 90% and we assign 2 for time
        grid[randi][randj]=2;
      }
      else
      {
        grid[randi][randj]=4; //for the remaining 10% we generate a 4 as a starting value
      }
      count++;
    }
  }
}

//initializes the grid to all 0s
void newgame() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j ++) {
      grid[i][j] = 0;
    }
  }
  randomNum(2);
}



//prints the current board
void printboard() {
  cout << "n: start new game, w: up, a: left, s: down, d: right, q: quit\n\n" << endl;
  cout<<"          Score: "<<score<<'\n'<<endl;
  cout<<"- * - * - * - * - * - * - * -"<<endl;
  for (int i = 0; i < 4; i++) {
    cout<<"|";
    for (int j = 0; j < 4; j ++){
        if (grid[i][j] == 0)
          cout<<"      |";
        else
        {
          cout <<setw(5)<< grid[i][j] << " |";
        }
      }
    cout<<endl;
    cout<<"- * - * - * - * - * - * - * -"<<endl;
  }
}

int main() {
  while (true) {

    cout << "n: start new game, w: up, a: left, s: down, d: right, q: quit" << endl;
    char inputletter;
    cin >> inputletter;
    if (inputletter == 'n') {
      newgame();
      system("CLS");
      cout<<"Starting a new game for you!\n\n"<<flush; 
      printboard();
    } else if (inputletter == 'w') {
      system("CLS");
      cout<<flush; //clears the screen for the new board
      up(grid, score);
      randomNum(1);
      printboard();
    }
    else if (inputletter == 's') {
      system("CLS");
      cout<<flush;
      down(grid, score);
      randomNum(1);
      printboard();
    }
    else if (inputletter == 'd') {
      system("CLS");
      cout<<flush;
      right(grid, score);
      randomNum(1);
      printboard();
    }
    else if (inputletter == 'a') {
      system("CLS");
      cout<<flush;
      left(grid, score);
      randomNum(1);
      printboard();
    }
    else if (inputletter == 'q') {
      system("CLS");
      cout<<"\n\n\n\n";
      cout<<"Your final score was: "<<score<<endl;
      cout<<"We hope you had fun! See you later!!\n\n\n"<<flush;
      break;
    }
    else{
      cout<<"Please enter a correct input as given below."<<endl;
    }
  }
  return 0;
}
