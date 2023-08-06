#include <stdio.h>
#include <stdlib.h>

#include "logic.h"
#include "render.h"

int render(struct world map) { return 0; }

int main() {
  struct world map = createWorld();

  struct pos pos;
  pos.x = 10;
  pos.y = 10;
  struct dim dim;
  dim.w = 10;
  dim.h = 10;

  addSquare(dim, pos, &map);
  addSquare(dim, pos, &map);

  listCubes(&map);
  // printf("%d\n", map.squares.count);

  removeAllSquares(map);

  return 0;
}