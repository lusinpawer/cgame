#include <stdbool.h>

#define MAP_SIZE 20

typedef struct Cell{
  // 0 - north, 1 - east, 2 - south, 3 west
  bool border[4];
  bool wall[4];
  bool solution[4];
  bool backpath[4];
}Cell;


typedef Cell Maze[MAP_SIZE][MAP_SIZE];



typedef struct Position{

  int xposition;
  int yposition;
} Position;
