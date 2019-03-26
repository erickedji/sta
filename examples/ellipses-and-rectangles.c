#include "sketchbook.h"
#include <stdlib.h>

void setup() {
	clear_before_drawing(true);
	background(65, 75, 79);
}

void draw_rectangle(int x, int y, int i) {
  fill((i * 10) % 255, (i * 8) % 255, (i * 2) % 255);

  int x1 = x + 2*i;
  int y1 = y + 7*i;
  int x2 = x1 + 200 - i;
  int y2 = y1 + 100 - i;
  rectangle(x1, y1, x2, y2);
}

void draw_ellipse(int x, int y, int i) {
  fill((i * 10) % 255, (i * 8) % 255, (i * 2) % 255);

  ellipse(x + 4*i, y - 4*i, 10 + 2*i, 10 + 3*i);
}

void draw(){
	int x = mouse_x();
	int y = mouse_y();

  stroke(0, 0, 0);
  for (int i = 0; i < 50; i++) {
    draw_rectangle(100 + x/50, 100 + y/50, i);
    draw_ellipse(400 + x/50, 500 + x/50, i);
  }
}
