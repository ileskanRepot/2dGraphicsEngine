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
  dim.h = 5;

  addSquare(dim, pos, &map);

  listCubes(&map);
  // printf("%d\n", map.squares.count);

  int running = 1;
  char cur = 0;

  while (running) {
    system("stty cooked");
    renderWorldSimple(&map);
    printf("Enter input (w,a,r,s,q)");
    system("stty raw");
    cur = getchar();

    running = move(&map, cur);

    // printf("WEE: %d", cur);
  };
  printf("\n");
  removeAllSquares(&map);

  return 0;
}
