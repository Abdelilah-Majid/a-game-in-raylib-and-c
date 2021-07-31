#pragma once
#include <iostream>
#include <math.h>
#include <raylib.h>
#include <vector>

typedef struct Color_palet {
  std::vector<Color> colors{LIGHTGRAY, DARKGRAY};

} Color_palet;

typedef struct Block {

  Vector2 pos_x_and_y{0, 0};

  Color color = (Color){255, 255, 255, 255};

  const char *type = "block";
} Block;

typedef struct Blocks_proccess {
  void main_proccess();
  Blocks_proccess();
  ~Blocks_proccess();

  void collesion_proccess(int colliding_block_index_with_ball);
  void texture_rendering_proccess();

  Vector2 blocks_size{19, 5};

  std::vector<Block> blocks_arr;

} Blocks_proccess;
