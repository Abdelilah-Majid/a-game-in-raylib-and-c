#pragma once
#include "target_bloks_proccess.h"
#include <raylib.h>
#include <vector>
typedef struct Ball {
  float radios = 16;
  Vector2 pos{1216 / 2, 640 - 64 - 21};
  float speed = 6;
  Vector2 speed_factor_x_y{0, -1};
  Color color{DARKPURPLE};
} Ball;

typedef struct Ball_proccess {
  void main_proccess();
  void draw_ball();
  void ball_phsics();
  void on_ball_collide_with_blocks(int colliding_block_index, Blocks_proccess blocks_proccess);
  void on_ball_collide_with_bar(Vector2 bar_pos);

  Ball_proccess();
  std::vector<Ball> ball;
} Ball_proccess;