#include <stdio.h>
#include <stdlib.h>

#include "logic.h"
#include "render.h"

int main() {
  struct world map = createWorld();

  struct pos pos;
  pos.x = 0;
  pos.y = 0;
  struct dim dim;
  dim.w = 2;
  dim.h = 2;

  addSquare(dim, pos, &map);

  listCubes(&map);
  // printf("%d\n", map.squares.count);

  renderWorldSimple(&map);

  removeAllSquares(&map);

  return 0;
}