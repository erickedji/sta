#include "sketchbook.h"
#include <stdlib.h>

void setup() {
	clear_before_drawing(false);
	background(65, 75, 79);
}

void rounded_rectangle(int x1, int y1, int x2, int y2, int r) {

  stroke(0, 0, 0);

  circle(x1 + r, y1 + r, r);
  circle(x1 + r, y2 - r, r);
  circle(x2 - r, y1 + r, r);
  circle(x2 - r, y2 - r, r);

  no_stroke();
  rectangle(x1 + r, y1, x2 - r, y2);
  rectangle(x1, y1 + r, x2, y2 - r);

  stroke(0, 0, 0);

  line(x1, y1 + r, x1, y2 - r);
  line(x1 + r, y2, x2 - r, y2);
  line(x2, y2 - r, x2, y1 + r);
  line(x2 - r, y1, x1 + r, y1);
}

void draw(){
	int x = mouse_x();
	int y = mouse_y();

  int x1 = rand() % (x > 0 ? x : WIDTH);
  int y1 = rand() % (y > 0 ? y : HEIGHT);

  stroke(0, 0, 0);
  fill(255, 255, 255);
  rounded_rectangle(x1, y1, x1 + 50, y1 + 50, 10);

  y = 50;
  x = frame_index();
  rounded_rectangle(x, y, x + 50, y + 50, 10);

  x = 50;
  y = frame_index();
  rounded_rectangle(x, y, x + 50, y + 50, 10);

}
