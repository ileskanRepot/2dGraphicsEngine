#ifndef STRUCTS_H
#define STRUCTS_H

struct col {
  int r;
  int g;
  int b;
};

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
  struct col color;
  struct dim dimension;
  struct pos position;
};

struct squares {
  int count;
  struct square* arr;
};

struct camera {
  // Center point of camera
  struct pos position;

  // Camera's dimensions. Should be odd numbers
  struct dim dimension;
};

struct world {
  struct camera camera;
  struct squares squares;
};

#endif