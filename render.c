#include "render.h"

#include <stdio.h>

#include "randomFuncs.h"
#include "structs.h"

int renderWorldSimple(struct world *map) {
  int squareCount = map->squares.count;
  printf("%d\n", squareCount);
  struct pos playerPos = map->camera.position;
  struct dim playerDim = map->camera.dimension;
  printf("  ");
  for (int ww = -(playerDim.w / 2); ww <= (int)(playerDim.h / 2); ww++) {
    printf("%2d", ww);
  }
  printf("\n");

  for (int hh = -(playerDim.h / 2); hh <= (int)(playerDim.h / 2); hh++) {
    printf("%2d", hh);
    for (int ww = -(playerDim.w / 2); ww <= (int)(playerDim.h / 2); ww++) {
      if (hh == 0 && ww == 0) {
        printf("@@");

      } else if (isSquareInPixel(playerPos.x + ww, playerPos.y + hh, map)) {
        printf("##");
      } else {
        printf("  ");
      }
    }
    printf("\n");
  }

  return 0;
}

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