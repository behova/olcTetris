
// main gameboard class
#include "Board.h"
#include "Tetrominos.h"
#include "olcPixelGameEngine.h"
#include <string>

Board::Board() {
  rows = 26;
  columns = 11;
  int i, j;

  // initialize currentBoard
  for (i = 0; i < rows; i++) {
    for (j = 0; j < columns; j++) {
      if (j == 0 || j == columns - 1) {
        currentBoard[i][j] = 9;
      } else if (i == rows - 1) {
        currentBoard[i][j] = 9;
      } else {
        currentBoard[i][j] = 0;
      }
    }
  }

  // initialized locked board
  for (i = 0; i < rows; i++) {
    for (j = 0; j < columns; j++) {
      if (j == 0 || j == columns - 1) {
        lockedBoard[i][j] = 9;
      } else if (i == rows - 1) {
        lockedBoard[i][j] = 9;
      } else {
        lockedBoard[i][j] = 0;
      }
    }
  }
};

int Board::getMinoIndex(int px, int py, int rotation) {

  switch (rotation % 4) {
  case 0:
    return py * 4 + px; // 0 degrees
  case 1:
    return 12 + py - (px * 4); // 90 degrees
  case 2:
    return 15 - (py * 4) - px; // 180 degrees
  case 3:
    return 3 - py + (px * 4); // 270 degrees
  }
  return 0;
}

void Board::resetBoard() {
  int i, j;
  for (i = 0; i < rows; i++) {
    for (j = 0; j < columns; j++) {
      if (currentBoard[i][j] != lockedBoard[i][j]) {
        currentBoard[i][j] = lockedBoard[i][j];
      }
    }
  }
}

int Board::checkCollision(Tetriminos::tetrimino piece, int rotation, int nPosX,
                          int nPosY) {
  int px, py;
  for (int px = 0; px < 4; px++) {
    for (int py = 0; py < 4; py++) {

      // get index into piece
      int pi = getMinoIndex(px, py, rotation);

      // get index into field
      int fx = (nPosX + px);
      int fy = (nPosY + py);

      // check bounds of array
      if (nPosX + px >= 0 && nPosX + px < 11) {
        if (nPosY + py >= 0 && nPosY + py < 26) {
          if (piece.block[pi] > 0 && lockedBoard[fy][fx] != 0) {
            return 1;
          }
        }
      }
    }
  }
  return 0;
}

void Board::addPiece(Tetriminos::tetrimino piece, int rotation, int nPosX,
                     int nPosY) {
  int px, py;
  for (int px = 0; px < 4; px++) {
    for (int py = 0; py < 4; py++) {

      // get index into piece
      int pi = getMinoIndex(px, py, rotation);

      // get index into field
      int fx = (nPosX + px);
      int fy = (nPosY + py);

      // check bounds of array
      if (nPosX + px >= 0 && nPosX + px < columns) {
        if (nPosY + py >= 0 && nPosY + py < rows) {
          // overwrite currentBoard with piece value if !=0
          if (piece.block[pi] != 0) {
            currentBoard[fy][fx] = piece.block[pi];
          }
        }
      }
    }
  }
}

void Board::addLocked(Tetriminos::tetrimino piece, int rotation, int nPosX,
                      int nPosY) {
  int px, py;
  for (int px = 0; px < 4; px++) {
    for (int py = 0; py < 4; py++) {

      // get index into piece
      int pi = getMinoIndex(px, py, rotation);

      // get index into field
      int fx = (nPosX + px);
      int fy = (nPosY + py);

      // check bounds of array
      if (nPosX + px >= 0 && nPosX + px < columns) {
        if (nPosY + py >= 0 && nPosY + py < rows) {
          // overwrite lockedBoard with piece value if !=0
          if (piece.block[pi] != 0) {
            lockedBoard[fy][fx] = piece.block[pi];
          }
        }
      }
    }
  }
}

int Board::checkLines() {
  int i, j, k, l, m;
  int matchedRows = 0;
  int rowValue = 0;

  for (i = 0; i < rows; i++) {
    for (j = 0; j < columns; j++) {
      if (lockedBoard[i][j] > 0 && lockedBoard[i][j] != 9) {
        rowValue += 1;
      }
    }
    // indexing out of bounds?
    if (rowValue == 9) {
      for (k = 0; k < columns; k++) {
        if (lockedBoard[i][k] != 9) {
          lockedBoard[i][k] = 0;
        }
      }
      for (l = i; l > 3; l--) {
        for (m = 0; m < columns; m++) {
          if (l > 2 && lockedBoard[l][m] != 9) {
            lockedBoard[l][m] = lockedBoard[l - 1][m];
          }
        }
      }

      matchedRows += 1;
    }
    rowValue = 0;
  }
  return matchedRows;
}

int Board::checkGameOver() {
  int i, j;
  int gameOver;

  for (i = 0; i < rows; i++) {
    for (j = 0; j < columns; j++) {
      if (i == 0 || i == 1) {
        if (lockedBoard[i][j] > 0 && lockedBoard[i][j] != 9) {
          gameOver = 1;
        }
      }
    }
  }
  return gameOver;
}