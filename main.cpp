#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include <iomanip>
#include "movements.h"
#include "checkMove.h"
#include "undo.h"
#include "finalMovements.h"
#include <fstream>

using namespace std;


//creating inital variables
int currentGameState[4][4];
int **previousGameState = new int*[4];
int score=0;


//generates how many ever random numbers on the currentGameState as the parameter "number"
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
    if(currentGameState[randi][randj]==0){
      if(probability<9){ //this creates a 90% chance as the probablity of it being less than 9 is 90% and we assign 2 for time
        currentGameState[randi][randj]=2;
      }
      else
      {
        currentGameState[randi][randj]=4; //for the remaining 10% we generate a 4 as a starting value
      }
      count++;
    }
  }
}

//initializes the currentGameState to all 0s
void newgame() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j ++) {
      currentGameState[i][j] = 0;
    }
  }
  //adds 2 random numbers to the currentGameState
  randomNum(2);

  //initializing all the values in previous game state to 0
  for(int i =0;i<4;i++){
      for(int j =0;j<4;j++){
          previousGameState[i][j]=0;
      }
  }
}

//prints the current board
void printboard(bool valid) {
  if(!valid){
    cout<<"   Score:"<<score<<"  Not a valid move!\n"<<endl;
  }
  else{
    cout<<"          Score: "<<score<<'\n'<<endl;
  }
  cout<<"- * - * - * - * - * - * - * -"<<endl;
  for (int i = 0; i < 4; i++) {
    cout<<"|";
    for (int j = 0; j < 4; j ++){
        if (currentGameState[i][j] == 0)
          cout<<"      |";
        else
        {
          cout <<setw(5)<< currentGameState[i][j] << " |";
        }
      }
    cout<<endl;
    cout<<"- * - * - * - * - * - * - * -"<<endl;
  }
}


//checking for final game state conditions in case of loss
bool checkLoss(){
  if(upFinal(currentGameState, previousGameState, score) && downFinal(currentGameState, previousGameState, score)
  && rightFinal(currentGameState, previousGameState, score) && leftFinal(currentGameState, previousGameState, score)){
    return true;
  }
  else return false;
}


int main() {
  //initializing the dynamic 2D array to store the previous game state
  for(int i = 0; i < 4; ++i) {
      previousGameState[i] = new int[4];
  }

  int numberOfMoves =0; //stores the number of moves made

  while (true) {

    bool movesPoss=false; //boolean to check if there is any space empty on the board
    for(int i =0;i<4;i++){
      for(int j =0;j<4;j++){
        if(currentGameState[i][j]==0){
          movesPoss=true;
          break;
        }
      }
    }

    //check for winning condition
    for(int i =0;i<4;i++){
      for(int j =0;j<4;j++){
        if(currentGameState[i][j]==2048){
          cout<<"You win the game!! :)"<<endl;
          cout<<"Your final score was: "<<score<<endl;
          break;
        }
      }
    }

    //if no spaces on the baord are left, do these following checks
    if(!movesPoss){
      if(checkLoss()){
        cout<<"Unfortunately no more valid moves are possible and the game is lost! :("<<endl;
        char inputletter;
        while(true){
          cout<<"n: start new game, u:undo, q: quit"<<endl;
          cin >> inputletter;
          //new game
          if(inputletter == 'n'){
            newgame();
            system("CLS");
            cout<<"Starting a new game for you!\n\n"<<flush;
            printboard(true);
            score=0;
            break;
          }

          //undo
          else if(inputletter =='u'){
            undo(currentGameState, previousGameState);
            system("CLS");
            cout<<flush;
            printboard(true);
            break;
          }

          //checks for quitting the game
          else if (inputletter == 'q') {
            char confirm;
            cout<<"Are you sure you would like to quit? Please enter 'y' for Yes or 'n' for No"<<endl;
            cin>>confirm;
            while(confirm!= 'y' && confirm!= 'n'){
              cout<<"Are you sure you would like to quit? Please enter 'y' for Yes or 'n' for No"<<endl;
              cin>>confirm;
            }
            if(confirm=='y'){
              system("CLS");
              cout<<"\n\n\n\n";
              cout<<"Your final score was: "<<score<<endl;
              cout<<"We hope you had fun! See you later!!\n\n\n"<<flush;
              break;
            }
            else{
              system("CLS");
              cout<<flush;
              printboard(true);
              continue;
            }
          }

          else{
            cout<<"Please enter a correct input as given below."<<endl;
          }
        }

        if(inputletter == 'q'){
          break;
        }
        else continue;

      }
    }


    cout << "n: start new game, w: up, a: left, s: down, d: right" << endl;
    cout << "u: undo, q: quit, z: save and quit, l: load" << endl;
    string inputletter;
    cin >> inputletter;

    if (inputletter.length() > 1) {
      system("CLS");
      printboard(true);
      cout << "Please enter a valid input! Valid input contains only 1 character." << endl;
      continue;
    }

    //starting a new game
    if (inputletter == "n") {
      newgame();
      system("CLS");
      cout<<"Starting a new game for you!\n\n"<<flush;
      printboard(true);
    }

    else if (inputletter == "z") {
      cout << "Are you sure you want to save and quit? Please enter 'y' for yes, and 'no' for no. " << endl;
      char inp;
      cin >> inp;
      if (inp == 'y') {
      cout << "The current state of board is shown below. " << endl;
      cout << "You have saved the game! Press 'l' to reload the game next time and continue from here. " << endl;
      cout << "Hope you have a good day!" << endl;

      system("CLS");
      cout<<flush;
      cout<<"Thank you for playing the game! It has been saved successfully."<<endl;

      ofstream fout;
      fout.open("tempstate.txt");

      //First line in the output txt file will have score
      fout << score << endl;

      //Next 16 lines will have the individual integers of each element
      //of currentGameState
      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
          fout << currentGameState[i][j] << endl;
        }
      }
      fout.close();
      break;
    }
      else {
        printboard(true);
      }
    }

    else if (inputletter == "l") {
      system("CLS");
      cout<<flush;

      ifstream fin;
      fin.open("tempstate.txt");
      int arr[16];
      int tempscore;
      fin >> tempscore;
      score = tempscore;
      int count = 0;
      while (!fin.eof()) {
        fin >> arr[count];
        count ++;
      }

      int counter = 0;
      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
          currentGameState[i][j] = arr[counter];
          counter ++;
        }
      }
      printboard(true);
      fin.close();

    }


    //up move
    else if (inputletter == "w") {
      system("CLS");
      cout<<flush; //clears the screen for the new board
      if(up(currentGameState, previousGameState, score)){
        randomNum(1);
        printboard(true);
        numberOfMoves++;
      }
      else{
        printboard(false);
      }
    }

    //down move
    else if (inputletter == "s") {
      system("CLS");
      cout<<flush;
      if(down(currentGameState, previousGameState, score)){
        randomNum(1);
        printboard(true);
        numberOfMoves++;
      }
      else{
        printboard(false);
      }
    }

    //right move
    else if (inputletter == "d") {
      system("CLS");
      cout<<flush;
      if(right(currentGameState, previousGameState, score)){
        randomNum(1);
        printboard(true);
        numberOfMoves++;
      }
      else{
        printboard(false);
      }

    }

    //left move
    else if (inputletter == "a") {
      system("CLS");
      cout<<flush;
      if(left(currentGameState, previousGameState, score)){
        randomNum(1);
        printboard(true);
        numberOfMoves++;
      }
      else{
        printboard(false);
      }

    }

    //for undoing the move
    else if(inputletter =="u"){
      if(numberOfMoves>=1){
         undo(currentGameState, previousGameState);
      }
      system("CLS");
      cout<<flush;
      printboard(true);
    }

    //checks for quitting the game
    else if (inputletter == "q") {
      char confirm;
      cout<<"Are you sure you would like to quit? Please enter 'y' for Yes or 'n' for No"<<endl;
      cin>>confirm;
      while(confirm!= 'y' && confirm!= 'n'){
        cout<<"Are you sure you would like to quit? Please enter 'y' for Yes or 'n' for No"<<endl;
        cin>>confirm;
      }
      if(confirm=='y'){
        system("CLS");
        cout<<"\n\n\n\n";
        cout<<"Your final score was: "<<score<<endl;
        cout<<"We hope you had fun! See you later!!\n\n\n"<<flush;
        break;
      }
      else{
        system("CLS");
        cout<<flush;
        printboard(true);
        continue;
      }
    }

    else{
      system("CLS");
      printboard(true);
      cout<<"Please enter a correct input as given below."<<endl;
    }
  }

  //deleting the previous game state
  for(int i = 0; i < 4; ++i) {
        delete [] previousGameState[i];
    }
  delete [] previousGameState;

  return 0;
}
