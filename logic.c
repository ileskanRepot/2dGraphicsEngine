
#include "logic.h"

#include <stdlib.h>

#include "randomFuncs.h"
#include "structs.h"

struct world createWorld() {
  struct world ret;

  // Initialize viewpoint
  ret.camera.position.x = 0;
  ret.camera.position.y = 0;
  ret.camera.dimension.h = 15;
  ret.camera.dimension.w = 15;

  ret.squares.count = 0;

  return ret;
}

int removeAllSquares(struct world* map) {
  free(map->squares.arr);
  map->squares.count = 0;
  return 0;
}

int move(struct world* map, char dir) {
  if (dir == 'q') {
    system("stty cooked");
    return 0;
  }

  switch (dir) {
    case 'w':
      if (!isSquareInPixel(map->camera.position.x, map->camera.position.y - 1,
                           map)) {
        map->camera.position.y -= 1;
      }
      break;

    case 'r':
      if (!isSquareInPixel(map->camera.position.x, map->camera.position.y + 1,
                           map)) {
        map->camera.position.y += 1;
      }
      break;

    case 'a':
      if (!isSquareInPixel(map->camera.position.x - 1, map->camera.position.y,
                           map)) {
        map->camera.position.x -= 1;
      }
      break;

    case 's':
      if (!isSquareInPixel(map->camera.position.x + 1, map->camera.position.y,
                           map)) {
        map->camera.position.x += 1;
      }
      break;

    default:
      break;
  }
  return 1;
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

int addFloor(struct world* map) {
  int floorWidht = 20;

  struct pos pos;
  pos.x = -floorWidht / 2;
  pos.y = 1;
  struct dim dim;
  dim.w = floorWidht;
  dim.h = 1;

  addSquare(dim, pos, map);
  return 0;
}