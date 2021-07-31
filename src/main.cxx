#include "ball_proccess.h"
#include "bar_proccess.h"
#include "collesion_detection_proccess.h"
#include "lose_or_win.h"
#include "target_bloks_proccess.h"
#include <iostream>
#include <raylib.h>
#include <vector>
int main() {

  unsigned short int min_screen_width = 1216;
  unsigned short int min_screen_hight = 640;

  SetConfigFlags(FLAG_MSAA_4X_HINT);
  // SetConfigFlags(FLAG_WINDOW_RESIZABLE);
  SetConfigFlags(FLAG_VSYNC_HINT);

  InitWindow(min_screen_width, min_screen_hight, "hello abdelilah majid i hope you a good day");
  SetWindowMinSize(min_screen_width, min_screen_hight);
  SetTargetFPS(300);
  int lose_or_win_int = 0;
  Blocks_proccess blocks_proccess = *new Blocks_proccess();
  Bar_proccess bar_proccess = *new Bar_proccess();
  Ball_proccess ball_proccess = *new Ball_proccess();
  Collesion_detection_proccess collesion_detection_proccess = *new Collesion_detection_proccess();
  Lose_or_win lose_or_win = *new Lose_or_win();

  while (!WindowShouldClose()) {
    //      update game variables here
    // update var
    //draw
    BeginDrawing();
    ClearBackground(WHITE);
    DrawText(std::to_string(GetFPS()).c_str(), GetScreenWidth() - 25, GetScreenHeight() - 20, 20, (Color){0, 255, 0, 255});
    // DrawText("hi majid abdelilah you did it", 600 / 6, 400 / 2, 30, YELLOW);
    // this is how to get the window size
    // std::cout << GetScreenWidth() << std::endl;
    lose_or_win_int = lose_or_win.main_procccess(ball_proccess, blocks_proccess);

    if (lose_or_win_int == 0) {
      blocks_proccess.main_proccess();
      bar_proccess.main_proccess();
      ball_proccess.main_proccess();
      collesion_detection_proccess.main_proccess(blocks_proccess, bar_proccess, ball_proccess);
    } else if (lose_or_win_int == -1) {
      DrawText("you lose", 1216 / 2 - (30 / 4) * 8, 640 / 2 - (30 / 4), 30, RED);
    } else {
      DrawText("you win", 1216 / 2 - (30 / 4) * 7, 640 / 2 - (30 / 4), 30, GREEN);
    }

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
