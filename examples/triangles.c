#include "sketchbook.h"
#include <stdlib.h>

void setup() {
	clear_before_drawing(false);
	background(144,195,212);
}

void draw(){
	int x1 = mouse_x();
	int y1 = mouse_y();

  int x2 = x1 + rand() % 100;
  int y2 = y1 + rand() % 100;
  int x3 = x1 + rand() % 100;
  int y3 = y1 + rand() % 100;

  stroke(0, 0, 0);
  fill((x1 + x2) % 255, (x2 + x3) % 255, (y1 + y2 + y3) % 255);
  triangle(x1, y1, x2, y2, x3, y3);
}
