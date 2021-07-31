#include "bar_proccess.h"

void Bar_proccess::main_proccess() {
  bar_movement_proccess();
  draw_bar();
};
void Bar_proccess::draw_bar() {
  DrawRectangle(bar.at(0).pos.x, bar.at(0).pos.y, bar.at(0).w_h.x, bar.at(0).w_h.y, bar.at(0).color);
};
void Bar_proccess::bar_movement_proccess() {
  if ((bar.at(0).pos.x < 0 && IsKeyDown(KEY_LEFT)) || (bar.at(0).pos.x > 1216 - 64 * 3 && IsKeyDown(KEY_RIGHT)))
    return;
  if (IsKeyDown(KEY_LEFT))
    bar.at(0).pos.x -= bar.at(0).speed;
  if (IsKeyDown(KEY_RIGHT))
    bar.at(0).pos.x += bar.at(0).speed;
};

Bar_proccess::Bar_proccess() {
  bar.push_back(*new Bar());
};