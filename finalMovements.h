#ifndef FINAL_MOVEMENTS_H
#define FINAL_MOVEMENTS_H

bool leftFinal(int currentGameState[4][4], int **previousGameState, int &score);
bool rightFinal(int currentGameState[4][4], int **previousGameState, int &score);
bool upFinal(int currentGameState[4][4], int **previousGameState, int &score);
bool downFinal(int currentGameState[4][4], int **previousGameState, int &score);

#endif