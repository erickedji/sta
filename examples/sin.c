# include "sketchbook.h"
void setup()
{
//    fps(100);
}
void draw()
{
    static int i = 0;
    int x, y, r = 10;

    for (int j = 0; j <= i; j++) {
        x = j;
        y = 100 * sin(j) - 50;
        circle(x, y + (HEIGHT / 2), r);
    }

    i = (i + 1) % WIDTH;
}
