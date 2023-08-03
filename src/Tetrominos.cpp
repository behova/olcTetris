
#include "Tetrominos.h"

// returns tetrimino struct definition in Tetriminos class
Tetriminos::tetrimino Tetriminos::getRandomTetrimino() {
  int r = rand() % 7;

  switch (r) {
  case 0:
    return shapeArray[0];
  case 1:
    return shapeArray[1];
  case 2:
    return shapeArray[2];
  case 3:
    return shapeArray[3];
  case 4:
    return shapeArray[4];
  case 5:
    return shapeArray[5];
  case 6:
    return shapeArray[6];
  default:
    return shapeArray[0];
  }
}