/**
 * @file linked_list.h
 * @author Adriano Rodrigues de Sousa
 * @brief
 * @version 0.1
 * @date 2023-01-10
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "common.h"

typedef struct LLNode
{
  struct LLNode *next;
  void *data;

} LLNode;

LLNode *createNodeLL(void *data);

Bool insertNodeLL(LLNode **head, void *data);

Bool deleteNodeLL(
    LLNode **head,
    void *data,
    ValuesCompare (*compare)(void *, void *),
    void (*freeData)(void **));

LLNode *searchNodeLL(LLNode *head, void *data, ValuesCompare (*compare)(void *dataNode, void *data));

void freeAllNodesLL(LLNode **head, void (*freeData)(void **));

void printListLL(LLNode *head, void (*print)(void *));

#endif /* LINKED_LIST_H */
