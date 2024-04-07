#include <stdio.h>

/**
 * @brief Swap two numbers using bitwise XOR
 *
 * @param num1
 * @param num2
 *
 * Note: O operador XOR é um operador binario que compara bit a bit de dois numeros.
 * Seu uso pode ir além de apenas comparar dois numeros, ele pode ser usado para inverter
 * os valores de dois numeros sem a necessidade de uma variavel auxiliar. Também é pode
 * fazer a mesma coisa com blocos de memoria.
 */
void swapNumbers(int *num1, int *num2);

int main()
{
  int num1 = 1, num2 = 3;

  printf("Enter the first number: ");
  scanf("%d", &num1);

  printf("Enter the second number: ");
  scanf("%d", &num2);

  printf("Num1: %d and Num2: %d\n", num1, num2);

  swapNumbers(&num1, &num2);

  printf("Num1: %d and Num2: %d\n", num1, num2);

  return 0;
}

void swapNumbers(int *num1, int *num2)
{
  *num1 = *num1 ^ *num2;
  *num2 = *num1 ^ *num2;
  *num1 = *num1 ^ *num2;
}