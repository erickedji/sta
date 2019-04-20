#include "sketchbook.h"

#define BIRD_X 100
#define INITIAL_BIRD_Y (HEIGHT / 2)
#define BIRD_FALL_PER_TICK 5
#define BIRD_CLIMB_DY 20

#define OBSTACLE_SPEED_PX_PER_TICK 4

/* the screen is divided into NB_AREAS areas, each containing one obstacle */
#define GAP_HEIGHT 200
#define NB_AREAS 2
/* draw one more obstacle, so they progressively exit/enter screen */
#define NB_OBSTACLES (NB_AREAS + 1)
#define AREA_WIDTH (WIDTH / NB_AREAS)
#define OBSTACLE_WIDTH (AREA_WIDTH / 3)
#define INITIAL_FIRST_OBSTACLE_X (WIDTH * 3 / 4)

void setup() {
  background(255, 255, 255);
}

void obstacle(int barX1, int gapY1) {
    no_stroke();

    fill(0, 0, 0);
    rectangle(barX1, 0, barX1 + OBSTACLE_WIDTH, HEIGHT);

    fill(255, 255, 255);
    rectangle(barX1, gapY1, barX1 + OBSTACLE_WIDTH, gapY1 + GAP_HEIGHT);
}

void bird(int y) {
  no_stroke();
  fill(255, 0, 0);
  circle(BIRD_X, y, 10);
}

void draw() {
  int i;

  static bool gameOver = false;
  static int birdY = INITIAL_BIRD_Y;
  static int obstacleStartX = INITIAL_FIRST_OBSTACLE_X;
  static int gapYs[NB_OBSTACLES] = {-1};

  if (gameOver) {
    background(0, 0, 0);
    stroke(0, 0, 255);
    text(WIDTH / 2 - 100, HEIGHT / 2, "Game Over!");
    return;
  }

  obstacleStartX -= OBSTACLE_SPEED_PX_PER_TICK;
  if (obstacleStartX + OBSTACLE_WIDTH < 0) {
    obstacleStartX = obstacleStartX + AREA_WIDTH;

    // shift obstacles
    for (i = 1; i < NB_OBSTACLES; i++)
      gapYs[i - 1] = gapYs[i];
    // last one is now empty
    gapYs[NB_OBSTACLES - 1] = -1;
  }

  // create a new obstacle in every position
  // where there is currently none
  for (i = 0; i < NB_OBSTACLES; i++)
    if (gapYs[i] == -1)
      gapYs[i] = (rand() % (HEIGHT - GAP_HEIGHT - 100)) + 100;

  for (i = 0; i < NB_OBSTACLES; i++)
    obstacle((i * AREA_WIDTH) + obstacleStartX, gapYs[i]);

  // collision detection
  bool yHit = birdY < gapYs[0] ||
    birdY > (gapYs[0] + GAP_HEIGHT);
  bool xHit = BIRD_X > obstacleStartX &&
    BIRD_X < (obstacleStartX + OBSTACLE_WIDTH);
  if (xHit && yHit) {
    // bird hit first obstacle
    gameOver = true;
  }

  // draw bird
  bird(birdY);
  birdY += BIRD_FALL_PER_TICK;
  if (birdY > HEIGHT) {
    // bird fell below bottom
    gameOver = true;
  }

  if (mouse_pressed()) {
    birdY -= BIRD_CLIMB_DY;
    if (birdY < 0) {
      // bird went over top
      gameOver = true;
    }
  }
}
