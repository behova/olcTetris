
#include "Tetrominos.h"
#include <cstdlib>
#include <variant>

Tetriminos::Tetriminos() {
  bagOne = charTetriminos;
  bagTwo = charTetriminos;
}

Tetriminos::tetrimino Tetriminos::getVecRandomTetrimino() {
  srand(time(NULL));
  int rbagOneChoice;
  int rbagTwoChoice;
  int rbagChoice = rand() % 2;
  char firstChoice;
  char finalChoice;
  int returnValue;

  // check if bags are empty and set random to bag size
  if (bagOne.size() > 0) {
    rbagOneChoice = rand() % (bagOne.size());
  } else {
    bagOne = charTetriminos;
    rbagOneChoice = rand() % 6;
  }
  if (bagTwo.size() > 0) {
    rbagTwoChoice = rand() % (bagTwo.size());
  } else {
    bagTwo = charTetriminos;
    rbagTwoChoice = rand() % 6;
  }
  // switch randomly chosen bag
  switch (rbagChoice) {
  case 0:
    firstChoice = bagOne.at(rbagOneChoice);
    break;
  case 1:
    firstChoice = bagTwo.at(rbagTwoChoice);
    break;
  }
  // check for repeat else re-roll once
  if (firstChoice != lastTetrimino) {
    finalChoice = firstChoice;
    lastTetrimino = finalChoice;
    // swap and pop it if no repeat
    switch (rbagChoice) {
    case 0:
      std::swap(bagOne[rbagOneChoice], bagOne.back());
      bagOne.pop_back();
      break;
    case 1:
      std::swap(bagTwo[rbagOneChoice], bagTwo.back());
      bagTwo.pop_back();
      break;
    }

  } else {
    // check if bags are empty and set random to bag size
    if (bagOne.size() > 0) {
      rbagOneChoice = rand() % (bagOne.size());
    } else {
      bagOne = charTetriminos;
      rbagOneChoice = rand() % 6;
    }
    if (bagTwo.size() > 0) {
      rbagTwoChoice = rand() % (bagTwo.size());
    } else {
      bagTwo = charTetriminos;
      rbagTwoChoice = rand() % 6;
    }
    // switch randomly chosen bag, assign it to final choice, swap and pop it.
    switch (rbagChoice) {
    case 0:
      finalChoice = bagOne.at(rbagOneChoice);
      std::swap(bagOne[rbagOneChoice], bagOne.back());
      bagOne.pop_back();
      break;
    case 1:
      finalChoice = bagTwo.at(rbagTwoChoice);
      std::swap(bagTwo[rbagOneChoice], bagTwo.back());
      bagTwo.pop_back();
      break;
    }
  }
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

  return vecTetriminos.at(returnValue);
}