#include <stdio.h>
#include <string.h>
#include "minunit.h"
#include "partitions.h"

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
#define RESET "\033[0m"

int testsRun = 0;

static char * testFirstCase() {
  int n = 5;
  int a[5] = {1, 4, 2, 3, 5};
  char *result = partition(a, n);
  muAssert("error, [1, 4, 2, 3, 5] partitions to 10100", !strcmp(result, "10100"));
  return 0;
}

static char * testSecondCase() {
  int n = 4;
  int a[4] = {1, 1, 1, 1};
  char *result = partition(a, n);
  muAssert("error, [1, 1, 1, 1] partitions to 1101", !strcmp(result, "1101"));
  return 0;
}

static char * testThirdCase() {
  int n = 4;
  int a[4] = {1, 1, 2, 2};
  char *result = partition(a, n);
  muAssert("error, [1, 1, 2, 2] partitions to 1010", !strcmp(result, "1010"));
  return 0;
}

static char * allTests() {
  muRunTest(testFirstCase);
  muRunTest(testSecondCase);
  muRunTest(testThirdCase);
  return 0;
}

int main(int argc, char **argv) {
  char *result = allTests();
  if (result != 0) {
    printf("-_-_-_-_-_-_-_,------,      o \n");
    printf("_-_-_-_-_-_-_-|   /\\_/\\ \n");
    printf("-_-_-_-_-_-_-~|__( X .X)  +     + \n");
    printf("_-_-_-_-_-_-_- \"\"  \"\" \n");
    printf(KRED "✗ %s \n" RESET, result);
  }
  else {
    printf("-_-_-_-_-_-_-_,------,      o \n");
    printf("_-_-_-_-_-_-_-|   /\\_/\\ \n");
    printf("-_-_-_-_-_-_-~|__( ^ .^)  +     + \n");
    printf("_-_-_-_-_-_-_-  \"\"  \"\" \n");
    printf(KGRN " ✓ ALL TESTS PASSED \n" RESET);
  }
  printf("Tests run: %d\n", testsRun);
  return result != 0;
}
