#include "mazeGameStack.h"


bool pushCell(CellNode **head, Cell *cell)
{

  CellNode *newNode = malloc(sizeof(CellNode));
  if(!newNode)
    {
      return false;
    }
    printf("Pushing node\n");
    newNode->next = *head;
    newNode->cell = cell;
    *head = newNode;
    return true;
}

bool popCell(CellNode **head, Cell **cell)
{
  printf("Popping element \n");
  CellNode *tempCell;
  if (!(tempCell=*head)) return false;
  *cell = tempCell->cell;
  *head = tempCell->next;
  free(head);
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
      printf("popping\n");
      next = (*head)->next;
      free(*head);
      *head = next;
    }
  printf("Stack empty\n");
  return true;
}
