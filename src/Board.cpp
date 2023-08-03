
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
}

void Board::draw(olc::PixelGameEngine *pge, int stX, int stY, int pxW,
                 int pxH) {

  /* draw main tetrimino field*/
  int i, j;
  for (i = 0; i < rows; i++) {
    for (j = 0; j < columns; j++) {

      int value = currentBoard[i][j];
      switch (value) {
      case 0:
        pge->FillRect((j * pxW) + stX, (i * pxH) + stY - (pxH * 2), pxW, pxH,
                      olc::BLANK);
        // pge->DrawRect((j * pxW) + stX,(i * pxH) + stY - (pxH * 2), pxW, pxH,
        // olc::WHITE);
        break;
      // O
      case 1:
        pge->FillRect(j * pxW + stX, i * pxH + stY - (pxH * 2), pxW, pxH,
                      olc::YELLOW);
        pge->DrawRect(j * pxW + stX, i * pxH + stY - (pxH * 2), pxW, pxH,
                      olc::DARK_YELLOW);
        break;
      // I
      case 2:
        pge->FillRect(j * pxW + stX, i * pxH + stY - (pxH * 2), pxW, pxH,
                      olc::CYAN);
        pge->DrawRect(j * pxW + stX, i * pxH + stY - (pxH * 2), pxW, pxH,
                      olc::DARK_CYAN);
        break;
      // S
      case 3:
        pge->FillRect(j * pxW + stX, i * pxH + stY - (pxH * 2), pxW, pxH,
                      olc::GREEN);
        pge->DrawRect(j * pxW + stX, i * pxH + stY - (pxH * 2), pxW, pxH,
                      olc::DARK_GREEN);
        break;
      // Z
      case 4:
        pge->FillRect(j * pxW + stX, i * pxH + stY - (pxH * 2), pxW, pxH,
                      olc::RED);
        pge->DrawRect(j * pxW + stX, i * pxH + stY - (pxH * 2), pxW, pxH,
                      olc::DARK_RED);
        break;
      // L
      case 5:
        pge->FillRect(j * pxW + stX, i * pxH + stY - (pxH * 2), pxW, pxH,
                      olc::Pixel(245, 122, 7));
        pge->DrawRect(j * pxW + stX, i * pxH + stY - (pxH * 2), pxW, pxH,
                      olc::Pixel(166, 82, 3));
        break;
      // J
      case 6:
        pge->FillRect(j * pxW + stX, i * pxH + stY - (pxH * 2), pxW, pxH,
                      olc::BLUE);
        pge->DrawRect(j * pxW + stX, i * pxH + stY - (pxH * 2), pxW, pxH,
                      olc::DARK_BLUE);
        break;
      // T
      case 7:
        pge->FillRect(j * pxW + stX, i * pxH + stY - (pxH * 2), pxW, pxH,
                      olc::MAGENTA);
        pge->DrawRect(j * pxW + stX, i * pxH + stY - (pxH * 2), pxW, pxH,
                      olc::DARK_MAGENTA);
        break;
      case 9:
        pge->DrawRect(j * pxW + stX, i * pxH + stY - (pxH * 2), pxW, pxH,
                      olc::GREY);
        break;
      default:
        pge->FillRect((j * pxW) + stX, (i * pxH) + stY - (pxH * 2), pxW, pxH,
                      olc::BLANK);
        pge->DrawRect((j * pxW) + stX, (i * pxH) + stY - (pxH * 2), pxW, pxH,
                      olc::WHITE);
        break;
      }
    }
  }
}

void Board::drawUI(olc::PixelGameEngine *pge, int stX, int stY, int pxW,
                   int pxH, int score, int level, int lines,
                   Tetriminos::tetrimino nextPiece) {

  /*draw UI box*/
  pge->DrawRect(stX + (pxW * columns), stY, pxW * 9, pxH * rows - (pxH * 2));

  /*draw Score box*/
  pge->DrawRect(stX + (pxW * columns) + (pxW * 1), stY + (pxH * 1), pxW * 7,
                pxH * 2, olc::GREEN);
  pge->DrawString((stX + (pxW * columns) + (pxW * 1)) + (pxW),
                  (stY + (pxH * 1)) + (pxH / 2), "SCORE", olc::MAGENTA);

  pge->DrawRect(stX + (pxW * columns), stY + (pxH * 2), pxW * 9, pxH * 3,
                olc::YELLOW);
  pge->DrawString((stX + (pxW * columns)) + (pxW),
                  (stY + (pxH * 3)) + (pxH / 2), std::to_string(score),
                  olc::MAGENTA);

  /*draw level box*/
  pge->DrawRect(stX + (pxW * columns) + (pxW), stY + (pxH * 6), pxW * 7,
                pxH * 4, olc::BLUE);
  pge->DrawString(stX + (pxW * columns) + (pxW * 2), stY + (pxH * 6) + (pxH),
                  "LEVEL", olc::MAGENTA);
  pge->DrawString(stX + (pxW * columns) + (pxW * 2),
                  stY + (pxH * 6) + (pxH * 2 + pxH / 2), std::to_string(level),
                  olc::MAGENTA);

  /*draw lines box*/
  pge->DrawRect(stX + (pxW * columns) + (pxW), stY + (pxH * 11), pxW * 7,
                pxH * 4, olc::CYAN);
  pge->DrawString(stX + (pxW * columns) + (pxW * 2), stY + (pxH * 11) + (pxH),
                  "LINES", olc::MAGENTA);
  pge->DrawString(stX + (pxW * columns) + (pxW * 2),
                  stY + (pxH * 11) + (pxH * 2 + pxH / 2), std::to_string(lines),
                  olc::MAGENTA);

  /*draw next piece box*/
  int pieceRows = 4;
  int pieceColumns = 4;

  pge->DrawRect(stX + (pxW * columns) + (pxW * 2), stY + (pxH * (rows - 9)),
                pxW * 6, pxH * 6, olc::RED);

  int i, j;
  for (i = 0; i < pieceRows; i++) {
    for (j = 0; j < pieceColumns; j++) {
      int value = nextPiece.block[(i * pieceColumns + j)];
      switch (value) {
      case 0:
        pge->FillRect((j * pxW) + stX + (pxW * columns) + (pxW * 3),
                      (i * pxH) + stY + (pxH * (rows - 8)), pxW, pxH,
                      olc::BLANK);
        // pge->DrawRect((j * pxW) + stX + (pxW * columns)+ (pxW * 3),(i * pxH)
        // + stY + (pxH * (rows - 8)), pxW, pxH, olc::WHITE);
        break;
      // O
      case 1:
        pge->FillRect((j * pxW) + stX + (pxW * columns) + (pxW * 3),
                      (i * pxH) + stY + (pxH * (rows - 8)), pxW, pxH,
                      olc::YELLOW);
        pge->DrawRect((j * pxW) + stX + (pxW * columns) + (pxW * 3),
                      (i * pxH) + stY + (pxH * (rows - 8)), pxW, pxH,
                      olc::DARK_YELLOW);
        break;
      // I
      case 2:
        pge->FillRect((j * pxW) + stX + (pxW * columns) + (pxW * 3),
                      (i * pxH) + stY + (pxH * (rows - 8)), pxW, pxH,
                      olc::CYAN);
        pge->DrawRect((j * pxW) + stX + (pxW * columns) + (pxW * 3),
                      (i * pxH) + stY + (pxH * (rows - 8)), pxW, pxH,
                      olc::DARK_CYAN);
        break;
      // S
      case 3:
        pge->FillRect((j * pxW) + stX + (pxW * columns) + (pxW * 3),
                      (i * pxH) + stY + (pxH * (rows - 8)), pxW, pxH,
                      olc::GREEN);
        pge->DrawRect((j * pxW) + stX + (pxW * columns) + (pxW * 3),
                      (i * pxH) + stY + (pxH * (rows - 8)), pxW, pxH,
                      olc::DARK_GREEN);
        break;
      // Z
      case 4:
        pge->FillRect((j * pxW) + stX + (pxW * columns) + (pxW * 3),
                      (i * pxH) + stY + (pxH * (rows - 8)), pxW, pxH, olc::RED);
        pge->DrawRect((j * pxW) + stX + (pxW * columns) + (pxW * 3),
                      (i * pxH) + stY + (pxH * (rows - 8)), pxW, pxH,
                      olc::DARK_RED);
        break;
      // L
      case 5:
        pge->FillRect((j * pxW) + stX + (pxW * columns) + (pxW * 3),
                      (i * pxH) + stY + (pxH * (rows - 8)), pxW, pxH,
                      olc::Pixel(245, 122, 7));
        pge->DrawRect((j * pxW) + stX + (pxW * columns) + (pxW * 3),
                      (i * pxH) + stY + (pxH * (rows - 8)), pxW, pxH,
                      olc::Pixel(166, 82, 3));
        break;
      // J
      case 6:
        pge->FillRect((j * pxW) + stX + (pxW * columns) + (pxW * 3),
                      (i * pxH) + stY + (pxH * (rows - 8)), pxW, pxH,
                      olc::BLUE);
        pge->DrawRect((j * pxW) + stX + (pxW * columns) + (pxW * 3),
                      (i * pxH) + stY + (pxH * (rows - 8)), pxW, pxH,
                      olc::DARK_BLUE);
        break;
      // T
      case 7:
        pge->FillRect((j * pxW) + stX + (pxW * columns) + (pxW * 3),
                      (i * pxH) + stY + (pxH * (rows - 8)), pxW, pxH,
                      olc::MAGENTA);
        pge->DrawRect((j * pxW) + stX + (pxW * columns) + (pxW * 3),
                      (i * pxH) + stY + (pxH * (rows - 8)), pxW, pxH,
                      olc::DARK_MAGENTA);
        break;
      case 9:
        pge->DrawRect((j * pxW) + stX + (pxW * columns) + (pxW * 3),
                      (i * pxH) + stY + (pxH * (rows - 8)), pxW, pxH,
                      olc::DARK_YELLOW);
        break;
      default:
        pge->FillRect((j * pxW) + stX + (pxW * columns) + (pxW * 3),
                      (i * pxH) + stY + (pxH * (rows - 8)), pxW, pxH,
                      olc::BLANK);
        pge->DrawRect((j * pxW) + stX + (pxW * columns) + (pxW * 3),
                      (i * pxH) + stY + (pxH * (rows - 8)), pxW, pxH,
                      olc::WHITE);
        break;
      }
    }
  }
}

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