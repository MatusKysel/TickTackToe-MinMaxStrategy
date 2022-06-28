#ifndef PLAYER_H
#define PLAYER_H

#include <array>


static const std::array<std::array<int, 3>, 8> kWinnings = {{
                                                              {0, 1, 2},
                                                              {3, 4, 5},
                                                              {6, 7, 8},
                                                              {0, 3, 6},
                                                              {1, 4, 7},
                                                              {2, 5, 8},
                                                              {0, 4, 8},
                                                              {2, 4, 6}
                                                            }};

static const char kPlayer1Mark = 'x';
static const char kPlayer2Mark = 'o';

class Player {
public:

  Player(const char mark) : score_(0), mark_(mark) {}

  virtual void Play(std::array<char, 9> &play_ground) = 0;
  const int GetScore() { return score_; }
  const char GetMark() { return mark_; }
  void ClearScore() { score_ = 0; }
  void IncScore() { ++score_; }

protected:
  char GetOponentsMark()
  { return (mark_ == kPlayer1Mark) ? kPlayer2Mark : kPlayer1Mark; }
  char mark_;
private:
  int score_;
};
#endif // PLAYER_H
