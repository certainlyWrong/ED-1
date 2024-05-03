#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

LLNode *createNodeLL(void *data)
{
  LLNode *node = (LLNode *)malloc(sizeof(LLNode));
  node->data = data;
  node->next = NULL;
  return node;
}

Bool insertNodeLL(LLNode **head, void *data)
{
  Bool result = FALSE;
  LLNode *current = *head;
  LLNode *previous = NULL;

  while (current != NULL)
  {
    previous = current;
    current = current->next;
  }

  if (previous == NULL)
  {
    *head = createNodeLL(data);
  }
  else
  {
    previous->next = createNodeLL(data);
  }

  result = TRUE;

  return result;
}

// implemente evitando o uso de breack
Bool deleteNodeLL(
    LLNode **head,
    void *data,
    ValuesCompare (*compare)(void *, void *),
    void (*freeData)(void **))
{
  Bool result = FALSE;
  LLNode *current = *head;
  LLNode *previous = NULL;

  while (current != NULL && compare(current->data, data) != EQUAL)
  {
    previous = current;
    current = current->next;
  }

  if (current != NULL)
  {
    if (previous == NULL)
    {
      *head = current->next;
    }
    else
    {
      previous->next = current->next;
    }

    freeData(&current->data);
    free(current);
    result = TRUE;
  }

  return result;
}

LLNode *searchNodeLL(LLNode *head, void *data, ValuesCompare (*compare)(void *dataNode, void *data))
{
  LLNode *result = NULL;
  LLNode *current = head;

  while (current != NULL && compare(current->data, data) != EQUAL)
    current = current->next;

  if (current != NULL)
    result = current;

  return result;
}

void freeAllNodesLL(LLNode **head, void (*freeData)(void **))
{
  LLNode *current = *head;
  LLNode *next = NULL;

  while (current != NULL)
  {
    next = current->next;
    freeData(&current->data);
    free(current);
    current = next;
  }

  *head = NULL;
}

void printListLL(LLNode *head, void (*print)(void *))
{
  LLNode *current = head;

  while (current != NULL)
  {
    print(current->data);
    current = current->next;
  }
}