

#ifndef POINT_H
#define POINT_H

typedef struct point Point;

Point *createPoint(float x, float y);

void freePoint(Point **point);

void printPoint(Point *point);

float getX(Point *point);

float getY(Point *point);

void setX(Point *point, float x);

void setY(Point *point, float y);

#endif /* POINT_H */