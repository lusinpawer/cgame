#include <stdio.h>
#include <string.h>
#include "mazeGameStructs.h"
#include "maze.h"

bool generateMaze(Maze *maze)
{
    printf("start generating maze\n");
    memset(maze,false,sizeof(Maze));
    
    for(int i=0;i<MAP_SIZE;i++)
    {
        for(int j=0;j<MAP_SIZE;j++)
        {
            //set all walls up
            maze[i][j].position.x = i;
            maze[i][j].position.y = j;
            memset(maze[i][j].wall,true,sizeof(bool)*4);
        }
    }
    printf("start generating path\n");
    generatePath(maze);
    
    
    return true;
}



void updatePosition(Position *pos, char c)
{
    switch(c){
            
        case 'a':
            pos->y = (pos->y > 0);
            break;
        case 'd':
            pos->y++;
            break;
        case 'w':
            pos->x--;
            break;
        case 's':
            pos->x++;
            break;
        default:
            break;
    }
    
}

void generateMap(Position *pos)
{
    int i,j;
    printf("\n");
    for (i=0;i<MAP_SIZE;i++)
    {
        for(j=0;j<MAP_SIZE;j++)
        {
            if(pos->x == i && pos->y == j)
                printf("O");
            else
                printf("X");
        }
        printf("\n");
    }
}

int main()
{
    printf("start!!\n");
    Cell cellArray[MAP_SIZE][MAP_SIZE];
    Maze *maze = cellArray;
    generateMaze(maze);
    
    Position *currentPosition = NULL;
    
    currentPosition->x = 0;
    currentPosition->y = 0;
    
    char c;
    
    while(1)
    {
        generateMap(currentPosition);
        c = getchar();
        updatePosition(currentPosition,c);
    }
    
    return 0;
}


//
//                       find all neighbors of CurrentCell with all walls intact
//                       if one or more found
//                       choose one at random
//                       knock down the wall between it and CurrentCell
//                       push CurrentCell location on the CellStack
//                       make the new cell CurrentCell
//                       add 1 to VisitedCells
//                       else
//                       pop the most recent cell entry off the CellStack
//                       make it CurrentCell
//                       endIf
//                       }

