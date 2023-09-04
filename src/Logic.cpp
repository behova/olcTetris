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

double Logic::getDelayTime(int currentLevel) {

  double time = (0.8 - ((currentLevel - 1) * 0.007));
  int i;
  int exponent = ((currentLevel - 1));

  double exponentialTime = time;
  for (i = 0; i < exponent; i++) {
    exponentialTime = time * exponentialTime;
  }

  return exponentialTime;
}