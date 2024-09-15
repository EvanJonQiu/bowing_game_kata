#include "game.h"

#include <gtest/gtest.h>

class GameTest : public testing::Test
{
 public:
  virtual void SetUp() {
    g = new Game();
  }
  virtual void TearDown() {
    delete g;
    g  = nullptr;
  }

  Game* g;
 protected:
  void rollMany(int n, int pins) {
    for (int i = 0; i < n; ++i) {
      g->roll(pins);
    }
  }

  void rollSpare() {
    g->roll(5);
    g->roll(5);    
  }

  void rollStrike() {
    g->roll(10);
  }
};

TEST_F(GameTest, test_game) {
  rollMany(20, 0);
  ASSERT_EQ(0, g->score());
}

TEST_F(GameTest, test_all_ones) {
  rollMany(20, 1);
  ASSERT_EQ(20, g->score());
}

TEST_F(GameTest, test_on_spare) {
  rollSpare();
  g->roll(3);
  rollMany(17, 0);
  ASSERT_EQ(16, g->score());
}

TEST_F(GameTest, test_on_strike) {
  rollStrike();
  g->roll(3);
  g->roll(4);
  rollMany(16, 0);
  ASSERT_EQ(24, g->score());
}

TEST_F(GameTest, test_perfact_game) {
  rollMany(12, 10);
  ASSERT_EQ(300, g->score());
}
