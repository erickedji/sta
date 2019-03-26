# include "sketchbook.h"
void setup()
{
    background(0, 0, 40);
    stroke(255, 255, 255);
}
#define MAX_POINTS 1000

int currentIndex = 0;
int x[MAX_POINTS];
int y[MAX_POINTS];

void draw()
{
    x[currentIndex] = mouse_x();
    y[currentIndex] = mouse_y();


    for (int i = 0; i <= currentIndex; i++) {
        // corners
        line(x[i], y[i], 0, 0);
        line(x[i], y[i], 0, HEIGHT);
        line(x[i], y[i], WIDTH, 0);
        line(x[i], y[i], WIDTH, HEIGHT);

        // middles
        line(x[i], y[i], WIDTH/2, 0);
        line(x[i], y[i], WIDTH, HEIGHT/2);
        line(x[i], y[i], WIDTH/2, HEIGHT);
        line(x[i], y[i], 0, HEIGHT/2);
    }

    currentIndex++;
}
