#include "sketchbook.h"
#include <stdlib.h>
void setup() {
  clear_before_drawing(false);
  background(65, 75, 79);
}

#define MAXLINES 1000

// lines going up (right), from the left side
int x_up[MAXLINES];
int y_up[MAXLINES];

// lines going down (right), from the top side
int x_down[MAXLINES];
int y_down[MAXLINES];

void draw(){
  int i = frame_index() % MAXLINES;

  // a new line that starts with a point somewhere on the left edge of the screen
  x_up[i] = 0;
  y_up[i] = rand() % HEIGHT;

  // a new line that starts with a point somewhere on the top edge of the screen
  x_down[i] = rand() % WIDTH;
  y_down[i] = 0;

  // draw the next point of all existing lines
  // (we currently have i + 1 lines)
  int j;
  for (j = 0; j <= i; j++) {
    fill(i % 255, (j + i)%255, (j * i)%255);
    ellipse(x_up[j], y_up[j], 2, 2);

    fill(i % 255, (j + 2*i)%255, (2 * j * i)%255);
    ellipse(x_down[j], y_down[j], 2, 2);

    // update the positions for all points
    // for lines going up-right (from the left edge): x increases, y decreases
    x_up[j]++;
    y_up[j]--;
    // for lines going down-right (from the top edge): x increases, y increases
    x_down[j]++;
    y_down[j]++;

    // make sure all values stay within their bounds
    x_up[j] %= WIDTH;
    y_up[j] %= HEIGHT;
    x_down[j] %= WIDTH;
    y_down[j] %= HEIGHT;
  }
}
