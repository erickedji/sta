#include "misc.h"
#include <sys/time.h>
#include <time.h>
#include <stdlib.h>
#include "sketchbook.h"

static unsigned long long start_millis = 0;

void misc_init() {
  srand(time(NULL));
  start_millis = millis();
}

unsigned long long millis() {
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000 - start_millis;
}
