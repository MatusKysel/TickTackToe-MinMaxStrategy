#include "human_player.h"

#include <iostream>

void HumanPlayer::Play(std::array<char, 9> &play_ground) {
  int field_num;
  while(1){
    std::cout << "Please select field number form 0 - 8 (starting in upper "
                 "right corner): ";
    std::cin >> field_num;
    if(play_ground[field_num] == ' ') {
      play_ground[field_num] = mark_;
      break;
    }
    std::cout << "Your move it's not valid" << std::endl;
  }
}
