#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#include <memory>
#include <array>
#include <vector>

#include "player.h"
#include "human_player.h"
#include "ai_player.h"

class TicTacToe {
public:
  enum PlayerType {
    HUMAN = 0,
    AI
  };

  TicTacToe(PlayerType player1, PlayerType player2);

  ~TicTacToe() {}

  void Start();

private:
  void PrintGame();
  void PrintOptions();
  void CheckGame(Player *player);
  void InitPlayGournd();

  std::array<char, 9> play_ground_;
  std::unique_ptr<Player> player1_;
  std::unique_ptr<Player> player2_;
  bool game_;
};
#endif // TIC_TAC_TOE_H
