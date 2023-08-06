#include "render.h"

#include <stdio.h>

#include "structs.h"

// int renderWorldSimple(struct world *map) {
//     ;
//   return 0;
// }

int listCubes(struct world *map) {
  int squareCount = map->squares.count;
  printf("Square count: %d\n", squareCount);

  for (int ii = 0; ii < squareCount; ii++) {
    printf("--- Square %d ---\n", ii);
    printf("Position (%.2f, %.2f)\n", map->squares.arr[ii].position.x,
           map->squares.arr[ii].position.y);

    printf("Dimensions (%.2f, %.2f)\n", map->squares.arr[ii].dimension.w,
           map->squares.arr[ii].dimension.h);
  }
  return 0;
}