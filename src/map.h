
#ifndef __cgame__map__
#define __cgame__map__

#include <stdio.h>

#define NDEBUG

#include "mazeGameStructs.h"
#include "dbg.h"

void updatePosition(Position *pos, char c, const Maze *maze);
void generateMap(Position pos);

#endif
