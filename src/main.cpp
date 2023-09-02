
#include "Board.h"
#include "Graphics.h"
#include "Logic.h"
#include "Tetrominos.h"
#include "olcPixelGameEngine.h"
#include <cstdio>
#include <iostream>
#include <string>

class Engine : public olc::PixelGameEngine {
public:
  Engine() { sAppName = "Tetris"; };

private:
  int rows, columns;
  int cellW, cellH;
  int stX, stY;
  int gameOver;
  int score;
  int level;
  int lines;
  Tetriminos::tetrimino nextPiece;
  Tetriminos::tetrimino currentPiece;
  int currentRotation;
  int currentX;
  int currentY;
  int pieceLocked;
  double delayTime;
  double fAccumulatedTime;
  int pause;
  int input;

public:
  bool OnUserCreate() override {
    // Called once at the start, so create things here

    // set rows and columns
    rows = 26;
    columns = 11;
    // set block width/height
    cellW = 8;
    cellH = 8;
    // set x/y for drawing the board
    stX = ScreenWidth() / 2 - ((cellW * 11));
    stY = ScreenHeight() / 2 - ((cellH * 26) / 2);
    // gameOver global
    gameOver = 0;
    // score global
    score = 0;
    level = 8;
    lines = 0;
    // info for drawing pieces
    nextPiece = tetriminos.getRandomTetrimino();
    currentPiece = tetriminos.getRandomTetrimino();
    currentRotation = 0;
    // current x/y of piece based on gameboard grid
    currentX = 3;
    currentY = 0;
    // when piece is locked it's added to locked array
    pieceLocked = 0;
    // delay will decrease as time goes on. checked against fElaspedTime
    delayTime = logic.getDelayTime(level);
    // acumulate fElapsed time
    fAccumulatedTime = 0;
    // Pause check
    pause = 0;
    // user input
    input = 0;

    UI.setUI(rows, columns, stX, stY, cellW, cellH);

    // seed srand
    srand(time(NULL));

    // add initial piece
    gameBoard.addPiece(currentPiece, currentRotation, currentX, currentY);

    return true;
  }

  bool OnUserUpdate(float fElapsedTime) override

  /* start game loop*/
  {
    // calculate time interval
    fAccumulatedTime += fElapsedTime;

    // reset input
    input = 0;

    /*pause game loop*/
    if (pause == 1) {
      gameBoard.resetBoard();

      gameBoard.addPiece(currentPiece, currentRotation, currentX, currentY);

      UI.drawBoard(this, &gameBoard.currentBoard);

      UI.drawPause(this, score, level, lines);

      if (GetKey(olc::SPACE).bPressed) {
        pause = 0;
        for (int x = 0; x < ScreenWidth(); x++) {
          for (int y = 0; y < ScreenHeight(); y++) {
            Draw(x, y, olc::Pixel(0, 0, 0));
          }
        }
      }

    }
    /*Game over screen*/
    else if (gameOver == 1) {
      UI.drawBoard(this, &gameBoard.currentBoard);

      UI.drawGameOver(this, score, level, lines);

    }
    /*main game loop*/
    else {

      /* Handle user input*/
      if (GetKey(olc::ESCAPE).bPressed) {
        pause = 1;
      }
      if (GetKey(olc::LEFT).bPressed) {
        input = 1;
      }
      if (GetKey(olc::UP).bPressed) {
        input = 2;
      }
      if (GetKey(olc::RIGHT).bPressed) {
        input = 3;
      }
      if (GetKey(olc::DOWN).bPressed) {
        input = 4;
      }
      if (GetKey(olc::F1).bPressed) {
        input = 5;
      }
      // only one move can be made per frame
      if (pieceLocked == 0) {
        switch (input) {
        case 1:
          if (gameBoard.checkCollision(currentPiece, currentRotation,
                                       currentX - 1, currentY) == 0) {
            currentX -= 1;
            break;
          } else {
            break;
          }
        case 2:
          if (gameBoard.checkCollision(currentPiece, currentRotation + 1,
                                       currentX, currentY) == 0) {
            currentRotation += 1;
            break;
          } else {
            break;
          }
        case 3:
          if (gameBoard.checkCollision(currentPiece, currentRotation,
                                       currentX + 1, currentY) == 0) {
            currentX += 1;
            break;
          } else {
            break;
          }
        case 4:
          if (gameBoard.checkCollision(currentPiece, currentRotation, currentX,
                                       currentY + 1) == 0) {
            currentY += 1;
            break;
          } else {
            break;
          }
        case 5:
          level += 1;
          delayTime = logic.getDelayTime(level);
          break;
        default:
          break;
        }
      }

      /* Catch all collision check*/
      if (pieceLocked == 0) {
        pieceLocked = gameBoard.checkCollision(currentPiece, currentRotation,
                                               currentX, currentY);
      }

      /*If piece is locked reset tetrimino variables and switch to next piece*/
      if (pieceLocked == 1) {
        gameBoard.addLocked(currentPiece, currentRotation, currentX, currentY);

        // increase score for piece lock(check last key press to see if
        // hardlock. check current peice for amount scored)

        // reset y x and piecelock
        currentRotation = 0;
        currentY = 0;
        currentX = 3;
        pieceLocked = 0;

        // set the next tetrimino
        currentPiece = nextPiece;
        nextPiece = tetriminos.getRandomTetrimino();

        // check for row match
        lines += gameBoard.checkLines();

        // increase level for line accumulation
        if (logic.getLevel(level, lines) == true) {
          level += 1;
          lines = 0;
          delayTime = logic.getDelayTime(level);
        }

        // check for gameOver
        gameOver = gameBoard.checkGameOver();
      }

      /* Main draw loop*/
      if (pieceLocked == 0) {

        for (int x = 0; x < ScreenWidth(); x++) {
          for (int y = 0; y < ScreenHeight(); y++) {
            Draw(x, y, olc::Pixel(0, 0, 0));
          }
        }

        gameBoard.resetBoard();

        gameBoard.addPiece(currentPiece, currentRotation, currentX, currentY);

        UI.drawBoard(this, &gameBoard.currentBoard);

        UI.drawUI(this, score, level, lines, nextPiece);
      }

      /*Advance tetrimino on time interval*/
      if (fAccumulatedTime >= delayTime) {

        if (gameBoard.checkCollision(currentPiece, currentRotation, currentX,
                                     currentY + 1) == 0) {

          currentY += 1;

        } else {
          pieceLocked = 1;
        }

        // reset accumulated time
        fAccumulatedTime = 0;

        // score += 1;
      }
    }

    return true;
  }

protected:
  Board gameBoard;
  Tetriminos tetriminos;
  Logic logic;
  Graphics UI;
};

int main() {
  Engine window;
  // Construct ScreenWidth, ScreenHeight, pixelW, pixelH
  if (window.Construct(256, 240, 4, 4))
    window.Start();

  return 0;
}
