#include "target_bloks_proccess.h"

void Blocks_proccess::main_proccess() {
  texture_rendering_proccess();
}

Blocks_proccess::Blocks_proccess() {
  for (unsigned long int i = 0; i < blocks_size.x * blocks_size.y; i++) {
    blocks_arr.push_back(Block());
  }

  for (unsigned long int j = 0; j < blocks_size.y; j++) {
    for (unsigned long int i = 0; i < blocks_size.x; i++) {
      blocks_arr.at(j * blocks_size.x + i).pos_x_and_y = (Vector2){i * 64.0f, j * 64.0f};
    }
  }

  unsigned short int color_index = 0;
  Color_palet color_palet = *new Color_palet();

  for (unsigned long int i = 0; i < blocks_size.x * blocks_size.y; i++) {
    blocks_arr.at(i).color = color_palet.colors.at(color_index);
    color_index++;
    if (color_index > 1)
      color_index = 0;
  }
}

Blocks_proccess::~Blocks_proccess() {
}

void Blocks_proccess::collesion_proccess(int colliding_block_index_with_ball) {
  blocks_arr.erase(blocks_arr.begin() + colliding_block_index_with_ball);
}

void Blocks_proccess::texture_rendering_proccess() {
  for (unsigned long int i = 0; i < blocks_arr.size(); i++) {
    DrawRectangle(blocks_arr.at(i).pos_x_and_y.x, blocks_arr.at(i).pos_x_and_y.y, 64, 64, blocks_arr.at(i).color);
  }
}
