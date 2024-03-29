#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "string_manipulation.h"

enum bool { FALSE, TRUE };

int inarray(char *word, char *array[], int array_length)
{
  int i;
  for (i = 0; i < array_length; i++)
  {
    if (strcmp(word, array[i]) == 0)
      return TRUE;
  }

  return FALSE;
}

int instring(char c, char *word, int word_length)
{
  while (*word != '\0' && word_length--)
  {
    if (c == *word++)
      return TRUE;
  }

  return FALSE;
}

int *stoi(char s[])
{
  int i = 0, sign;
  int *result = (int *) calloc(1, sizeof(int));

  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    i++;
  for (i = 0; i < strlen(s); i++)
  {
    if (s[i] < 48 || s[i] > 57)
      return NULL;
    *result = 10 * *result + (s[i] - '0');
  }
  *result *= sign;

  return result;
}
