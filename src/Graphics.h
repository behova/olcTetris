#ifndef GRAPHICS_H_
#define GRAPHICS_H_

#include "Tetrominos.h"
#include "olcPixelGameEngine.h"

// main gameboard class

class Graphics {
public:
  int rows;
  int columns;
  int stX;
  int stY;
  int pxW;
  int pxH;

public:
  void setUI(int rows, int columns, int stX, int stY, int pxW, int pxH);

  void drawBoard(olc::PixelGameEngine *pge, int (*currentBoard)[26][11]);

  void drawUI(olc::PixelGameEngine *pge, int score, int level, int lines,
              Tetriminos::tetrimino nextPiece);

  void drawGameOver(olc::PixelGameEngine *pge, int score, int level, int lines);

  void drawPause(olc::PixelGameEngine *pge, int score, int level, int lines);

  void drawReset();
};

#endif