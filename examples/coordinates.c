#include "sketchbook.h"

void show_coordinates() {
    char label[5];
    int x, y;

    // X coordinates
    y = 0;
    for (x = 100; x < WIDTH; x += 100) {
        // tick mark
        line(x, y, x, y + 5);

        // label
        sprintf(label, "%d", x);
        text(x - 17, y + 10, label);
    }
    // show letter X at end of line
    text(WIDTH - 20, 10, "X");

    // Y coordinates
    x = 0;
    for (y = 100; y < HEIGHT; y += 100) {
        // tick mark
        line(x, y, x + 5, y);

        // label
        sprintf(label, "%d", y);
        text(10, y - 8, label);
    }
    // show letter Y at end of line
    text(10, HEIGHT - 20, "Y");
}

void setup() {}

void draw() {
    show_coordinates();
}

