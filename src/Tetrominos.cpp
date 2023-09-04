
#include "Tetrominos.h"
#include <cstdlib>
#include <variant>

Tetriminos::Tetriminos() {
  bagOne = vecTetriminos;
  bagTwo = vecTetriminos;
}

Tetriminos::tetrimino Tetriminos::getVecRandomTetrimino() {
  srand(time(NULL));
  int rbagOneChoice;
  int rbagTwoChoice;
  int rbagChoice = rand() % 2;
  tetrimino finalChoice;

  // check if bags are empty and set random to bag size
  if (bagOne.size() > 0) {
    rbagOneChoice = rand() % (bagOne.size());
  } else {
    bagOne = vecTetriminos;
    rbagOneChoice = rand() % 6;
  }
  if (bagTwo.size() > 0) {
    rbagTwoChoice = rand() % (bagTwo.size());
  } else {
    bagTwo = vecTetriminos;
    rbagTwoChoice = rand() % 6;
  }
  // switch randomly chosen bag then return a random piece from the bag
  // then moves the choice to the back and pops it
  switch (rbagChoice) {
  case 0:
    finalChoice = bagOne.at(rbagOneChoice);
    std::swap(bagOne[rbagOneChoice], bagOne.back());
    bagOne.pop_back();
  case 1:
    finalChoice = bagTwo.at(rbagTwoChoice);
    std::swap(bagTwo[rbagOneChoice], bagTwo.back());
    bagTwo.pop_back();
  }
  return finalChoice;
}