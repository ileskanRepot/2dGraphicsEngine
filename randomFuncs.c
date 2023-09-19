
#include "randomFuncs.h"

#include <stdio.h>

#include "structs.h"

int isSquareInPixel(int x, int y, struct world *map) {
  for (int ii = 0; ii < map->squares.count; ii++) {
    struct dim dim = map->squares.arr[ii].dimension;
    struct pos pos = map->squares.arr[ii].position;
    if ((pos.x <= x && x < pos.x + dim.w) &&
        (pos.y <= y && y < pos.y + dim.h)) {
      return 1;
    }
  }
  return 0;
}