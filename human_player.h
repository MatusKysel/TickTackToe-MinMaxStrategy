#ifndef HUMAN_PLAYER_H
#define HUMAN_PLAYER_H

#include "player.h"

class HumanPlayer : public Player {
public:

  HumanPlayer(const char mark) : Player(mark) {}
  void Play(std::array<char, 9> &play_ground);

private:

};
#endif // HUMAN_PLAYER_H
