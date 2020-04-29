#include <iostream>
using namespace std;

int grid[4][4];

void newgame() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j ++) {
      grid[i][j] = 0;
    }
  }
}

void printboard() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j ++) {
      if (grid[i][j] == 0) {
        cout << "_ ";
      } else {
        cout << grid[i][j];
      }
    }
    cout << endl;
  }

  cout << "n: new game, w: up, a: left, s: down, d: right, q: quit" << endl;
}

int main() {

  while (true) {
    printboard();
    char inputletter;
    cin >> inputletter;
    if (inputletter == 'n') {
      newgame();
    } else if (inputletter == 'q') {
      break;
    }
  }

  //Added a new line to check
  //Second Line to check

  return 0;
}
