#include <stdbool.h>

#define MAP_SIZE 20

enum PRdirection{NORTH, EAST, SOUTH, WEST} ;


typedef struct Cell{
  // 0 - north, 1 - east, 2 - south, 3 west
  
    Position position;
    
    bool border[4];
    bool wall[4];
    bool solution[4];
    bool backpath[4];
}Cell;


typedef Cell Maze[MAP_SIZE][MAP_SIZE];



typedef struct Position{

  int x;
  int y;
} Position;
