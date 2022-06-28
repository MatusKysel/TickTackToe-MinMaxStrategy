#ifndef AI_PLAYER_H
#define AI_PLAYER_H

#include "player.h"

class AiPlayer : public Player {
public:

  AiPlayer(const char mark) : Player(mark) {}
  void Play(std::array<char, 9> &play_ground);

private:
  int Minimax(std::array<char, 9> &play_ground, bool player, int depth);
  int CheckGame(std::array<char, 9> &play_ground, int depth);

};
#endif // AI_PLAYER_H


