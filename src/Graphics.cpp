// main gameboard class
#include "Graphics.h"
#include "Tetrominos.h"
#include "olcPixelGameEngine.h"
#include <string>

void Graphics::setUI(int rows, int columns, int stX, int stY, int pxW,
                     int pxH) {
  this->rows = rows;
  this->columns = columns;
  this->stX = stX;
  this->stY = stY;
  this->pxW = pxW;
  this->pxH = pxH;
}

void Graphics::drawBoard(olc::PixelGameEngine *pge,
                         int (*currentBoard)[26][11]) {

  /* draw main tetrimino field*/
  int i, j;
  for (i = 0; i < rows; i++) {
    for (j = 0; j < columns; j++) {

      int value = (*currentBoard)[i][j];
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

void Graphics::drawUI(olc::PixelGameEngine *pge, int score, int level,
                      int lines, Tetriminos::tetrimino nextPiece) {

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
/* Draw Game over in UI*/
void Graphics::drawGameOver(olc::PixelGameEngine *pge, int score, int level,
                            int lines) {
  /*draw UI box*/
  pge->FillRect(stX + (pxW * columns), stY, pxW * 9, pxH * rows - (pxH * 2),
                olc::BLACK);
  pge->DrawRect(stX + (pxW * columns), stY, pxW * 9, pxH * rows - (pxH * 2));

  pge->DrawRect(stX + (pxW * columns), stY + (pxH) + (pxH / 2), pxW * 9,
                pxH * 3, olc::GREEN);
  pge->DrawString((stX + (pxW * columns) + (pxW * 2) + (pxW / 2)),
                  (stY + (pxH * 2)), "GAME", olc::MAGENTA);
  pge->DrawString((stX + (pxW * columns) + (pxW * 2) + (pxW / 2)),
                  (stY + (pxH * 3)), "OVER", olc::MAGENTA);

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

  /*draw Score box*/
  pge->DrawRect(stX + (pxW * columns) + (pxW), stY + (pxH * 16), pxW * 7,
                pxH * 4, olc::CYAN);
  pge->DrawString(stX + (pxW * columns) + (pxW * 2), stY + (pxH * 16) + (pxH),
                  "SCORE", olc::MAGENTA);
  pge->DrawString(stX + (pxW * columns) + (pxW * 2),
                  stY + (pxH * 16) + (pxH * 2 + pxH / 2), std::to_string(score),
                  olc::MAGENTA);
}

void Graphics::drawPause(olc::PixelGameEngine *pge, int score, int level,
                         int lines) {
  /*draw UI box*/
  pge->FillRect(stX + (pxW * columns), stY, pxW * 9, pxH * rows - (pxH * 2),
                olc::BLACK);
  pge->DrawRect(stX + (pxW * columns), stY, pxW * 9, pxH * rows - (pxH * 2));

  pge->DrawRect(stX + (pxW * columns), stY + (pxH) + (pxH / 2), pxW * 9,
                pxH * 3, olc::GREEN);
  pge->DrawString((stX + (pxW * columns) + (pxW * 2) + (pxW / 2)),
                  (stY + (pxH * 2)), "GAME", olc::MAGENTA);
  pge->DrawString((stX + (pxW * columns) + (pxW) + (pxW / 2)),
                  (stY + (pxH * 3)), "PAUSED", olc::MAGENTA);

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

  /*draw Score box*/
  pge->DrawRect(stX + (pxW * columns) + (pxW), stY + (pxH * 16), pxW * 7,
                pxH * 4, olc::CYAN);
  pge->DrawString(stX + (pxW * columns) + (pxW * 2), stY + (pxH * 16) + (pxH),
                  "SCORE", olc::MAGENTA);
  pge->DrawString(stX + (pxW * columns) + (pxW * 2),
                  stY + (pxH * 16) + (pxH * 2 + pxH / 2), std::to_string(score),
                  olc::MAGENTA);
}