#include <stdlib.h>
#include <stdio.h>
#include "partitions.h"

typedef struct T {
  int n;
  int *a;
} TestCase;

int main(int argc, char **argv) {
  int t;
  scanf("%d", &t);

  TestCase *testCases = (TestCase *) malloc(sizeof(TestCase) * t);
  for (int i = 0; i < t; i++) {
    scanf("%d", &testCases[i].n);
    testCases[i].a = (int *) malloc(sizeof(int) * testCases[i].n);
    for (int j = 0; j < testCases[i].n; j++) {
      scanf("%d", &testCases[i].a[j]);
    }
  }

  for (int i = 0; i < t; i++) {
    printf("%s\n", partition(testCases[i].a, testCases[i].n));
  }
}
