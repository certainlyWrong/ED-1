
/**
 * @file common.h
 * @author Adriano Rodrigues de Sousa
 * @brief Common data structures
 * @version 0.1
 * @date 2023-01-06
 *
 * @copyright Copyright (c) 2023
 */

#ifndef COMMON_H
#define COMMON_H

/**
 * @brief Order of the tree
 *
 * @param PRE_ORDER Pre-order
 * @param IN_ORDER In-order
 * @param POST_ORDER Post-order
 */
typedef enum Order
{
  PRE_ORDER,
  IN_ORDER,
  POST_ORDER
} Order;

/**
 * @brief Boolean type
 *
 * @param FALSE False
 * @param TRUE True
 */
typedef enum Bool
{
  FALSE,
  TRUE
} Bool;

/**
 * @brief Branch of the tree
 *
 * @param SMALLER Left branch
 * @param BIGGER Right branch
 * @param EQUAL Equal branch
 * @param PASS Pass branch
 */
typedef enum ValuesCompare
{
  SMALLER,
  BIGGER,
  EQUAL,
  PASS
} ValuesCompare;

#endif /* COMMON_H */