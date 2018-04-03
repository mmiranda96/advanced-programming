#include <stdlib.h>
#include <stdio.h>
#include "reversewords.h"

int main(int argc, char **argv) {
  int n;
  scanf("%d%*c", &n);

  char **cases = (char **) malloc(sizeof(char *) * n);
  for (int i = 0; i < n; i++) {
    cases[i] = (char *) malloc(sizeof(char) * 1000);
    scanf("%[^\n]%*c", cases[i]);
  }

  for (int i = 0; i < n; i++) {
    printf("%s\n", reverseWords(cases[i]));
  }
  
  return 0;
}
