#include "game.h"

int Game::score() {
  int score = 0;
  int frameIndex = 0;
  for (int frame = 0; frame < 10; ++frame) {
    if (isStrike(frameIndex)) {
      score += 10 + strikeBonus(frameIndex);
      frameIndex++;
    } else  if (isSpare(frameIndex)) {
      score += 10 + spareBonus(frameIndex);
      frameIndex += 2;
    } else {
      score += sumOfBallsInFrame(frameIndex);
      frameIndex += 2;  
    }
  }
  return score;
}
