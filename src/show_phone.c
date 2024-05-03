#include <stdio.h>

typedef struct phone
{
  char cod[3];
  char area[3];
  char num[5];
} Phone;

/**
 * @brief This function shows the phone number in the format (cod) area-number
 *
 * @param p the pointer to the phone number
 * @param type the type of the phone number, it can be a string or a phone struct
 */
void showNumber(void *p, char *type);

int main()
{
  char phoneChar[11] = "0413301515";

  Phone p1 = {
      .cod = "041",
      .area = "330",
      .num = "1515",
  };

  // showNumber(phoneChar, "char");

  showNumber(&p1, "phone");

  return 0;
}

/**
 * @brief This function shows the phone number in the format (cod) area-number from a pointer to char
 *
 * @param p
 */
void showNumberChar(char *p)
{
  printf(
      "(%c%c%c) %c%c%c-%c%c%c%c\n",
      p[0], p[1], p[2],
      p[3], p[4], p[5],
      p[6], p[7], p[8],
      p[9]);
}

/**
 * @brief This function shows the phone number in the format (cod) area-number from a pointer to phone struct
 *
 * @param p
 */
void showNumber(void *p, char *type)
{
  if (type == "char")
    showNumberChar(p);
  else if (type == "phone")
  {
    showNumberChar((char *)p);
  }
  else
    printf("Invalid type\n");
}
