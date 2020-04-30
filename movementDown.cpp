//creating the game logic for when the 's' (down) key is pressed
void down(int grid[4][4]){

    //removing empty space above each number in the grid
    for(int j =0;j<4;j++){
        for(int i =2;i>=0;i--){
            int count=0; //calculates how many empty spaces above a number
            while(grid[i+1+count][j]==0 && (i+1+count)<=3){
                count++;
            }
            //shifts the number to the lowermost position empty space possible
            if(count>0){
                grid[i+count][j]=grid[i][j];
                grid[i][j]=0;
            }
        }
    }

    //moving and combining the grid numbers
    for(int j=0;j<4;j++){
        for(int i =3;i>=0;i--){
            
            //combining the grid numbers if they are the same
            if(i>0){
                if(grid[i][j]==grid[i-1][j]){
                    grid[i][j]=grid[i][j]+grid[i-1][j];
                    grid[i-1][j] = 0;
                }
            }
            //to check again if there is a free space created above a grid and then moving the number there
            if(i<3){
                if(grid[i+1][j]==0){
                    grid[i+1][j]=grid[i][j];
                    grid[i][j]=0;
                }
            }
              
        }
        
    }

}