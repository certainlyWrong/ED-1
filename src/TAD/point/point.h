/**
 * @file point.h
 * @author Adriano R. de Sousa (adrianorodriguesdsousa@gmail.com)
 * @brief This file contains the definition of the Point TAD.
 * @version 0.1
 * @date 2024-05-03
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef POINT_H
#define POINT_H

typedef struct point Point;

/**
 * @brief Create a Point object
 *
 * @param x
 * @param y
 * @return Point*
 */
Point *createPoint(float x, float y);

/**
 * @brief Free a Point object
 *
 * @param point
 */
void freePoint(Point **point);

/**
 * @brief Print a Point object
 *
 * @param point
 */
void printPoint(Point *point);

/**
 * @brief Get the X object
 *
 * @param point
 * @return float
 */
float getX(Point *point);

/**
 * @brief Get the Y object
 *
 * @param point
 * @return float
 */
float getY(Point *point);

/**
 * @brief Set the X object
 *
 * @param point
 * @param x
 */
void setX(Point *point, float x);

/**
 * @brief Set the Y object
 *
 * @param point
 * @param y
 */
void setY(Point *point, float y);

#endif /* POINT_H */