#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief Check if a point is inside a circle
 *
 * @param x
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
int circlePointMembershipChecker(int x, int y, int r, int x0, int y0);

int main(int argc, char const *argv[])
{
  int **matriz;
  int n = 51, m = 51, r = 10;
  int x0 = n / 2, y0 = m / 2;

  if (n < r * 2 || m < r * 2)
  {
    printf("The circle does not fit in the matrix\n");
    return 1;
  }

  matriz = (int **)malloc(n * sizeof(int *));

  for (size_t i = 0; i < m; i++)
  {
    matriz[i] = (int *)malloc(m * sizeof(int));
  }

  for (size_t i = 0; i < n; i++)
  {
    for (size_t j = 0; j < m; j++)
    {
      matriz[i][j] = circlePointMembershipChecker(i, j, r, x0, y0);
    }
  }

  for (size_t i = 0; i < n; i++)
  {
    for (size_t j = 0; j < m; j++)
    {
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }

  return 0;
}

int circlePointMembershipChecker(int x, int y, int r, int x0, int y0)
{
  return sqrt(pow(x - x0, 2) + pow(y - y0, 2)) <= r;
}
