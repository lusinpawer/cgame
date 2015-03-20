#include "mazeGameStack.h"


bool pushCell(CellNode **head, Cell *cell)
{

  CellNode *newNode = malloc(sizeof(CellNode));
  if(!newNode)
    {
      return false;
    }
    debug("Pushing node\n");
    newNode->next = *head;
    newNode->cell = cell;
    *head = newNode;
    debug("Finished pushing\n");
    return true;
}

bool popCell(CellNode **head, Cell **cell)
{
  debug("Popping element \n");
  CellNode *tempCell;
  if (!(tempCell=*head))
  {
      debug("pop error, returning\n");
      return false;
  }
    
  *cell = tempCell->cell;
  *head = tempCell->next;
  free(tempCell);
  return true;
}

bool createStack(CellNode **head)
{
  *head = NULL;
  return true;
}

bool deleteStack(CellNode **head)
{
  CellNode *next;
  while(*head)
    {
      debug("popping\n");
      next = (*head)->next;
      free(*head);
      *head = next;
    }
  debug("Stack empty\n");
  return true;
}
