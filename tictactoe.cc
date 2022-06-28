#include "tictactoe.h"

#include <iostream>

TicTacToe::TicTacToe(PlayerType player1, PlayerType player2) {
  if(player1 == HUMAN) {
    player1_ = std::make_unique<HumanPlayer>(kPlayer1Mark);
  } else {
    player1_ = std::make_unique<AiPlayer>(kPlayer1Mark);
  }

  if(player2 == HUMAN) {
    player2_ = std::make_unique<HumanPlayer>(kPlayer2Mark);
  } else {
    player2_ = std::make_unique<AiPlayer>(kPlayer2Mark);
  }
}

void TicTacToe::InitPlayGournd(){
  for(auto &field: play_ground_) field = ' ';
}

void TicTacToe::Start() {
  game_ = true;
  InitPlayGournd();
  while(1) {
    player1_->Play(play_ground_);
    PrintGame();
    CheckGame(player1_.get());
    if(!game_) break;
    player2_->Play(play_ground_);
    PrintGame();
    CheckGame(player2_.get());
    if(!game_) break;
  }
  PrintOptions();
}

void TicTacToe::PrintGame() {
  std::cout << "Score: Player x: " << player1_->GetScore() <<
               " Player o: " << player2_->GetScore() << std::endl;
  std::cout << std::endl
            << play_ground_[0] << " │ " << play_ground_[1] << " │ "
            << play_ground_[2] << "\n──┼───┼──\n"
            << play_ground_[3] << " │ " << play_ground_[4] << " │ "
            << play_ground_[5] << "\n──┼───┼──\n"
            << play_ground_[6] << " │ " << play_ground_[7] << " │ "
            << play_ground_[8] << std::endl;
}

void TicTacToe::CheckGame(Player *player) {
  bool full = true;
  for(int i = 0; i < 8; ++i){
    if(play_ground_[kWinnings[i][0]] == player->GetMark() &&
       play_ground_[kWinnings[i][1]] == player->GetMark() &&
       play_ground_[kWinnings[i][2]] == player->GetMark()) {
      player->IncScore();
      game_ = false;
      std::cout << "Player " << player->GetMark() << " wins!" << std::endl;
    }
  }
  if(game_) {
    for(auto &mark: play_ground_) {
      if(mark == ' ')
        full = false;
    }
  }
  if(game_ && full){
    game_ = false;
    std::cout << "Game ends with a draw" << std::endl;
  }
}

void TicTacToe::PrintOptions() {
  int control;
  while(1) {
    std::cout << "Options: Restart - 0, Continue - 1, Exit - 9" << std::endl;
    std::cin >> control;
    switch (control) {
      case 9:
        return;
        break;
      case 0:
        player1_->ClearScore();
        player2_->ClearScore();
        Start();
        break;
      case 1:
        Start();
        break;
      default:
        std::cout << "Invalid option" << std::endl;
    }
  }
}
