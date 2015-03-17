#ifndef cgame_mazegamestack_h
#define cgame_mazegamestack_h

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include "MazeGameStructs.h"

typedef struct CellNode
{
  struct CellNode *next;
  Cell *cell;
}CellNode;

bool pushCell(CellNode **head, Cell *cell);
bool popCell(CellNode **head, Cell **cell);
bool createStack(CellNode **head);
bool deleteStack(CellNode **head);

#endif