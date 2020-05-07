#include "../header/movements.h"
#include "../header/checkMove.h"
#include "../header/finalMovements.h"

//creating the game logic for when the 's' (down) key is pressed
bool down(int currentGameState[4][4], int **previousGameState, int &score, int &prevScore){

    //creating a temporary game state
    int tempGameState[4][4];
    //storing the score temporarily
    int tempScore=score;

    //intializing temp to current game state
    for(int i =0;i<4;i++){
        for(int j =0;j<4;j++){
            tempGameState[i][j]= currentGameState[i][j];
        }
    }

    //removing empty space above each number in the tempGameState
    for(int j =0;j<4;j++){
        for(int i =2;i>=0;i--){
            int count=0; //calculates how many empty spaces above a number
            while(tempGameState[i+1+count][j]==0 && (i+1+count)<=3){
                count++;
            }
            //shifts the number to the lowermost position empty space possible
            if(count>0){
                tempGameState[i+count][j]=tempGameState[i][j];
                tempGameState[i][j]=0;
            }
        }
    }

    //moving and combining the tempGameState numbers
    for(int j=0;j<4;j++){
        for(int i =3;i>=0;i--){
            
            //combining the tempGameState numbers if they are the same
            if(i>0){
                if(tempGameState[i][j]==tempGameState[i-1][j]){
                    tempGameState[i][j]=tempGameState[i][j]+tempGameState[i-1][j];
                    tempGameState[i-1][j] = 0;
                    tempScore+=tempGameState[i][j]+tempGameState[i-1][j];//increasing the score if a combination happens
                }
            }
            //to check again if there is a free space created above a tempGameState and then moving the number there
            if(i<3){
                if(tempGameState[i+1][j]==0){
                    tempGameState[i+1][j]=tempGameState[i][j];
                    tempGameState[i][j]=0;
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
        prevScore = score;
        score=tempScore;

        return true;
    }
    else{
        return false;
    }

}

//function called when the board is full to check if the up move is possible
bool downFinal(int currentGameState[4][4], int **previousGameState, int &score){

    //creating a temporary game state
    int tempGameState[4][4];

    //intializing temp to current game state
    for(int i =0;i<4;i++){
        for(int j =0;j<4;j++){
            tempGameState[i][j]= currentGameState[i][j];
        }
    }

    //removing empty space above each number in the tempGameState
    for(int j =0;j<4;j++){
        for(int i =2;i>=0;i--){
            int count=0; //calculates how many empty spaces above a number
            while(tempGameState[i+1+count][j]==0 && (i+1+count)<=3){
                count++;
            }
            //shifts the number to the lowermost position empty space possible
            if(count>0){
                tempGameState[i+count][j]=tempGameState[i][j];
                tempGameState[i][j]=0;
            }
        }
    }

    //moving and combining the tempGameState numbers
    for(int j=0;j<4;j++){
        for(int i =3;i>=0;i--){
            
            //combining the tempGameState numbers if they are the same
            if(i>0){
                if(tempGameState[i][j]==tempGameState[i-1][j]){
                    tempGameState[i][j]=tempGameState[i][j]+tempGameState[i-1][j];
                    tempGameState[i-1][j] = 0;
                    score+=tempGameState[i][j]+tempGameState[i-1][j];//increasing the score if a combination happens
                }
            }
            //to check again if there is a free space created above a tempGameState and then moving the number there
            if(i<3){
                if(tempGameState[i+1][j]==0){
                    tempGameState[i+1][j]=tempGameState[i][j];
                    tempGameState[i][j]=0;
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