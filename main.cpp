#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include <iomanip>
#include "header/movements.h"
#include "header/checkMove.h"
#include "header/undo.h"
#include "header/endConditions.h"
#include "header/save.h"
#include <fstream>
#include <sys/stat.h>
#include <sys/types.h>

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
  score=0;
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

//function called for when quitting the game
char quittingGame(){
  char confirm;
  cout<<"Are you sure you would like to quit? Please enter 'y' for Yes or 'n' for No"<<endl;
  cin>>confirm;
  while(confirm!= 'y' && confirm!= 'n'){
    cout<<"Are you sure you would like to quit? Please enter 'y' for Yes or 'n' for No"<<endl;
    cin>>confirm;
  }
  if(confirm=='y'){
    system("clear");
    cout<<"\n\n\n\n";
    cout<<"Your final score was: "<<score<<endl;
    cout<<"We hope you had fun! See you later!!\n\n\n"<<flush;
    return 'y';
  }
  else{
    system("clear");
    cout<<flush;
    printboard(true);
    return 'n';
  }
}

//to check if only letter is entered
bool validInput(string inputletter){
  if (inputletter.length() > 1) {
    system("clear");
    printboard(true);
    cout << "Please enter a valid input! Valid input contains only 1 character." << endl;
    return false;
  }
  else
  {
    return true;
  }
  
}


int main() {
  //initializing the dynamic 2D array to store the previous game state
  for(int i = 0; i < 4; ++i) {
      previousGameState[i] = new int[4];
  }
  
  //stores the number of moves made
  int numberOfMoves =0; 

  while (true) {

    //check for winning condition
    winningCondition(currentGameState, score);

    bool movesPoss=false; //boolean to check if there is any space empty on the board
    for(int i =0;i<4;i++){
      for(int j =0;j<4;j++){
        if(currentGameState[i][j]==0){
          movesPoss=true;
          break;
        }
      }
    }

    //if no spaces on the baord are left, do these following checks for possible loss
    if(!movesPoss){
      if(losingCondition(currentGameState, previousGameState,score)){
        cout<<"Unfortunately no more valid moves are possible and the game is lost! :("<<endl;
        char inputletter;
        while(true){
          cout<<"n: start new game, u:undo, q: quit"<<endl;
          cin >> inputletter;
          //new game
          if(inputletter == 'n'){
            newgame();
            system("clear");
            cout<<"Starting a new game for you!\n\n"<<flush;
            printboard(true);
            score=0;
            break;
          }

          //undo
          else if(inputletter =='u'){
            undo(currentGameState, previousGameState);
            system("clear");
            cout<<flush;
            printboard(true);
            break;
          }

          //checks for quitting the game
          else if (inputletter == 'q') {
            char decision = quittingGame();
            if(decision =='y')
              break;
            else
              continue;
          }

          else{
            cout<<"Please enter a correct input as given below."<<endl;
          }
        }

        //break out of the game completely
        if(inputletter == 'q')
          break;  
        else 
          continue;

      }
    }


    //start of normal output for the game
    cout << "n: start new game, w: up, a: left, s: down, d: right" << endl;
    cout << "u: undo, q: quit, z: save and quit, x: save, l: load" << endl;
    string inputletter;
    cin >> inputletter;

    //to check if input is only one character or more than one
    if(!validInput(inputletter))
      continue;

    //starting a new game
    if (inputletter == "n") {
      cout << "You are about to start a new game. Are you sure you want to continue?" << endl;
      cout << "Please enter 'y' for Yes, and 'n' for No." << endl;

      string inp;
      cin >> inp;

      //to check if input is only one character or more than one
      if(!validInput(inp))
        continue;

      while(inp!= "y" && inp!= "n"){
        cout<<"You are about to start a new game. Are you sure you want to continue?'\n'Please enter 'y' for Yes or 'n' for No."<<endl;
        cin>>inp;
      }  
      if(inp=="y"){
        newgame();
        system("clear");
        cout<<"Starting a new game for you!\n\n"<<flush;
        printboard(true);
      }
      else{
        if(numberOfMoves==0){
          system("clear");
          cout<<flush;
          continue;
        }
        else{
          system("clear");
          cout<<flush;
          printboard(true);
        }
        
      }
        
      

      
    }

    //loading game state
    else if (inputletter == "l") {
      cout << "You are about to load the game from a previous state. Are you sure you want to continue?" << endl;
      cout << "Please enter 'y' for Yes, and 'n' for No." << endl;

      string inp;
      cin >> inp;

      //to check if input is only one character or more than one
      if(!validInput(inp))
        continue;

      while(inp!= "y" && inp!= "n"){
        cout<<"You are about to load the game from a previous state. Are you sure you want to continue?'\n'Please enter 'y' for Yes or 'n' for No."<<endl;
        cin>>inp;
      }  
      
      //if person wants to load from previous state
      if(inp=="y"){
        system("clear");
        cout<<flush;

        ifstream fin;
        fin.open("savedstate/tempstate.txt");

        //Checks if the loaded file exists or not. Accordingly prompts the user.
        if (fin.fail()) {
          system("clear");
          cout<<"No saved state available!\n" <<flush;
          printboard(true);
        } 
        else {
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
        }
        fin.close();

      }
      //if person does not wish to load drom previous state 
      else{
        system("clear");
        cout<<flush;
        printboard(true);
      }
        
    }

    //save functionality
    else if (inputletter == "x") {
      cout << "You are about to save the game state. Are you sure you want to continue?" << endl;
      cout << "Please enter 'y' for Yes, and 'n' for No." << endl;

      string inp;
      cin >> inp;

      //to check if input is only one character or more than one
      if(!validInput(inp))
        continue;

      while(inp!= "y" && inp!= "n"){
        cout<<"You are about to save the game state. Are you sure you want to continue?'\n'Please enter 'y' for Yes or 'n' for No."<<endl;
        cin>>inp;
      }

      if (inp == "y") {

        system("clear");
        cout<<flush;
        printboard(true);

        //saving function called from saveQuit.cpp
        save(currentGameState, score);
        
      }
      else{
        system("clear");
        cout<<flush;
        printboard(true);
      }
    }

    //save and quit functionality
    else if (inputletter == "z") {
      cout << "Are you sure you want to save and quit? Please enter 'y' for Yes, and 'no' for No. " << endl;
      string inp;
      cin >> inp;

    //to check if input is only one character or more than one
    if(!validInput(inp))
      continue;

      while(inp!= "y" && inp!= "n"){
        cout<<"Are you sure you would like to save and quit? Please enter 'y' for Yes or 'n' for No"<<endl;
        cin>>inp;
      }

      if (inp == "y") {
      cout << "The current state of board is shown below. " << endl;
      cout << "You have saved the game! Press 'l' to reload the game next time and continue from here. " << endl;
      cout << "Hope you have a good day!" << endl;

      system("clear");
      cout<<flush;
      cout<<"Thank you for playing the game! It has been saved successfully."<<endl;

      //saving the game
      save(currentGameState, score);
      //quits the game
      break;
    }
      else {
        system("clear");
        cout<<flush;
        printboard(true);
      }
    }

    //up move
    else if (inputletter == "w") {
      system("clear");
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
      system("clear");
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
      system("clear");
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
      system("clear");
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
    else if (inputletter == "u"){
      if(numberOfMoves>=1){
         undo(currentGameState, previousGameState);
      }
      system("clear");
      cout<<flush;
      printboard(true);
    }

    //checks for quitting the game
    else if (inputletter == "q") {
      char decision = quittingGame();
      if(decision =='y')
        break;
      else
        continue;
    }

    else{
      system("clear");
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
