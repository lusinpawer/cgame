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
	  // setting borders on edges
	  if(j == 0)
	    {
	      maze[i][j]->border[0]=true;
	    }
	  if(j == MAP_SIZE-1)
	    {
	      maze[i][j]->border[2]=true;
	    }
	  if(i == 0)
	    {
	      maze[i][j]->border[3]=true;
	    }
	  if(i== MAP_SIZE)
	    {
	      maze[i][j]->border[1]=true;
	    }
	  //set all walls up
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
	}
      
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
