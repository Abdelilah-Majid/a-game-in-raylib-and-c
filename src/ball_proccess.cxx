#include "ball_proccess.h"

void Ball_proccess::main_proccess() {
  ball_phsics();
  draw_ball();
}

void Ball_proccess::draw_ball() {
  DrawCircle(ball.at(0).pos.x, ball.at(0).pos.y, ball.at(0).radios, ball.at(0).color);
}

void Ball_proccess::ball_phsics() {

  ball.at(0).pos.y += ball.at(0).speed * ball.at(0).speed_factor_x_y.y;
  ball.at(0).pos.x += ball.at(0).speed * ball.at(0).speed_factor_x_y.x;

  if (ball.at(0).pos.x + ball.at(0).radios > 1216 || ball.at(0).pos.x - ball.at(0).radios < 0) {
    ball.at(0).speed_factor_x_y.x *= -1;
    ball.at(0).pos.x > 1216 / 2 ? ball.at(0).pos.x -= 1 : ball.at(0).pos.x += 1;
  }
  if (ball.at(0).pos.y - ball.at(0).radios < 0) {
    ball.at(0).speed_factor_x_y.y *= -1;
    ball.at(0).pos.y += 1;
  }
}

void Ball_proccess::on_ball_collide_with_blocks(int colliding_block_index, Blocks_proccess blocks_proccess) {
  if ((ball.at(0).pos.x - ball.at(0).radios < blocks_proccess.blocks_arr.at(colliding_block_index).pos_x_and_y.x + 59)) {
    if ((ball.at(0).pos.x + ball.at(0).radios > blocks_proccess.blocks_arr.at(colliding_block_index).pos_x_and_y.x + 5)) {
      ball.at(0).speed_factor_x_y.y *= -1;
    }
  }
  if ((ball.at(0).pos.y - ball.at(0).radios < blocks_proccess.blocks_arr.at(colliding_block_index).pos_x_and_y.y + 59)) {

    if ((ball.at(0).pos.y + ball.at(0).radios > blocks_proccess.blocks_arr.at(colliding_block_index).pos_x_and_y.y + 5)) {
      ball.at(0).speed_factor_x_y.x *= -1;
    }
  }
}

void Ball_proccess::on_ball_collide_with_bar(Vector2 bar_pos) {
  ball.at(0).speed_factor_x_y.y *= -1;
  ball.at(0).speed_factor_x_y.x = ((ball.at(0).pos.x - bar_pos.x) / (64 * 3) * 2) - 1;
}

Ball_proccess::Ball_proccess() {
  ball.push_back(*new Ball());
}