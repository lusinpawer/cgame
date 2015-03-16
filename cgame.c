#include <stdio.h>
#include "mazeGameStructs.h"
#include "mazeGameStack.h"

bool generateMaze(Maze *maze)
{
    memset(maze,false,sizeof(Maze));
    
    for(int i=0;i<MAP_SIZE;i++)
    {
        for(int j=0;j<MAP_SIZE;j++)
        {
            //set all walls up
            maze[i][j]->position->x = i;
            maze[i][j]->position->j = j;
            memset(maze[i][j]->wall,true,sizeof(bool)*4);
        }
    }
    return true;
}

    bool generatePath(Maze *maze)
    {
      CellNode *head;
      createStack(&head);
      int totalCells = MAP_SIZE*MAP_SIZE;
      int i = rand()%MAP_SIZE;
      int j = rand()%MAP_SIZE;
      Cell *currentCell = maze[i][j];
      int visitedCells = 1;
      while (visitedCells < totalCells)
	{
        int intactCount;
        if( (intactCount = intactNeighboursCount(maze, i, j) > 0))
        {
            // select random cell
            int randomDirection = randomDirection(currentCell, rand()%intactCount);
            

        }
        // there were no
        
        
    
        
        
        
        find all neighbors of CurrentCell with all walls intact
        if one or more found
            choose one at random
            knock down the wall between it and CurrentCell
            push CurrentCell location on the CellStack
            make the new cell CurrentCell
            add 1 to VisitedCells
            else
                pop the most recent cell entry off the CellStack  
                make it CurrentCell
                endIf
	}
      
    }
}

void destroyWall(const Maze *maze, Cell *cell, int direction)
{
    PRdirection dir = (PRdirection)direction;
    
    switch (direction) {
        case 0: // north
            maze[][]
            ][]
            break;
            
        default:
            retun NULL;
    }

}

int randomDirection(const Cell *cell, int randomIndex)
{
    int direction = 0;
    for(int direction = 0; direction < 4; direction++)
    {
        if (!cell->border[direction]) {
            
            --randomIndex;
            if(randomIndex == 0)
            {
                return direction;
            }
        }
    }
    printf("should not be reached!\n")
    return direction;

}

int intactNeighboursCount(const Maze *maze, int width, int height)
{
    int count = 0;
    for(int i=0; i<4; i++)
    {
        if(width > 0 && intactWalls(maze[width-1][height])) ++count;
        if(height > 0 && intactWalls(maze[width][height-1])) ++count;
        if(width < MAP_SIZE-1 && intactWalls(maze[width+1][height])) ++count;
        if(height < MAP_SIZE-1 && intactWalls(maze[width][height+1])) ++count;
    }
    return count;
}

bool intactWalls(Cell *cell)
{
    bool isIntact = true;
    for(int i=0; i<4; i++)
    {
        if(!cell->wall[i])
        {
            retun false;
        }
    }
    return true;
}

void updatePosition(position *pos, char c)
{
  switch(c){

  case 'a':
    pos->yposition = (pos->yposition > 0);
    break;
  case 'd':
    pos->yposition++;
    break;
  case 'w':
    pos->xposition--;
    break;
  case 's':
    pos->xposition++;
    break;
  default:
    break;
}

}

void generateMap(position *pos)
{
int i,j;
 printf("\n");
  for (i=0;i<MAP_SIZE;i++)
    {
      for(j=0;j<MAP_SIZE;j++)
	{
	  if(pos->xposition == i && pos->yposition == j)
	    printf("O");
	  else
	    printf("X");
	}
      printf("\n");
    }
}

int main()
{
  struct position currentPosition;

  currentPosition.xposition = 0;
  currentPosition.yposition = 0;

  char c;

  while(1)
    {
      generateMap(&currentPosition);
      c = getchar();
      updatePosition(&currentPosition,c);
}
  return 0;
}
