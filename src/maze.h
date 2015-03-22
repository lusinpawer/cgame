// Perfect maze algorithm based on pseudocode from
// http://www.mazeworks.com/mazegen/mazetut/


#ifndef cgame_maze_h
#define cgame_maze_h

#define NDEBUG

#include "mazeGameStack.h"
#include "mazeGameStructs.h"
#include "dbg.h"
#include "time.h"
#include <string.h>


bool generateMaze(Maze *maze);


#endif