#include "render.h"

#include <stdio.h>

#include "structs.h"

int listCubes(struct world *map) {
  printf("Square count: %d\n", map->squares.count);
  return 0;
}