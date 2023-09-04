
#include "Board.h"
#include "Graphics.h"
#include "Logic.h"
#include "Tetrominos.h"
#include "olcPixelGameEngine.h"
#include <cstdio>
#include <iostream>
#include <ostream>
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
  int pieceLock;
  double delayTime;
  double fAccumulatedTime;
  double fMoveTime;
  double fLatchTime;
  int pause;
  int input;

public:
  void mainDrawLoop() {
    if (pieceLock == 0) {

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
  }
  void collisionCheck() {
    if (pieceLock == 0) {
      pieceLock = gameBoard.checkCollision(currentPiece, currentRotation,
                                           currentX, currentY);
    }
  }
  void pieceLocked() {
    if (pieceLock == 1) {
      gameBoard.addLocked(currentPiece, currentRotation, currentX, currentY);

      // increase score for piece lock(check last key press to see if
      // hardlock. check current peice for amount scored)

      // reset y x and piecelock
      currentRotation = 0;
      currentY = 0;
      currentX = 3;
      pieceLock = 0;

      // set the next tetrimino
      currentPiece = nextPiece;
      nextPiece = tetriminos.getRandomTetrimino();

      // check for row match
      lines += gameBoard.checkLines();

      // increase level for line accumulation
      if (logic.checkLevelIncrease(level, lines) == true) {
        level += 1;
        delayTime = logic.getDelayTime(level);
      }

      // check for gameOver
      gameOver = gameBoard.checkGameOver();
    }
  }
  void advanceRow() {
    if (fAccumulatedTime >= delayTime) {

      if (gameBoard.checkCollision(currentPiece, currentRotation, currentX,
                                   currentY + 1) == 0) {

        currentY += 1;

      } else {
        pieceLock = 1;
      }

      // reset accumulated time
      fAccumulatedTime = 0;

      // score += 1;
    }
  }
  void pauseLoop() {

    gameBoard.resetBoard();

    gameBoard.addPiece(currentPiece, currentRotation, currentX, currentY);

    UI.drawBoard(this, &gameBoard.currentBoard);

    UI.drawPause(this, score, level, lines);

    if (GetKey(olc::ESCAPE).bPressed) {
      pause = 0;
    }
  }
  void gameOverLoop() {

    UI.drawBoard(this, &gameBoard.currentBoard);

    UI.drawGameOver(this, score, level, lines);
  }
  bool OnUserCreate() override {
    // Called once at the start
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
    level = 0;
    lines = 0;
    // info for drawing pieces
    nextPiece = tetriminos.getRandomTetrimino();
    currentPiece = tetriminos.getRandomTetrimino();
    currentRotation = 0;
    // current x/y of piece based on gameboard grid
    currentX = 3;
    currentY = 0;
    // when piece is locked it's added to locked array
    pieceLock = 0;
    // delay will decrease as time goes on. checked against fElaspedTime
    delayTime = logic.getDelayTime(level);
    // acumulate fElapsed time
    fAccumulatedTime = 0.0;
    // acumulate time before move
    fMoveTime = 0.0;
    // latchTime for single button press
    fLatchTime = 0.0;
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
    fMoveTime += fElapsedTime;
    fLatchTime -= fElapsedTime;
    if (fLatchTime <= 0.0) {
      fLatchTime = 0.0;
    }

    /*main game loop*/
    /* Handle Pause input*/

    if (pause == 1) {
      /*pause game loop*/
      pauseLoop();
    } else if (gameOver == 1) {
      /*Game over screen*/
      gameOverLoop();
    } else if (fMoveTime >= .07 && fLatchTime <= 0.0) {
      if (GetKey(olc::LEFT).bHeld) {
        if (gameBoard.checkCollision(currentPiece, currentRotation,
                                     currentX - 1, currentY) == 0) {
          currentX -= 1;
        }
      }
      if (GetKey(olc::UP).bHeld) {
        if (gameBoard.checkCollision(currentPiece, currentRotation + 1,
                                     currentX, currentY) == 0) {
          currentRotation += 1;
        }
      }
      if (GetKey(olc::RIGHT).bHeld) {
        if (gameBoard.checkCollision(currentPiece, currentRotation,
                                     currentX + 1, currentY) == 0) {
          currentX += 1;
        }
      }
      if (GetKey(olc::DOWN).bHeld) {
        if (gameBoard.checkCollision(currentPiece, currentRotation, currentX,
                                     currentY + 1) == 0) {
          currentY += 1;
        }
        // todo: change gravity here
      }

      /* Catch all collision check*/
      collisionCheck();

      /*If piece is locked reset tetrimino variables and switch to next
       * piece*/
      pieceLocked();

      // reset move delay
      fMoveTime = 0;
    } else {
      if (GetKey(olc::F1).bPressed) {
        level += 1;
        delayTime = logic.getDelayTime(level);
      }
      if (GetKey(olc::ESCAPE).bPressed) {
        pause = 1;
      }
      if (GetKey(olc::LEFT).bPressed) {
        if (gameBoard.checkCollision(currentPiece, currentRotation,
                                     currentX - 1, currentY) == 0) {
          currentX -= 1;
          fLatchTime = .1;
        }
      }
      if (GetKey(olc::UP).bPressed) {
        if (gameBoard.checkCollision(currentPiece, currentRotation + 1,
                                     currentX, currentY) == 0) {
          currentRotation += 1;
          fLatchTime = .18;
        }
      }
      if (GetKey(olc::RIGHT).bPressed) {
        if (gameBoard.checkCollision(currentPiece, currentRotation,
                                     currentX + 1, currentY) == 0) {
          currentX += 1;
          fLatchTime = .1;
        }
      }
      if (GetKey(olc::DOWN).bPressed) {
        if (gameBoard.checkCollision(currentPiece, currentRotation, currentX,
                                     currentY + 1) == 0) {
          currentY += 1;
          fLatchTime = .1;
        }
      }

      /* Catch all collision check*/
      collisionCheck();

      /*If piece is locked reset tetrimino variables and switch to next
       * piece*/
      pieceLocked();
    }

    if (pause == 0) {
      /* Main draw loop*/
      mainDrawLoop();
      /*Advance tetrimino on time interval*/
      advanceRow();
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
