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
            
            return &maze[i][j-1];
            
        case 1: // east
            
            return &maze[i+1][j];
        case 2: // south
            
            return &maze[i][j+1];
        case 3: // west
            
            return &maze[i-1][j];
            
        default:
            return NULL;
    }
    return NULL;
}




int selectRandomDirection(const Cell *cell, int randomIndex, bool *intactNeighbours)
{
    for(int direction = 0; direction < 4; direction++)
    {
        debug("Direction: %d wall exists: %d border exists: %d\n", direction, cell->wall[direction],cell->border[direction]);
        if (!cell->border[direction] && intactNeighbours[direction]) {
            
            debug("random index count: %d\n", randomIndex);
            if(randomIndex == 0)
            {
                return direction;
            }
            --randomIndex;

        }
    }
    debug("should not be reached: direction: %d \n", direction);
    return 3;
    
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

int intactNeighboursCount(const Maze *maze, int width, int height, bool *intactNeighbours)
{
    int count = 0;
        if(width > 0 && intactWalls(maze[width-1][height]))
        {
            debug("west neighbour intact\n");
            intactNeighbours[3] = true;
            count++;
        }
        if(height > 0 && intactWalls(maze[width][height-1]))
        {
            debug("north neighbour intact\n");
            intactNeighbours[0] = true;
            count++;
        }
        if(width < MAP_SIZE-1 && intactWalls(maze[width+1][height]))
        {
            debug("east neighbour intact\n");
            intactNeighbours[1] = true;
            count++;
        }
        if(height < MAP_SIZE-1 && intactWalls(maze[width][height+1]))
        {
            debug("south neighbour intact\n");
            intactNeighbours[2] = true;
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
    debug("start loop\n");
    bool intactNeighbours[4] = {false, false, false, false};
    while (visitedCells < totalCells)
    {
        debug("visited cells count: %d Current cell: %d %d \n", visitedCells,i,j);
        int intactCount = intactNeighboursCount(maze, i, j, intactNeighbours);
        if(intactCount > 0)
        {
            // select random cell
            debug("intact count: %d \n",intactCount);
            int randomDirection = selectRandomDirection(currentCell, rand()%intactCount,intactNeighbours);
            debug("random direction chosen: %d \n",randomDirection);
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
        memset(intactNeighbours,false,sizeof(bool)*4);
    }
    return true;
}

bool generateMaze(Maze *maze)
{
    debug("start generating maze\n");
    memset(maze,false,sizeof(Maze));
    
    for(int i=0;i<MAP_SIZE;i++)
    {
        for(int j=0;j<MAP_SIZE;j++)
        {
            //set all walls up
            maze[i][j].position.x = i;
            maze[i][j].position.y = j;
            memset(maze[i][j].wall,true,sizeof(bool)*4);
            memset(maze[i][j].border,false,sizeof(bool)*4);
            
            if(i == 0) maze[i][j].border[3] = true;
            if(i == MAP_SIZE-1) maze[i][j].border[1] = true;
            if(j == 0) maze[i][j].border[0] = true;
            if(j == MAP_SIZE-1) maze[i][j].border[2] = true;
        }
    }
    debug("start generating path\n");
    generatePath(maze);
    
    
    return true;
}


