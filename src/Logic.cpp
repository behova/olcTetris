// game logic that doesn't fit in loop
#include "Logic.h"

int Logic::getLevel(int currentLevel, int currentLines) {
  bool levelIncrease;

  if (currentLevel <= 8 && currentLines >= (currentLevel * 10) + 10) {
    levelIncrease = true;
  } else if (currentLevel <= 15 && currentLevel > 8 && currentLines >= 100) {
    levelIncrease = true;
  } else if (currentLevel <= 24 && currentLevel > 15 &&
             currentLines >= (currentLevel * 10) - 50) {
    levelIncrease = true;
  } else if (currentLevel <= 28 && currentLevel > 24 && currentLines >= 200) {
    levelIncrease = true;
  } else {
    levelIncrease = false;
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