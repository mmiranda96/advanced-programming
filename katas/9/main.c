#include <stdlib.h>
#include <stdio.h>
#include "movies.h"

int main(int argc, char **argv) {
  int flightLength;
  scanf("%d", &flightLength);
  
  int movieCount;
  scanf("%d", &movieCount);

  int *movieLengths = (int *) malloc(sizeof(int) * movieCount);
  for (int i = 0; i < movieCount; i++) {
    scanf("%d", &movieLengths[i]);
  }

  if (checkMovies(flightLength, movieLengths, movieCount)) {
    printf("TRUE\n");
  }
  else {
    printf("FALSE\n");
  }
  
  return 0;
}
