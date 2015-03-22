#include <stdio.h>

#define NDEBUG

#include "dbg.h"
#include "mazeGameStructs.h"
#include "maze.h"
#include "map.h"


int main()
{
    Cell cellArray[MAP_SIZE][MAP_SIZE];
    Maze *maze = cellArray;
    generateMaze(maze);
    
    Position currentPosition;
    currentPosition.x = 0;
    currentPosition.y = 0;
    char c;
    
    generateMap(currentPosition);

    printf("\nPress one of the a (left),s (down),d (right),w (top) followed by ENTER to walk around the maze \n");
    while(1)
    {
        if((c = getchar()) != '\n')
        {
            updatePosition(&currentPosition,c, maze);
            generateMap(currentPosition);
            if(currentPosition.x == MAP_SIZE-1 && currentPosition.y == MAP_SIZE-1)
            {
                printf("\nYou've won the game!\n");
                break;
            }
        }
    }
    
    return 0;
}


