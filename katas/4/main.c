#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "numericstr.h"

#define MAX_SIZE 100


int main(int argc, char **argv) {
  char str[MAX_SIZE];
  printf("Insert a string to verify: ");
  fgets(str, MAX_SIZE, stdin);
  str[strlen(str) - 1] = 0;
  if (isNumeric(str))
  {
    printf("%s is numeric.\n", str);
  }
  else
  {
    printf("%s is not numeric.\n", str);
  }
  return 0;
}
