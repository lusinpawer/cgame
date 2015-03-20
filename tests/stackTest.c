#include "mazeGameStack.h"

int main(int argc, char **argv)
{
  Cell *c;
  CellNode *cn;
  createStack(&cn);
  pushCell(&cn,c);
  pushCell(&cn,c);
  pushCell(&cn,c);
    popCell(&cn,&c);
    popCell(&cn,&c);

  deleteStack(&cn);
  return 0;
}  
