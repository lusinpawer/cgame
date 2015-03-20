#include <stdio.h>

#define NDEBUG

#include "dbg.h"
#include "mazeGameStructs.h"
#include "maze.h"


void updatePosition(Position *pos, char c, const Maze *maze)
{
    switch(c){
            
        case 'a':
        {
            if(!maze[pos->x][pos->y].wall[3] && !maze[pos->x][pos->y].border[3])
            {
                pos->x--;
                return;
            }
            break;
        }
        case 'd':
        {
            if(!maze[pos->x][pos->y].wall[1] && !maze[pos->x][pos->y].border[1])
            {
                pos->x++;
                return;
            }
            break;
        }
        case 'w':
        {
            if(!maze[pos->x][pos->y].wall[0] && !maze[pos->x][pos->y].border[0])
            {
                pos->y--;
                return;
            }
            break;
        }
        case 's':
        {
            if(!maze[pos->x][pos->y].wall[2] && !maze[pos->x][pos->y].border[2])
            {
                pos->y++;
                return;
            }
            break;
        }
        default:
        {
            printf("Press one of the a (left),s (down),d (right),w (top) to walk around the maze \n");
            return;
        }
    }
    printf("border or wall!\n\n");
    
}

void generateMap(Position pos)
{
    int i,j;
    debug("Position: %d %d \n\n", pos.x, pos.y);
    for (j=0;j<MAP_SIZE;j++)
    {
        for(i=0;i<MAP_SIZE;i++)
        {
            if(pos.x == i && pos.y == j)
                printf("O");
            else
                printf("X");
        }
        printf("\n");
    }
    printf("\n");
}

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

    printf("Press one of the a (left),s (down),d (right),w (top) followed by ENTER to walk around the maze \n");
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


