
#include "Tetrominos.h"
#include <cstdlib>
#include <variant>

Tetriminos::Tetriminos() { bag = charTetriminos; }

Tetriminos::tetrimino Tetriminos::getVecRandomTetrimino() {
  int randBagAdress;
  char firstChoice;
  char finalChoice;
  int returnValue;

  // check if bag is empty
  if (bag.size() <= 0) {
    bag = charTetriminos;
  }

  // seed rand
  srand(time(NULL));

  // set to random address based on bag size
  randBagAdress = (rand() % bag.size());
  firstChoice = bag.at(randBagAdress);

  // check for repeat else re-roll once
  if (firstChoice != lastTetrimino) {

    // set final and last tetrimino
    finalChoice = firstChoice;

    // swap and pop it if no repeat
    std::swap(bag[randBagAdress], bag.back());
    bag.pop_back();

  } else {
    // re-seed rand
    srand(time(NULL));

    // set final choice directly
    randBagAdress = (rand() % bag.size());
    finalChoice = bag.at(randBagAdress);

    // swap and pop it
    std::swap(bag[randBagAdress], bag.back());
    bag.pop_back();
  }
  // set tetrimino history
  lastTetrimino = finalChoice;

  // convert final choice char to tetrimino array.
  switch (finalChoice) {
  case 'O':
    returnValue = 0;
    break;
  case 'I':
    returnValue = 1;
    break;
  case 'S':
    returnValue = 2;
    break;
  case 'Z':
    returnValue = 3;
    break;
  case 'L':
    returnValue = 4;
    break;
  case 'J':
    returnValue = 5;
    break;
  case 'T':
    returnValue = 6;
    break;
  default:
    returnValue = 0;
    break;
  }

  return vecTetriminos[returnValue];
}