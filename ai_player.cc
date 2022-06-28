#include "ai_player.h"

void AiPlayer::Play(std::array<char, 9> &play_ground) {
  int move = -1;
  int score = -99;
  int temp_score = -9;
  for(int i = 0; i < 9; ++i) {
    if(play_ground[i] == ' ') {
      play_ground[i] = mark_;
      temp_score = AiPlayer::Minimax(play_ground, true, 1);
      play_ground[i] = ' ';
      if(temp_score > score) {
        score = temp_score;
        move = i;
      }
    }
  }
  play_ground[move] = mark_;
}


int AiPlayer::Minimax(std::array<char, 9> &play_ground,
                      bool player, int depth) {
  int winner = AiPlayer::CheckGame(play_ground, depth);
  if(winner != 0) return winner;

  int move = -1;
  int score = 0;
  int temp_score = -9;
  for(int i = 0; i < 9; ++i) {
    if(play_ground[i] == ' ') {
      play_ground[i] = (player) ? GetOponentsMark() : mark_;
      temp_score = AiPlayer::Minimax(play_ground, (player) ? false : true,
                                     depth + 1);
      if(((temp_score > score) && !player) ||
         ((temp_score < score) && player)) {
        score = temp_score;
        move = i;
      }
      play_ground[i] = ' ';
    }
  }
  if(move == -1) return 0;
  return score;
}

int AiPlayer::CheckGame(std::array<char, 9> &play_ground, int depth) {
  for(int i = 0; i < 8; ++i){
    if(play_ground[kWinnings[i][0]] != ' ' &&
       play_ground[kWinnings[i][0]] == play_ground[kWinnings[i][1]] &&
       play_ground[kWinnings[i][0]] == play_ground[kWinnings[i][2]]) {
      return (play_ground[kWinnings[i][0]] == mark_) ? 10 - depth : depth - 10;
    }
  }
  return 0;
}
