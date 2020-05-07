#ifndef END_CONDITIONS_H
#define END_CONDITIONS_H

void winningCondition(int currentGameState[4][4], int score);
bool losingCondition(int currentGameState[4][4], int **previousGameState, int &score);

#endif