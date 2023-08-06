#ifndef STRUCTS_H
#define STRUCTS_H

struct pos {
  // X
  float x;
  // Y
  float y;
};

// Dimensions
struct dim {
  // Width
  float w;
  // Height
  float h;
};

struct square {
  struct dim dimension;
  struct pos position;
};

struct squares {
  int count;
  struct square* arr;
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

#endif