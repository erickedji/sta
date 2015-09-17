#ifndef DRAWING_H
#define DRAWING_H

// Provides drawing functions for the sketchbook.
// It is a thin wrapper arount the GFX library.

#include <stdint.h>
#include <math.h> // include pie by default

// set fill color
void fill(uint8_t r, uint8_t g, uint8_t b);
// disable filling shapes
void no_fill();
// set stroke color
void stroke(uint8_t r, uint8_t g, uint8_t b);
// disable stroking shapes
void no_stroke();

// draws a line from (x1, y1) to (x2, y2) with the stroke color
void line(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2);
// draws a rectangle from (x1, y1) to (x2, y2)
void rectangle(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2);
// draws an ellipse around (x, y) with the radius of rx and ry.
void ellipse(unsigned int x, unsigned int y, unsigned int rx, unsigned int ry);
// draws a circle with its midpoint at (x, y) and radius r
void circle(unsigned int x, unsigned int y, unsigned int r);
// draws a pie piece around the midpoint (x,y) and radius r. Start and end angle are given in degrees
void pie(unsigned int x, unsigned int y, unsigned int r, unsigned int start, unsigned int end);
// sets the given pixel to the stroke color
void pixel(unsigned int x, unsigned int y);

#endif
