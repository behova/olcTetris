// game logic that doesn't fit in loop
#include "Logic.h"

int Logic::checkLevelIncrease(int currentLevel, int currentLines) {
  bool levelIncrease = false;

  switch (currentLevel) {
  case 0:
    if (currentLines >= 10) {
      levelIncrease = true;
    }
    break;
  case 1:
    if (currentLines >= 30) {
      levelIncrease = true;
    }
    break;
  case 2:
    if (currentLines >= 60) {
      levelIncrease = true;
    }
    break;
  case 3:
    if (currentLines >= 100) {
      levelIncrease = true;
    }
    break;
  case 4:
    if (currentLines >= 150) {
      levelIncrease = true;
    }
    break;
  case 5:
    if (currentLines >= 210) {
      levelIncrease = true;
    }
    break;
  case 6:
    if (currentLines >= 280) {
      levelIncrease = true;
    }
    break;
  case 7:
    if (currentLines >= 360) {
      levelIncrease = true;
    }
    break;
  case 8:
    if (currentLines >= 450) {
      levelIncrease = true;
    }
    break;
  case 9:
    if (currentLines >= 550) {
      levelIncrease = true;
    }
    break;
  case 10:
    if (currentLines >= 650) {
      levelIncrease = true;
    }
    break;
  case 11:
    if (currentLines >= 750) {
      levelIncrease = true;
    }
    break;
  case 12:
    if (currentLines >= 850) {
      levelIncrease = true;
    }
    break;
  case 13:
    if (currentLines >= 950) {
      levelIncrease = true;
    }
    break;
  case 14:
    if (currentLines >= 1050) {
      levelIncrease = true;
    }
    break;
  case 15:
    if (currentLines >= 1150) {
      levelIncrease = true;
    }
    break;
  case 16:
    if (currentLines >= 1260) {
      levelIncrease = true;
    }
    break;
  case 17:
    if (currentLines >= 1380) {
      levelIncrease = true;
    }
    break;
  case 18:
    if (currentLines >= 1500) {
      levelIncrease = true;
    }
    break;
  case 19:
    if (currentLines >= 1640) {
      levelIncrease = true;
    }
    break;
  case 20:
    if (currentLines >= 1790) {
      levelIncrease = true;
    }
    break;
  default:
    levelIncrease = false;
    break;
  }
  return levelIncrease;
}

double Logic::getDropTime(int currentLevel) {
  double fps = 60.0;
  double fpr;
  double time;
  switch (currentLevel) {
  case 0:
    fpr = 53;
    break;
  case 1:
    fpr = 49;
    break;
  case 2:
    fpr = 45;
    break;
  case 3:
    fpr = 41;
    break;
  case 4:
    fpr = 37;
    break;
  case 5:
    fpr = 33;
    break;
  case 6:
    fpr = 28;
    break;
  case 7:
    fpr = 22;
    break;
  case 8:
    fpr = 17;
    break;
  case 9:
    fpr = 11;
    break;
  case 10:
    fpr = 10;
    break;
  case 11:
    fpr = 9;
    break;
  case 12:
    fpr = 8;
    break;
  case 13:
    fpr = 7;
    break;
  case 14:
    fpr = 6;
    break;
  case 15:
    fpr = 6;
    break;
  case 16:
    fpr = 5;
    break;
  case 17:
    fpr = 5;
    break;
  case 18:
    fpr = 4;
    break;
  case 19:
    fpr = 4;
    break;
  case 20:
    fpr = 3;
    break;
  default:
    fpr = 3;
    break;
  }
  // get frames spent per row as a percentage of frames per second
  time = (fpr / fps);

  return time;
}

double Logic::getSoftDropTime(int currentLevel) {
  double fps = 60.0;
  double fpr;
  double time;
  double drop = .1;
  switch (currentLevel) {
  case 0:
    fpr = 53;
    break;
  case 1:
    fpr = 49;
    break;
  case 2:
    fpr = 45;
    break;
  case 3:
    fpr = 41;
    break;
  case 4:
    fpr = 37;
    break;
  case 5:
    fpr = 33;
    break;
  case 6:
    fpr = 28;
    break;
  case 7:
    fpr = 22;
    break;
  case 8:
    fpr = 17;
    break;
  case 9:
    fpr = 11;
    break;
  case 10:
    fpr = 10;
    break;
  case 11:
    fpr = 9;
    break;
  case 12:
    fpr = 8;
    break;
  case 13:
    fpr = 7;
    break;
  case 14:
    fpr = 6;
    break;
  case 15:
    fpr = 6;
    break;
  case 16:
    fpr = 5;
    break;
  case 17:
    fpr = 5;
    break;
  case 18:
    fpr = 4;
    break;
  case 19:
    fpr = 4;
    break;
  case 20:
    fpr = 3;
    break;
  default:
    fpr = 3;
    break;
  }
  // get frames spent per row as a percentage of frames per second
  time = (fpr / fps) * drop;

  return time;
}