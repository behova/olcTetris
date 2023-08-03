#ifndef LOGIC_H_
#define LOGIC_H_

// game logic that doesn't fit in loop
class Logic {
public:
  int level;

public:
  int getLevel(int currentLevel, int currentLines);
  int getTimeInterval(int currentLevel);
  int getScore();
};

#endif