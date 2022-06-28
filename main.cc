#include <iostream>
#include <memory>

#include "tictactoe.h"

void print_info(){
  std::cout << "Welcome in TicTacToe Game" << std::endl;
  std::cout << "Please select game wariant ..." << std::endl;
  std::cout << "Press 0 -> AI vs HUMAN" << std::endl;
  std::cout << "Press 1 -> HUMAN vs AI" << std::endl;

}

void print_err(){
  std::cout << "Yours selection is not matching" << std::endl;
  std::cout << "Game is restarting ..." << std::endl;
}

int main() {
  int selection = 9;
  std::unique_ptr<TicTacToe> game;

  while(1) {
    print_info();
    std::cin >> selection;
    if (selection == 1 || selection == 0) break;
    print_err();
  }
  game = (selection) ?
           std::make_unique<TicTacToe>(TicTacToe::HUMAN, TicTacToe::AI) :
           std::make_unique<TicTacToe>(TicTacToe::AI, TicTacToe::HUMAN);

  game->Start();

  return 0;
}
