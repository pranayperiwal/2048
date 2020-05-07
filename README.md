# COMP1340-Game
Repository used to edit the code by the team members.

Game name: 2048

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

iii) Dynamic memory management : We will be maintaining a previous game state and a current game state for the purpose of the “undo” functionality we aim to implement. The previous game state would be maintained in a dynamic 2D array. If undo move is made, the current state would simply point to the previous state and the board is changed. The previous game state is deleted before the game is closed.

iv) File input/output (e.g., for loading/saving game status) : We will implement Undo, Quit, New Game functions. When there are no moves left, or the user wants to quit the game, we will be storing that specific state of the game at that point of time in a new output file, and displaying that on the terminal. Further, we have implemented the features of quit and save, save, and just quit. When the user saves, we output the game state to another folder which contains the saved game state. The user can retrieve the game state by loading this game state again, and continuing to play. The saved game state also preserves the user score.

v) Program codes in multiple files : We will be splitting our code tentatively into three files. These files will contain the code corresponding to the game functionality (game logic), tiles movement, generation of random tiles and merging of tiles.

b) Functions

1. Moves by the player and the resultant changes of the game state:
a) Up
b) Down
c) Right
d) Left
2. To check if a valid move is made and only then create a random tile
3. Creating a random new tile with 2 90% of the time and 4 10% of the time
4. Giving conditions for the final state and end conditions in the case the player is unable to make any more moves
5. Restart of the game
6. Quitting the game
7. Saving the game state
8. Quitting and saving the game state
9. Undo move by 1 step

c) GitHub Repo

Link for the video and gameplay with explanation:
https://drive.google.com/drive/folders/1hSCnzt6MycVyaZ_aQQ_UvQE0uekhlePZ?usp=sharing
We have changed the settings to anyone with the link can view the video. 

The github repository where both the students have been added as contributors:
https://github.com/prateekkher/2048
