#include "point/point.h"

int main()
{
  Point *p1 = createPoint(1, 2);

  printPoint(p1);

  setX(p1, 3);

  printPoint(p1);

  freePoint(&p1);

  return 0;
}
