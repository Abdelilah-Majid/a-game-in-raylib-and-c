#include "collesion_detection_proccess.h"

void Collesion_detection_proccess::main_proccess(Blocks_proccess &blocks_proccess,
                                                 Bar_proccess &bar_proccess,
                                                 Ball_proccess &ball_proccess) {

  int colliding_block = blocks_collesion_detection(blocks_proccess, bar_proccess, ball_proccess);
  if (colliding_block != -1) {
    ball_proccess.on_ball_collide_with_blocks(colliding_block, blocks_proccess);
    blocks_proccess.collesion_proccess(colliding_block);
  }
  bool colliding_bar = bar_collesion_detection(blocks_proccess, bar_proccess, ball_proccess);
  if (colliding_bar) {
    ball_proccess.on_ball_collide_with_bar(bar_proccess.bar.at(0).pos);
  }
}
int Collesion_detection_proccess::blocks_collesion_detection(Blocks_proccess &blocks_proccess,
                                                             Bar_proccess &bar_proccess,
                                                             Ball_proccess &ball_proccess) {
  for (unsigned long int i = 0; i < blocks_proccess.blocks_arr.size(); i++) {

    if (ball_proccess.ball.at(0).pos.x - ball_proccess.ball.at(0).radios > blocks_proccess.blocks_arr.at(i).pos_x_and_y.x + 64) {

      continue;
    }
    if (ball_proccess.ball.at(0).pos.x + ball_proccess.ball.at(0).radios < blocks_proccess.blocks_arr.at(i).pos_x_and_y.x) {

      continue;
    }
    if (ball_proccess.ball.at(0).pos.y - ball_proccess.ball.at(0).radios > blocks_proccess.blocks_arr.at(i).pos_x_and_y.y + 64) {

      continue;
    }
    if (ball_proccess.ball.at(0).pos.y + ball_proccess.ball.at(0).radios < blocks_proccess.blocks_arr.at(i).pos_x_and_y.y) {

      continue;
    }
    return i;
  }
  return -1;
}

bool Collesion_detection_proccess::bar_collesion_detection(Blocks_proccess &blocks_proccess, Bar_proccess &bar_proccess, Ball_proccess &ball_proccess) {

  if (ball_proccess.ball.at(0).pos.x - ball_proccess.ball.at(0).radios > bar_proccess.bar.at(0).pos.x + bar_proccess.bar.at(0).w_h.x) {
    return false;
  }
  if (ball_proccess.ball.at(0).pos.x + ball_proccess.ball.at(0).radios < bar_proccess.bar.at(0).pos.x) {
    return false;
  }
  if (ball_proccess.ball.at(0).pos.y - ball_proccess.ball.at(0).radios > bar_proccess.bar.at(0).pos.y + bar_proccess.bar.at(0).w_h.y) {
    return false;
  }
  if (ball_proccess.ball.at(0).pos.y + ball_proccess.ball.at(0).radios < bar_proccess.bar.at(0).pos.y) {
    return false;
  }
  return true;
}