#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <math.h>

/**
 * @brief Check if a point is inside a circle
 *
 * @param x is a integer that represents the x-axis of the point
 * @param y
 * @param r
 * @param x0
 * @param y0
 * @return int
 *
 * Note: A função verifica se um ponto (x, y) está dentro de um circulo de raio r e centro (x0, y0).
 * A função usa o calculo da distancia entre dois pontos, que é dado pela formula: sqrt((x1 - x2)^2 + (y1 - y2)^2)
 * e compara com o raio do circulo. Se a distancia for menor ou igual ao raio, o ponto está dentro do circulo.
 */
int circlePointMembershipChecker(int x, int y, int z, int r, int x0, int y0, int z0);

int main(int argc, char const *argv[])
{
  int ***matriz;
  int x_axis = 21, y_axis = 21, z_axis = 21, r = 10;
  int x0 = x_axis / 2, y0 = y_axis / 2, z0 = z_axis / 2;

  if (x_axis < (r * 2) || y_axis < (r * 2) || z_axis < (r * 2))
  {
    printf("The circle does not fit in the matrix\n");
    return 1;
  }

  matriz = (int ***)malloc(z_axis * sizeof(int **));

  for (size_t i = 0; i < y_axis; i++)
  {
    matriz[i] = (int **)malloc(y_axis * sizeof(int *));
  }

  for (size_t i = 0; i < z_axis; i++)
  {
    for (size_t j = 0; j < y_axis; j++)
    {
      matriz[i][j] = (int *)malloc(x_axis * sizeof(int));
    }
  }

  for (size_t z1 = 0; z1 < z_axis; z1++)
  {
    for (size_t y1 = 0; y1 < y_axis; y1++)
    {
      for (size_t x1 = 0; x1 < x_axis; x1++)
      {
        matriz[z1][y1][x1] = circlePointMembershipChecker(x1, y1, z1, r, x0, y0, z0);
      }
    }
  }

  while (true)
  {
    for (size_t i = 0; i < z_axis; i++)
    {
      for (size_t j = 0; j < y_axis; j++)
      {
        for (size_t k = 0; k < x_axis; k++)
        {
          printf("%d ", matriz[i][j][k]);
        }
        printf("\n");
      }
      usleep(300000);
      printf("\033[2J\033[H");
      printf("\n");
    }
  }

  return 0;
}

int circlePointMembershipChecker(int x, int y, int z, int r, int x0, int y0, int z0)
{
  return sqrt(pow(x - x0, 2) + pow(y - y0, 2) + pow(z - z0, 2)) <= r;
}
