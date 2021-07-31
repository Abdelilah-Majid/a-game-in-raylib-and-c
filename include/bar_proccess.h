#pragma once
#include <raylib.h>
#include <vector>
typedef struct Bar {
  Vector2 w_h{64 * 3, 64 / 2};
  Vector2 pos{1216 / 2 - w_h.x / 2, 640 - 64};
  Color color{DARKGRAY};
  float speed = 6;

} Bar;

typedef struct Bar_proccess {
  void main_proccess();
  void draw_bar();
  void bar_movement_proccess();
  float calculate_speed_according_to_cpu_clock_speed();
  Bar_proccess();
  std::vector<Bar> bar;

} Bar_proccess;