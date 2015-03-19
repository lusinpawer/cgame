
#ifndef cgame_mazegamestructs_h
#define cgame_mazegamestructs_h

#include <stdbool.h>

#define MAP_SIZE 20

typedef struct Position{
    
    int x;
    int y;
} Position;

typedef struct Cell{
  // 0 - north, 1 - east, 2 - south, 3 west
  
    Position position;
    
    bool border[4];
    bool wall[4];
    bool solution[4];
    bool backpath[4];
}Cell;


typedef Cell Maze[MAP_SIZE];
//typedef Cell Maze[MAP_SIZE];


#endif


