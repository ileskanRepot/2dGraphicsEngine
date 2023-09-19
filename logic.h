#include "structs.h"

struct world createWorld();

int move(struct world* map, char dir);

int removeAllSquares(struct world* map);

int addSquare(struct dim dimension, struct pos position, struct world* map);