#pragma once
#include "ball_proccess.h"
#include "bar_proccess.h"
#include "target_bloks_proccess.h"

typedef struct Collesion_detection_proccess {
  void main_proccess(Blocks_proccess &blocks_proccess,
                     Bar_proccess &bar_proccess,
                     Ball_proccess &ball_proccess);
  int blocks_collesion_detection(Blocks_proccess &blocks_proccess,
                                 Bar_proccess &bar_proccess,
                                 Ball_proccess &ball_proccess);
  bool bar_collesion_detection(Blocks_proccess &blocks_proccess,
                               Bar_proccess &bar_proccess,
                               Ball_proccess &ball_proccess);
} Collesion_detection_proccess;