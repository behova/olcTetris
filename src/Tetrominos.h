#ifndef TETRIMINOS_H_
#define TETRIMINOS_H_

#include "olcPixelGameEngine.h"
#include <vector>

// main gameboard class

class Tetriminos {
public:
  Tetriminos();

  struct tetrimino {
    int block[16];
  };

  // Vector that contains each type of tetrimino /// reimplimentation with
  // vectors
  char lastTetrimino;
  std::vector<char> bagOne;
  std::vector<char> bagTwo;
  std::vector<char> charTetriminos = {'O', 'I', 'S', 'Z', 'L', 'J', 'T'};
  std::vector<tetrimino> vecTetriminos = {
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

  // get struct that contains array of tetrimino
  struct tetrimino getVecRandomTetrimino();
};
#endif