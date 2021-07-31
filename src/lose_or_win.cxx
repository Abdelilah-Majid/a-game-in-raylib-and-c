#include "lose_or_win.h"

int Lose_or_win::main_procccess(Ball_proccess &ball_proccess, Blocks_proccess &blocks_process) {
  if (ball_proccess.ball.at(0).pos.y > 640)
    return -1;
  if (blocks_process.blocks_arr.size() == 0)
    return 1;
  return 0;
}