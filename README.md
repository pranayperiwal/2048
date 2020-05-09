# COMP1340-Game
Repository used to edit the code by the team members.

Game name: 2048

Problem Statement : In our project we try to implement what we have learned throughout the course into one final project. We have made the interactive game 2048 which can be played on the terminal using various features as listed below. The objective of the game being reaching the tile 2048 by combining tiles 2, 4, 16, 32, 64, 128, 256, 512 and 1024. We have used data structures such as 2D arrays, file input/output, functions, make file, probability and random generation of numbers.

1. Brief Identification of Team Members

Prateek Kher - 3035709590
Pranay Periwal - 3035664697

2. Game Description with Basic Rules
2048 is a single player puzzle-based game which requires the player to slide blocks of numbers on a 4x4 grid to combine them until a tile reaches the number 2048. The game starts out with 2 tiles on the grid which can either be a ‘2’ or a ‘4’. The player can then move all the number tiles to the right, left, up or down by clicking the right, left, up or down arrow key. If supposing the player plays right, and there are 2 tiles of the same number in any of the rows, those number tiles would add up to double the original tile number.
With every move made, the score of the player increases by the number of the tiles which were combined. For example, if a 2 and 2 tile combine to give a number 4 tile, the score added would be 4.
One of the important rules is that with each move, the combination of the same number tiles is in the direction of the move made. For example, if there are 3 2s in the top right of the 4x4 grid and the user makes a right move, the new tiles would be 2 and 4 in the top right, as opposed to 4 and 2. However for the same conditions if the user moved left, the top row would be 4 and 2 since the combination of tiles now took place starting from the left.
A new tile is generated after the combination of the tiles takes place. The new tile generated can be a ‘2’ or a ‘4’.


3. Features/Functions and GitHub Repo

a) Features

Requirements -

i) Generation of random game sets or events :
The initial game state would consist of 2 tiles generated randomly anywhere on the 4x4 board. The 2 tiles would be a combination of ‘2’ and ‘4’.
The new tile generated after every move would be either a ‘2’ or a ‘4’. However, the 2 would be generated 90% of the time and the 4 10% of the time.

ii) Data structures for storing game status :
The game state would be stored in a 2D array. Therefore, for the project, we will be using a linear form of data structure. We will not be using vectors as we do not need to change the size of our board (the permanent size of the board is 4x4).

iii) Dynamic memory management : We will be maintaining a previous game state and a current game state for the purpose of the “undo” functionality we aim to implement. The previous game state would be maintained in a dynamic 2D array. If undo move is made, the current state would simply point to the previous state and the board is changed. The previous game state is deleted before the game is closed. In this special feature the user can undo up to 1 move. When the user undoes the move, the score also goes back to the previous state. The player can then start playing again as per the options. Maintaining the undo score and undo game state gives the user also flexibility if they make a mistake while playing a game.

iv) File input/output (e.g., for loading/saving game status) : We will implement Undo, Quit, New Game functions. When there are no moves left, or the user wants to quit the game, we will be storing that specific state of the game at that point of time in a new output file, and displaying that on the terminal. Further, we have implemented the features of quit and save, save, and just quit. When the user saves, we output the game state to another folder which contains the saved game state. The user can retrieve the game state by loading this game state again, and continuing to play. The saved game state also preserves the user score. Further, the saved game state is saved in a directory we create 'savedgamestate'. The loading of game state also takes in the input from the file within this folder. This helps our game look cleaner, and more compact.

v) Program codes in multiple files : Apart from the main , makefile, and the README we have divided the code into further 3 more directories. The three directories are header, functionalities and movement. The movement directory contains all the cpp files with respect to the movement of up, left, right and down. The functionalities directory contains the cpp files of end conditions, quit and undo. We have the headers directory which essentially contains the .h files. We call these various filed from the main.cpp file. The code is divided up cleanly so that user can easily identify and navigate through the code.

b) Functions

i. Moves by the player and the resultant changes of the game state:
a) Up
b) Down
c) Right
d) Left
ii. To check if a valid move is made and only then create a random tile
iii. Creating a random new tile with 2 90% of the time and 4 10% of the time
iv. Giving conditions for the final state and end conditions in the case the player is unable to make any more moves
v. Restart of the game
vi. Quitting the game
vii. Saving the game state
viii. Quitting and saving the game state
ix. Undo move by 1 step
x. Printing the state of board.
xi. Starting a new game condition. 

c) GitHub Repo

Link for the video and gameplay with explanation:
https://drive.google.com/drive/folders/1hSCnzt6MycVyaZ_aQQ_UvQE0uekhlePZ?usp=sharing
We have changed the settings to anyone with the link can view the video.

The github repository where both the students have been added as contributors:
https://github.com/prateekkher/2048
