#include <stdlib.h>
#include <stdio.h>
#include "tidy.h"

int main(int argc, char **argv) {
  int numberOfCases;
  scanf("%d", &numberOfCases);
  char **cases = (char **) malloc(sizeof(char *) * numberOfCases);
  for (int i = 0; i < numberOfCases; i++) {
    cases[i] = (char *) malloc(sizeof(char) * 18);
    scanf("%s", cases[i]);
  }

  for (int i = 0; i < numberOfCases; i++) {
    printf("Case #%d: %s\n", i + 1, lastTidyNumber(cases[i]));
  }

  return 0;
}
