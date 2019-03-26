# include "sketchbook.h"
void setup()
{
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
        circle(x[i], y[i], 20);
    }

    currentIndex++;
}
