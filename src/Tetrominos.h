#ifndef TETRIMINOS_H_
#define TETRIMINOS_H_

#include "olcPixelGameEngine.h"

// main gameboard class

class Tetriminos {
public:
  struct tetrimino {
    int block[16];
  };
  // array of tetrimino structs that contain an array that represents the
  // tetrimino
  tetrimino shapeArray[7] = {
      {{0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0}

      },
      {{0, 2, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0}},
      {
          {0, 0, 0, 0, 0, 3, 3, 0, 3, 3, 0, 0, 0, 0, 0, 0},
      },
      {
          {0, 0, 0, 0, 4, 4, 0, 0, 0, 4, 4, 0, 0, 0, 0, 0},
      },
      {
          {0, 5, 0, 0, 0, 5, 0, 0, 0, 5, 5, 0, 0, 0, 0, 0},
      },
      {
          {0, 0, 6, 0, 0, 0, 6, 0, 0, 6, 6, 0, 0, 0, 0, 0},
      },
      {
          {0, 0, 0, 0, 7, 7, 7, 0, 0, 7, 0, 0, 0, 0, 0, 0},
      }

  };

public:
  // get struct that contains array of tetrimino
  struct tetrimino getRandomTetrimino();
};
#endif