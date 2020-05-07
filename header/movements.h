//header file for all 4 types of movements

#ifndef MOVEMENTS_H
#define MOVEMENTS_H

bool left(int currentGameState[4][4], int **previousGameState, int &score, int &prevScore);
bool right(int currentGameState[4][4], int **previousGameState, int &score, int &prevScore);
bool up(int currentGameState[4][4], int **previousGameState, int &score, int &prevScore);
bool down(int currentGameState[4][4], int **previousGameState, int &score, int &prevScore);

#endif