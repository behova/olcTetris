#ifndef BOARD_H_
#define BOARD_H_

#include "Tetrominos.h"
#include "olcPixelGameEngine.h"

// main gameboard class

class Board {
public:
  int rows;
  int columns;
  int currentBoard[26][11];
  int lockedBoard[26][11];

public:
  Board();

  void draw(olc::PixelGameEngine *pge, int stX, int stY, int pxW, int pxH);

  void drawUI(olc::PixelGameEngine *pge, int stX, int stY, int pxW, int pxH,
              int score, int level, int lines, Tetriminos::tetrimino nextPiece);

  void drawGameOver(olc::PixelGameEngine *pge, int stX, int stY, int pxW,
                    int pxH, int score, int level, int lines);

  void resetBoard();

  int getMinoIndex(int px, int py, int rotation);

  int checkCollision(Tetriminos::tetrimino piece, int rotation, int nPosX,
                     int nPosY);

  void addPiece(Tetriminos::tetrimino piece, int rotation, int nPosX,
                int nPosY);

  void addLocked(Tetriminos::tetrimino piece, int rotation, int nPosX,
                 int nPosY);

  int checkLines();

  int checkGameOver();
};

#endif
