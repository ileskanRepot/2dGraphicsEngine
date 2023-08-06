#include <stdio.h>
#include <stdlib.h>

struct pos {
  float x;
  float y;
};

struct square {
  float width;
  float height;
  struct pos position;
};

struct squares {
  int count;
  struct square* arr
};

struct camera {
  struct pos position;
  float width;
  float height;
};

struct world {
  struct camera camera;
  struct squares squares;
};

int addSquare(float width, float height, struct pos position,
              struct world map) {
  map.squares.arr = realloc(map.squares.arr, sizeof(struct square));
  if (map.squares.arr == NULL) {
    return -1;
  }
  map.squares.arr[map.squares.count].height = height;
  map.squares.arr[map.squares.count].width = width;
  map.squares.arr[map.squares.count].position.x = position.x;
  map.squares.arr[map.squares.count].position.y = position.y;

  map.squares.count++;

  return 1;
}

int render(struct world map) {}

int main() {
  struct world map;

  return 0;
}