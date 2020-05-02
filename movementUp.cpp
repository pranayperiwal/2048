#include <iostream>
using namespace std;

//creating the game logic for when the 'w' (up) key is pressed
void up(int grid[4][4], int &score){

    //removing empty space above each number in the grid
    for(int j =0;j<4;j++){
        for(int i =1;i<4;i++){
            int count=0; //calculates how many empty spaces above a number
            while(grid[i-1-count][j]==0 && (i-1-count)>=0){
                count++;
            }
            //shifts the number to the upmost position empty space possible
            if(count>0){
                grid[i-count][j]=grid[i][j];
                grid[i][j]=0;
            }
        }
    }

    //moving and combining the grid numbers
    for(int j=0;j<4;j++){
        for(int i =0;i<4;i++){
            
            //combining the grid numbers if they are the same
            if(i<3){
                if(grid[i][j]==grid[i+1][j]){
                    grid[i][j]=grid[i][j]+grid[i+1][j];
                    grid[i+1][j] = 0;
                    score+=grid[i][j]+grid[i+1][j]; //increasing the score if a combination happens
                }
            }
            //to check again if there is a free space created above a grid and then moving the number there
            if(i>0){
                if(grid[i-1][j]==0){
                    grid[i-1][j]=grid[i][j];
                    grid[i][j]=0;
                }
            }
            
        }
        
    }

}

