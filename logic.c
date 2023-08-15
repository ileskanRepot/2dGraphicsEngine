#include "logic.h"

#include <stdlib.h>

#include "structs.h"

struct world createWorld() {
  struct world ret;

  // Initialize viewpoint
  ret.camera.position.x = 0;
  ret.camera.position.y = 0;
  ret.camera.dimension.h = 9;
  ret.camera.dimension.w = 9;

  ret.squares.count = 0;

  return ret;
}

int removeAllSquares(struct world* map) {
  free(map->squares.arr);
  map->squares.count = 0;
  return 0;
}

int addSquare(struct dim dimension, struct pos position, struct world* map) {
  int count = map->squares.count;
  if (map->squares.arr == 0) {
    map->squares.arr = malloc(sizeof(struct square));
  } else {
    map->squares.arr = realloc(
        map->squares.arr, (map->squares.count + 1) * sizeof(struct square));
  }
  if (!map->squares.arr) {
    return -1;
  }
  map->squares.arr[count].dimension.h = dimension.h;
  map->squares.arr[count].dimension.w = dimension.w;
  map->squares.arr[count].position.x = position.x;
  map->squares.arr[count].position.y = position.y;

  map->squares.count++;

  return 0;
}