#include <stdio.h>

#define MAP_SIZE 20

typedef struct position{

  int xposition;
  int yposition;
} position;

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
