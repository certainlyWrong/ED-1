#include "point.h"
#include <stdio.h>

struct point
{
  float x;
  float y;
};

Point *createPoint(float x, float y)
{
  Point *point = (Point *)malloc(sizeof(Point));
  point->x = x;
  point->y = y;
  return point;
}

void freePoint(Point **point)
{
  free(*point);
  *point = NULL;
}

void printPoint(Point *point)
{
  printf("Point (%.2f, %.2f)\n", point->x, point->y);
}

float getX(Point *point)
{
  return point->x;
}

float getY(Point *point)
{
  return point->y;
}

void setX(Point *point, float x)
{
  point->x = x;
}

void setY(Point *point, float y)
{
  point->y = y;
}
