#ifndef GAME_H
#define GAME_H (1)

class Game
{
 public:
  Game() {}
  ~Game() {}

  inline void roll(int pins) {
   rolls_[currentRoll_++] = pins; 
  }
  int score();

 private:
  constexpr bool isSpare(int frameIndex) {
    return rolls_[frameIndex] + rolls_[frameIndex + 1] == 10; 
  }
  constexpr int strikeBonus(int frameIndex) {
    return rolls_[frameIndex + 1] + rolls_[frameIndex + 2];
  }
  constexpr int spareBonus(int frameIndex) {
    return rolls_[frameIndex + 2];
  }
  constexpr int sumOfBallsInFrame(int frameIndex) {
    return rolls_[frameIndex] + rolls_[frameIndex + 1];
  }
  constexpr bool isStrike(int frameIndex) {
    return rolls_[frameIndex] == 10;
  }
  
 private:
  int rolls_[21] = {0};
  int currentRoll_ = 0;
};


#endif /* GAME_H */
