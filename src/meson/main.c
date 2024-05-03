#include <stdio.h>
#include "linked_list/linked_list.h"

void printString(void *data)
{
  printf("%s\n", (char *)data);
}

int main()
{
  LLNode *head = createNodeLL("Hello World");

  printListLL(head, printString);

  return 0;
}
