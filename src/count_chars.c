#include <stdio.h>

int main(int argc, char const *argv[])
{
  if (argc < 2)
  {
    printf("Usage: %s <string>\n", argv[0]);
    return 1;
  }

  int count = 0;
  while (argv[1][count] != '\0')
    count++;

  printf("Number of characters: %d\n", count);
  return 0;
}
