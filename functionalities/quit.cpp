#include <fstream>
#include <sys/stat.h>
#include <sys/types.h>
#include "../header/save.h"
using namespace std;

void save(int currentGameState[4][4], int &score){
    int makedirectory;
    makedirectory = system("mkdir -p savedstate");

    ofstream fout;
    fout.open("savedstate/tempstate.txt");

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
}

