#include "maze.h"



// destroy wall between current cell and next cell
void destroyWall(int direction,Cell *currentCell, Cell *nextCell)
{
    currentCell->wall[direction] = false;
    nextCell->wall[(direction+2)%4] = false;
}

Cell* selectNextCell(int direction,Maze *maze, int i, int j)
{
    switch(direction) {
        case 0: // north
            
            return &maze[i][j+1];
            
        case 1: // east
            
            return &maze[i+1][j];
        case 2: // south
            
            return &maze[i][j-1];
        case 3: // west
            
            return &maze[i-1][j];
            
        default:
            return NULL;
    }
    return NULL;
}




int selectRandomDirection(const Cell *cell, int randomIndex)
{
    int direction = 0;
    for(int direction = 0; direction < 4; direction++)
    {
        if (!cell->border[direction]) {
            
            printf("random index count: %d\n", randomIndex);
            if(randomIndex == 0)
            {
                return direction;
            }
            --randomIndex;

        }
    }
    printf("should not be reached!\n");
    return direction;
    
}

bool intactWalls(const Cell cell)
{
    for(int i=0; i<4; i++)
    {
        if(!cell.wall[i])
        {
            return false;
        }
    }
    return true;
}

int intactNeighboursCount(const Maze *maze, int width, int height)
{
    int count = 0;
        if(width > 0 && intactWalls(maze[width-1][height]))
        {
            printf("east wall intact\n");
            count++;
        }
        if(height > 0 && intactWalls(maze[width][height-1]))
        {
            printf("north wall intact\n");
            count++;
        }
        if(width < MAP_SIZE-1 && intactWalls(maze[width+1][height]))
        {
            printf("west wall intact\n");
            count++;
        }
        if(height < MAP_SIZE-1 && intactWalls(maze[width][height+1]))
        {
            printf("south wall intact\n");
            count++;
        }
    return count;
}



bool generatePath(Maze *maze)
{
    CellNode *head;
    createStack(&head);
    int totalCells = MAP_SIZE*MAP_SIZE;
    int i = rand()%MAP_SIZE;
    int j = rand()%MAP_SIZE;
    Cell *currentCell = &maze[i][j];
    Cell *nextCell;
    int visitedCells = 1;
    printf("start loop\n");
    while (visitedCells < totalCells)
    {
        printf("visited cells count: %d Current cell: %d %d \n", visitedCells,i,j);
        int intactCount = intactNeighboursCount(maze, i, j);
        if(intactCount > 0)
        {
            // select random cell
            printf("intact count: %d random direction chosen: %d \n",intactCount, rand()%intactCount);
            int randomDirection = selectRandomDirection(currentCell, rand()%intactCount);
            nextCell = selectNextCell(randomDirection, maze,i,j);
            destroyWall(randomDirection, currentCell, nextCell);
            pushCell(&head, currentCell);
            currentCell = nextCell;
            visitedCells++;
        }
        else
        {
            popCell(&head, &currentCell);
        }
        i = currentCell->position.x;
        j = currentCell->position.y;
    }
    return true;
}


